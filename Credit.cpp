#include "Credit.h"

// Default constructor

Credit::Credit(){
	credCardType = "";
	credPinNum = 0;
	bank = "";
	name = "";
}

// Accessor/Mutator Methods

void Credit::setCredCardType(std::string cct){
	credCardType = cct;
}

void Credit::setCredPinNum(int cpn){
	credPinNum = cpn;
}

void Credit::setBank(std::string b){
	bank = b;
}

void Credit::setName(std::string n){
	name = n;
}

std::string Credit::getCredCardType()const{
	return credCardType;
}

int Credit::getCredPinNum()const{
	return credPinNum;
}

std::string Credit::getBank()const{
	return bank;
}

std::string Credit::getName()const{
	return name;
}

// Gets the customer's credit card information

double Credit::pay(double cost){
	
	int input = 0;

	std::cout << "Input Credit Card Type (i.e Visa, Mastercard, etc): ";
	std::cin >> credCardType;
	setCredCardType(credCardType);

	std::cout << "Input Name of Card Holder: ";
	std::cin >> name;
	setName(name);

	std::cout << "Input Bank: ";
	std::cin >> bank;
	setBank(bank);

	std::cout << "Input Credit Card Pin: ";
	credPinNum = inputValidation(credPinNum);
	setCredPinNum(credPinNum);

	// Gives the tip option

	do{
		std::cout << "Amount owed: $" << cost << "\n";
		std::cout << "Select option for tip: \n";
		std::cout << "Include tip (Press 1)\n";
		std::cout << "Ignore tip (Press 2)\n";
		input = inputValidation(input);
	} while (!(input > 0 && input < 3));

	if (input == 1){
		Payment::setTipOption(true);
		std::cout << "Input tip: ";
		std::cin >> Payment::tip;
		Payment::setTip(tip);
		cost += Payment::tip;
	}

	if (input == 2){
		Payment::setTipOption(false);
	}
	Payment::setTotalCosts(cost);
	return cost;
}

void Credit::fileOutput() {

	// Outputs the payment information to the orders file

	std::ofstream orderFile;
	orderFile.open("Orders.txt", std::ios::app);

	if (orderFile) {

		orderFile << "Payment: Credit\n";
		orderFile << "Card Holder: " << name << "\n";
		orderFile << "Bank: " << bank << "\n";
		orderFile << "Card Type: " << credCardType << "\n";
		orderFile << "Card Number: " << credPinNum << "\n";
		orderFile << "Payed Amount: " << totalCosts << "\n";

	}
	else {
		std::cout << "File not found\n";
	}
	orderFile.close();
}

/* This is one way you can calculate the finances from the Payment class, since you can't instantiate it directly since it's an abstract class
void Credit::calculateFinances()
{

	string orders[] =  Order::getOrders();

	Payment::setTotalCosts();
	Payment:: setTax();
	Payment:: setTip();
	Payment:: setSubTotal();
}*/
