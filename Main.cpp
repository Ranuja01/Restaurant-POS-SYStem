#include "Burger.h"
#include "Debit.h"
#include "Chef.h"
#include "Pizza.h"
#include "Manager.h"
#include "Waiter.h"
#include "Order.h"
#include "Cheque.h"
#include "Credit.h"
#include "Inventory.h"
#include "Cash.h"

#include <fstream>


using namespace std;

const int numDishes = 2;
const double TAX = 1.13;
static double account = 0;
static int numEmployees = 0;

double inputValidation(double input);
int inputValidation(int input);
void menu(Employee*** employees, int numManagers, int numChefs, int numWaiters, inventoryStruct inventory[15], Inventory in, Dish* dishes[numDishes]);

int main() {

	/*
	double salt [numDishes];
	double sugar [numDishes];
	double blackPepper[numDishes];
	double chilliPowder[numDishes];
	double onions[numDishes];
	double peppers[numDishes];
	double cheese[numDishes];
	double oil[numDishes];
	double chicken[numDishes];
	double fish[numDishes];
	double beef[numDishes];
	double mushrooms[numDishes];
	double carrots[numDishes];
	double flour[numDishes];
	double garlic[numDishes];
*/

	// Defines the types of dishes available

	Dish* dishes[numDishes] = { new Burger(), new Pizza() };

	Employee** employees;

	int numManagers = 0;
	int numChefs = 0;
	int numWaiters = 0;

	string name = "";
	string password = "";
	double salary = 0;
	double price = 0;

	double ingredients [15][numDishes];

	inventoryStruct inventory[15];
	Inventory in;;

	ifstream inv;
	inv.open("Inventory.txt");

	ifstream managerFile;
	managerFile.open("ManagerData.txt");

	ifstream chefFile;
	chefFile.open("ChefData.txt");

	ifstream waiterFile;
	waiterFile.open("WaiterData.txt");

	ifstream inFile;
	inFile.open("Recipes.txt");

	/*
		The main function is used to load all necessary information from files to local arrays
	*/
	
	// Gets data on the specific amount of ingredients required for each dish as well as the price

	if (inFile) {
		
		for (int i = 0; i < numDishes; i++) {
			inFile >> ingredients[0][i] >> ingredients[1][i] >> ingredients[2][i] >> ingredients[3][i] >> ingredients[4][i] >> ingredients[5][i] >> ingredients[6][i] >> ingredients[7][i] >> ingredients[8][i] >> ingredients[9][i] >> ingredients[10][i] >> ingredients[11][i] >> ingredients[12][i] >> ingredients[13][i] >> ingredients[14][i] >> price;
			dishes[i]->setIngredients(ingredients[i]);
			dishes[i]->setPrice(price);
		}

	} else {
		cout << "File not found!" << endl;
	}

	// Gets data on the ingredients available in the inventory

	if (inv) {

		for (int i = 0; i < 15; i++) {
			inv >> inventory[i].ingredient >> inventory[i].purchaseDate >> inventory[i].expiryDate >> inventory[i].unitCost >> inventory[i].quantity;

			in = Inventory(inventory);
			
		}

	} else {
	
		cout << "File not found!" << endl;
	}
	
	// Gets data on the different employees working at the location

	if (managerFile) {
	
		managerFile >> numManagers;
		
		if (chefFile) {

			chefFile >> numChefs;

			if (waiterFile) {

				waiterFile >> numWaiters;
				numEmployees = numManagers + numChefs + numWaiters;

				employees = new Employee*[numEmployees];

				// Goes through different files meant for different employee types and initializes the employee array with them

				for (int i = 0; i < numManagers; i++){
					
					managerFile >> name >> password >> salary;
					Manager *m = new Manager(name,password, salary);
					employees[i] = m;
				}

				for (int i = numManagers; i < numChefs + numManagers; i++) {
					
					chefFile >> name >> password >> salary;
					Chef *c = new Chef(name,password, salary);
					employees[i] = c;
				}
			
				for (int i = numChefs + numManagers; i < numEmployees; i++) {
					
					waiterFile >> name >> password >> salary;
					Waiter *w = new Waiter(name,password, salary);
					employees[i] = w;
				}

			}
			else {

				cout << "File not found!" << endl;
			}

		}
		else {

			cout << "File not found!" << endl;
		}

	}
	else {

		cout << "File not found!" << endl;
	}

	// Gets the data on how much money is in the account

	ifstream accountFile;
	accountFile.open("Account.txt");
	if (accountFile) {

		accountFile >> account;

	}
	else {

		cout << "File not found!" << endl;
	}

	inFile.close();
	inv.close();
	managerFile.close();
	chefFile.close();
	waiterFile.close();
	accountFile.close();

	// The menu function is called to run the system

	menu(&employees,numManagers,numChefs,numWaiters,inventory,in,dishes);

	cout << "Goodnight!" << endl;

	return 0;
}

