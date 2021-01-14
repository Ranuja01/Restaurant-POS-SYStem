#include "Debit.h"

// Default constructor

Debit::Debit(){
	debtCardNum = 0;
	debtPinNum = 0;
	bank = "";
	name = "";
}

// Accessor/Mutator Methods

void Debit::setDebtCardNum(double dcn){
	debtCardNum = dcn;
}

void Debit::setDebtPinNum(int pn){
	debtPinNum = pn;
}

void Debit::setBank(std::string b){
	bank = b;
}

void Debit::setName(std::string n){
	name = n;
}

double Debit::getDebtCardNum()const{
	return debtCardNum;
}

int Debit::getDebtPinNum()const{
	return debtPinNum;
}

std::string Debit::getBank()const{
	return bank;
}

std::string Debit::getName()const{
	return name;
}

// Gets the customer's debit card information

double Debit::pay(double cost){

	double input = 0;

	std::cout << "Input name of card holder: \n";
	std::cin >> name;
	setName(name);

	std::cout << "Input debit card pin: ";
	debtPinNum = inputValidation(debtPinNum);
	setDebtPinNum(debtPinNum);

	std::cout << "Input bank: ";
	std::cin >> bank;
	setBank(bank);

	// Gives the tip option

	do {
		std::cout << "Amount owed: $" << cost << "\n";
		std::cout << "Select option for tip: \n";
		std::cout << "Include tip (Press 1)\n";
		std::cout << "Ignore tip (Press 2)\n";
		input = inputValidation(input);
	} while (!(input > 0 && input < 3));

	if (input == 1) {
		Payment::setTipOption(true);
		std::cout << "Input tip: ";
		std::cin >> Payment::tip;
		Payment::setTip(tip);
		cost += Payment::tip;
	}

	if (input == 2) {
		Payment::setTipOption(false);
	}
	Payment::setTotalCosts(cost);
	return cost;
}

void Debit::fileOutput() {

	// Outputs the payment information to the orders file

	std::ofstream orderFile;
	orderFile.open("Orders.txt", std::ios::app);

	if (orderFile) {

		orderFile << "Payment: Debit\n";
		orderFile << "Card Holder: " << name << "\n";
		orderFile << "Card Number: " << debtPinNum << "\n";
		orderFile << "Payed Amount: " << totalCosts << "\n";

	}
	else {
		std::cout << "File not found\n";
	}
	orderFile.close();
}
