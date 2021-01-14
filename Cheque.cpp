#include "Cheque.h"

// Default constructor

Cheque::Cheque():Payment(){
	address = "";
	chequeNumber = 0;
	memo = "";
	name = "";
	transitNumber = 0;
	financialNumber = 0;
	accountNumber = 0;
	deposit = 0;

}

// Accessor/Mutator Methods

void Cheque::setTransitNumber(int tn){
	transitNumber = tn;
}

void Cheque::setFinancialNumber(int fn){
	financialNumber = fn;
}


void Cheque::setDeposit(double d){
	deposit = d;
}

void Cheque::setAddress(std::string a){
	address = a;
}

void Cheque::setChequeNumber(int cn){
	chequeNumber = cn;
}

void Cheque::setAccountNumber(int an){
	accountNumber = an;
}

void Cheque::setMemo(std::string m){
	memo = m;
}

void Cheque::setName(std::string n){
	name = n;
}

std::string Cheque::getAddress()const{
	return address;
}

double Cheque::getDeposit()const{
	return deposit;
}

int Cheque::getChequeNumber()const{
	return chequeNumber;
}

std::string Cheque::getMemo()const{
	return memo;
}

std::string Cheque::getName()const{
	return name;
}

int Cheque::getTransitNumber()const{
	return  transitNumber;
}

int Cheque::getFinancialNumber()const{
	return  financialNumber;
}

int Cheque::getAccountNumber()const{
	return accountNumber;
}

// Gets the customer's cheque information

double Cheque::pay(double cost){

	int input = 0;

	std::cout << "Input name of cheque holder: ";
	std::cin >> name;
	setName(name);

	do {
	std::cout << "Input deposit: ";
	std::cin >> deposit;
	setDeposit(deposit);
	} while (deposit < cost);
	std::cout << "Input memo: ";
	std::cin >> memo;
	setMemo(memo);

	std::cout << "Input transit number: ";
	transitNumber = inputValidation(transitNumber);
	setTransitNumber(transitNumber);

	std::cout << "Input Financial number: ";
	financialNumber = inputValidation(financialNumber);
	setFinancialNumber(financialNumber);


	std::cout << "Input account number: ";
	accountNumber = inputValidation(accountNumber);
	setAccountNumber(accountNumber);

	// Gives the tip option

	do{
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
	}

	if (input == 2){
		Payment::setTipOption(false);
	}

	double totalAmount = deposit + Payment::getTip();

	Payment::setTotalCosts(totalAmount);

	std::cout << "$" << Payment::getTotalCosts() << "\n";
	return totalAmount;
}

void Cheque::fileOutput() {

	// Outputs the payment information to the orders file

	std::ofstream orderFile;
	orderFile.open("Orders.txt", std::ios::app);

	if (orderFile) {

		orderFile << "Payment: Debit\n";
		orderFile << "Cheque Holder: " << name << "\n";
		orderFile << "memo: " << memo << "\n";
		orderFile << "Transit Number: " << transitNumber << "\n";
		orderFile << "Financial Number: " << financialNumber << "\n";
		orderFile << "Account Number: " << accountNumber << "\n";
		orderFile << "Payed Amount: " << totalCosts << "\n";

	}
	else {
		std::cout << "File not found\n";
	}

	orderFile.close();
}