void menu(Employee ***employees, int numManagers, int numChefs, int numWaiters, inventoryStruct inventory [15], Inventory in,Dish *dishes [numDishes]) {
	
	string key;

	bool open = true;
	bool loop = true;
	bool employeeFound = false;
	bool enoughMoney = true;
	bool cont = true;

	char input = '0';
	int index = 0;

	string purchaseDate = "";
	string expiryDate = "";
	double unitCost = 0;
	double quantity = 0;

	string name = "";
	long pass = 0;
	double salary = 0;

	int count = 0;
	int tableNum = 0;
	int numberOfItems = 0;
	double cost = 0;

	Order receipt = Order();
	Cheque cheque = Cheque();
	Debit debit = Debit();
	Credit credit = Credit();
	Cash cash = Cash();
	Dish* order;



	// This is the master loop where everything occurs inside

	while (loop){

		cout << "Enter your password to login\n";
		cin >> key;

		// Verifies employee password 
		
		for (int i = 0; i < numEmployees && employeeFound == false; i++) {

			if ((*employees)[i]->getPassword() == key) {
				employeeFound = true;
				index = i;
			}
			else if (i == numEmployees - 1 && input != 1) {
				cout << "Incorrect Password! Try again.";
			}

		}

		while (employeeFound) {

			input = '0';
			purchaseDate = "";
			expiryDate = "";
			unitCost = 0;
			quantity = 0;
			name = "";
			pass = 0;
			salary = 0;
			cost = 0;
			cont = true;
			tableNum = 0;
			numberOfItems = 0;
			cost = 0;

			/* This is the main decision structure that differs the type of menu shown to each type of employee */

			// Managers have access to accounts, the ability to order ingredients, hire new employees etc.

			if (index >= 0 && index < numManagers) {

				cout << "Enter an option: " << endl;
				cout << "1. Logout" << endl;
				cout << "2. Check Account " << endl;
				cout << "3. Order more ingredients" << endl;
				cout << "4. Check Inventory" << endl;
				cout << "5. Hire new Employee (Starting tomorrow)" << endl;
				cout << "6. Close for the day" << endl;
						
				cin >> input;

				if (isalpha(input)) {
					cout << "Invalid Entry! Try again" << endl;
				}
				else {

					// Takes input and shows the appropriate screen based on the menu item chosen

					switch (input) {

					case '1':

						// Logs the user out of the system

						employeeFound = false;
						break;
					case '2':

						// Shows the amount of money in the restaurant account

						cout << "Account: $" << account << endl;
						break;
					case '3':

						// Asks the manager to pick the type of ingredient that they want to order and gets specific information on it

						if (account > 0) {
							while (enoughMoney && cont) {

								cout << "Enter the item you wish to purchase: " << endl;
								cout << "1. Go back" << endl;
								cout << "2. Salt" << endl;
								cout << "3. Sugar" << endl;
								cout << "4. Black Pepper" << endl;
								cout << "5. Chilli Powder" << endl;
								cout << "6. Onions" << endl;
								cout << "7. Peppers" << endl;
								cout << "8. Cheese" << endl;
								cout << "9. Oil" << endl;
								cout << "10. Chicken" << endl;
								cout << "11. Fish" << endl;
								cout << "12. Beef" << endl;
								cout << "13. Mushroom" << endl;
								cout << "14. Carrots" << endl;
								cout << "15. Flour" << endl;
								cout << "16. Garlic" << endl;

								cin >> input;

								if (isalpha(input)) {
									cout << "Invalid Entry!" << endl;
								}
								else {
									
									if (input != '1') {

										cout << "Enter the purchase date (dd/mm/yyyy): " << endl;
										cin >> purchaseDate;

										cout << "Enter the expiry date (dd/mm/yyyy): " << endl;
										cin >> expiryDate;

										cout << "Enter the unit cost: " << endl;
										unitCost = inputValidation(unitCost);

										cout << "Enter the quantity required: " << endl;
										quantity = inputValidation(quantity);

										if ((account - (quantity * unitCost) * TAX) < 0) {
											enoughMoney = false;
											cout << "Not enough money for the purchase! " << endl;
										}
										else {

											ofstream inv;
											inv.open("Inventory.txt");

											ofstream accountFile;
											accountFile.open("Account.txt");

											cout << "Purchase successful " << endl;
											inventoryStruct inst;

											inst.ingredient = inventory[((int)input- '0') - 2].ingredient;
											inst.purchaseDate = purchaseDate;
											inst.expiryDate = expiryDate;
											inst.unitCost = unitCost;
											inst.quantity = quantity;

											account -= (quantity * unitCost) * TAX;

											inventory[((int)input - '0') - 2] = inst;
											in = Inventory(inventory);

											// Stores the updated inventory and account in the file as they change

											if (accountFile) {

												accountFile << account;

											}
											else {

												cout << "File not found!" << endl;
											}

											for (int i = 0; i < 15; i++) {

												if (inv) {
													inv << inventory[i].ingredient << inventory[i].purchaseDate << inventory[i].expiryDate << inventory[i].unitCost << inventory[i].quantity;
												}
												else {
													cout << "File not found!" << endl;
												}

											}
											inv.close();
											accountFile.close();

										}
									}
									else {
										cont = false;
									}
								}
							}
						}
						else {

						// If there is no money or the cost of the purchase is too much then it will not be made

							enoughMoney = false;
							cout << "Not enough money to make purchases!" << endl;
						}
						break;

					case '4':

						// Checks if the inventory is running low on any ingredient

						in.checkInventory();
						break;
					case '5':

						// Allows manager to hire new employees starting the next day

						while (cont) {

							cout << "Choose type of employee to be hired";
							cout << "1. Go back";
							cout << "2. Manager";
							cout << "3. Chef";
							cout << "4. Waiter";

							cin >> input;

							if (isalpha(input)) {
								cout << "Invalid Entry!" << endl;
							}
							else {

								if (input != 1) {

									ofstream outFile;

									// Opens specific file based on what type of employee is to be hired

									switch (input) {

									case '2':

										outFile.open("ManagerData.txt", ios::app);
										break;
									case '3':
										outFile.open("ChefData.txt", ios::app);
										break;

									case '4':
										outFile.open("WaiterData.txt", ios::app);
										break;

									default:
										cout << "Invalid Entry! Try again" << endl;
										break;

									}

									cout << "Enter the Employee's name:" << endl;
									cin >> name;

									cout << "Enter the Employee's password:" << endl;
									cin >> pass;

									cout << "Enter the Employee's salary:" << endl;
									salary = inputValidation(salary);

									outFile << name << " " << pass << "  " << salary << "\n";

								}
								else {
									cont = false;
								}
							}

						}

						break;

					case '6':

						// This function is called when the restaurant closes

						cout << "Are you sure you want to close for the day?" << endl;
						cout << "1. Yes" << endl;
						cout << "Any other input for no." << endl;

						cin >> input;

						if (isalpha(input)) {
							cout << "Invalid Entry!" << endl;
						}
						else {

							if (input == '1') {

								employeeFound = false;
								loop = false;

								// The employees are run through in a loop so the system can record their pay accordingly

								for (int i = 0; i < numEmployees; i++) {
									account -= (*employees)[i]->pay();
								}

							}

						}

						break;

					default:

						// Invalid inputs in the switch structure come here

						cout << "Invalid Entry! Try again" << endl;
						break;

					} // end of switch

				}
	
			} else if (index >= numManagers && index < numChefs + numChefs){

				// This part of the main decision structure is the chef menu

				cout << "Enter an option: " << endl;
				cout << "1. Logout" << endl;
				cout << "2. Order more ingredients" << endl;
				cout << "3. Check Inventory" << endl;

				cin >> input;

				if (isalpha(input)) {
					cout << "Invalid Entry!" << endl;
				}
				else {

					switch (input) {

					case '1':

						// Logs the user out

						employeeFound = false;
						break;
					case '2':

						// Same as the manager menu, a chef can order more ingredients

						if (account > 0) {

							while (enoughMoney && cont) {

								cout << "Enter the item you wish to purchase: " << endl;
								cout << "1. Go back" << endl;
								cout << "2. Salt" << endl;
								cout << "3. Sugar" << endl;
								cout << "4. Black Pepper" << endl;
								cout << "5. Chilli Powder" << endl;
								cout << "6. Onions" << endl;
								cout << "7. Peppers" << endl;
								cout << "8. Cheese" << endl;
								cout << "9. Oil" << endl;
								cout << "10. Chicken" << endl;
								cout << "11. Fish" << endl;
								cout << "12. Beef" << endl;
								cout << "13. Mushroom" << endl;
								cout << "14. Carrots" << endl;
								cout << "15. Flour" << endl;
								cout << "16. Garlic" << endl;

								cin >> input;

								if (isalpha(input)) {
									cout << "Invalid Entry!" << endl;
								}
								else {

									if (input != 1) {

										cout << "Enter the purchase date (dd/mm/yyyy): " << endl;
										cin >> purchaseDate;

										cout << "Enter the expiry date (dd/mm/yyyy): " << endl;
										cin >> expiryDate;

										cout << "Enter the unit cost: " << endl;
										unitCost = inputValidation(unitCost);

										cout << "Enter the quantity required: " << endl;
										quantity = inputValidation(quantity);

										if ((account - (quantity * unitCost) * TAX) < 0) {
											enoughMoney = false;
											cout << "Not enough money for the purchase! " << endl;
										}
										else {

											ofstream inv;
											inv.open("Inventory.txt");

											ofstream accountFile;
											accountFile.open("Account.txt");

											cout << "Purchase successful " << endl;
											inventoryStruct ins;

											ins.ingredient = inventory[((int)input - '0') - 2].ingredient;
											ins.purchaseDate = purchaseDate;
											ins.expiryDate = expiryDate;
											ins.unitCost = unitCost;
											ins.quantity = quantity;

											account -= (quantity * unitCost) * TAX;

											inventory[((int)input - '0') - 2] = ins;
											in = Inventory(inventory);

											if (accountFile) {

												accountFile << account;

											}
											else {

												cout << "File not found!" << endl;
											}

											for (int i = 0; i < 15; i++) {

												if (inv) {
													inv << inventory[i].ingredient << inventory[i].purchaseDate << inventory[i].expiryDate << inventory[i].unitCost << inventory[i].quantity;
												}
												else {
													cout << "File not found!" << endl;
												}

											}
											inv.close();
											accountFile.close();

										}
									}
									else {
										cont = false;
									}
								}
							}
						}
						else {
							enoughMoney = false;
							cout << "No money to make purchases!" << endl;
						}
						break;

					case '3':

						// Checks if the inventory is running low on aany ingredient

						in.checkInventory();
						break;

					default:
						cout << "Invalid Entry! Try again" << endl;
						break;
					}
				}

			} else {
				
				cout << "Enter an option: " << endl;
				cout << "1. Logout" << endl;
				cout << "2. Take Order" << endl;
				cout << "3. Check Inventory" << endl;
				
				cin >> input;

				if (isalpha(input)) {
					cout << "Invalid Entry! Try again" << endl;
				}
				else {

					switch (input) {

					case '1':

						// Logs the user out

						employeeFound = false;
						break;
					case '2':
						
						// The waiter can enter orders here
						// Information on the table number as well as the type of dishes is inputted

						cout << "Enter the waiter: " << endl;
						cin >> name;

						cout << "Enter the table number: " << endl;
						tableNum = inputValidation(tableNum);

						cout << "Enter the number of dishes: " << endl;
						numberOfItems = inputValidation(numberOfItems);

							order = new Dish[numberOfItems];

							for (int i = 0; i < numberOfItems; i++) {

								cout << "Enter an option: " << endl;
								cout << "1. Go back" << endl;

								for (int j = 0; j < numDishes; j++) {
									cout << j + 2 << ". ";
									dishes[j]->print();
								}



								cin >> input;
								
								if (input != '1' && isdigit(input)) {

									order[i] = *dishes[((int)input - '0') - 2];
									
									cost += order[i].getCost();
								} else if (isalpha(input)){
									cout << "Invalid entry! Try again" << endl;
									i--;
								}
								
								
							}
	
							receipt = Order(name, tableNum, numberOfItems, order, in);

							// The type of payment and respective details are then entered through the payment derived classes

							if (receipt.createOrder() == true) {

								cost *= TAX;

								cout << "Coming right up! " << endl;

								cout << "Enter payment method:  " << endl;
								cout << "1. Cheque" << endl;
								cout << "2. Debit" << endl;
								cout << "3. Credit" << endl;
								cout << "4. Cash" << endl;

								cin >> input;

								std::ofstream orderFile;
								orderFile.open("Orders.txt", std::ios::app);

								if (orderFile) {

									orderFile << "Waiter: " << name << endl;
									orderFile << "Table Number: " << tableNum << endl;

								}
								else {
									std::cout << "File not found\n";
								}
								orderFile.close();

								switch (input) {
								case '1':
									cheque.pay(cost);
									cheque.fileOutput();
									break;

								case '2':
									debit.pay(cost);
									debit.fileOutput();
									break;

								case '3':
									credit.pay(cost);
									credit.fileOutput();
									break;
								case '4':
									cash.pay(cost);
									cash.fileOutput();
									break;

								}

							} else {
								cout << "Not enough ingredients!" << endl;
							}
						
						break;

					case '3':
						in.checkInventory();
						break;

					default:
						cout << "Invalid Entry! Try again" << endl;
						break;
					}

				}

			}
		}

	}

}


int inputValidation(int input) {

	bool loop = true;
	cin >> input;
	while (loop){

		// Checks if any non integer numbers are entered when an integer is required
		
		if (cin.fail()){

			// Clears the input stream and asks for input until an integer is entered

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Entry!" << endl;
			cin >> input;
		}
		if (!cin.fail()) {
			loop = false;
		}

	}

	return input;

}

double inputValidation(double input) {

	bool loop = true;
	cin >> input;
	while (loop)
	{
		// Checks if any non double numbers are entered when an double is required
		if (cin.fail()) {

			// Clears the input stream and asks for input until an double value is entered

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Entry!" << endl;
			cin >> input;
		}
		if (!cin.fail()) {
			loop = false;
		}

	}

	return input;

}
