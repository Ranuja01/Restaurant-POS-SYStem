#include "Cash.h"

#include "Cash.h"

// Default constructor

Cash::Cash(){
	fiveDollarbillQuantity = 0;
	tenDollarBillQuantity = 0;
	twentyDollarBillQuantity = 0;
	fiftyDollarBillQuantity = 0;
	hundredDollarBillQuantity = 0;
	nickelQuantity = 0;
	dimeQuantity = 0;
	quarterQuantity = 0;
	loonieQuantity = 0;
	toonieQuantity = 0;

}

// Accessor/Mutator Methods

void Cash::setFiveDollarbillQuantity(int fdb){
	fiveDollarbillQuantity = fdb;
}

void Cash::setTenDollarBillQuantity(int tdb){
	tenDollarBillQuantity = tdb;
}

void Cash::setTwentyDollarBillQuantity(int tdb){
	twentyDollarBillQuantity = tdb;
}

void Cash::setFiftyDollarBillQuantity(int fdb){
	fiftyDollarBillQuantity = fdb;
}

void Cash::setHundredDollarBillQuantity(int hdb){
	hundredDollarBillQuantity = hdb;
}

void Cash::setNickelQuantity(double n){
	nickelQuantity = n;
}

void Cash::setDimeQuantity(double d){
	dimeQuantity = d;
}

void Cash::setQuarterQuantity(double q){
	quarterQuantity = q;
}

void Cash::setLoonieQuantity(double l){
	loonieQuantity = l;
}

void Cash::setToonieQuantity(double t){
	toonieQuantity = t;
}

int Cash::getFiveDollarbillQuantity()const{
	return fiveDollarbillQuantity;
}

int Cash::getTenDollarBillQuantity()const{
	return tenDollarBillQuantity;
}

int Cash::getTwentyDollarBillQuantity()const{
	return twentyDollarBillQuantity;
}

int Cash::getFiftyDollarBillQuantity()const{
	return fiftyDollarBillQuantity;
}

int Cash::getHundredDollarBillQuantity()const{
	return hundredDollarBillQuantity;
}

double Cash::getNickelQuantity()const{
	return nickelQuantity;
}

double Cash::getDimeQuantity()const{
	return dimeQuantity;
}

double Cash::getQuarterQuantity()const{
	return quarterQuantity;
}

double Cash::getLoonieQuantity()const{
	return loonieQuantity;
}

double Cash::getToonieQuantity()const{
	return toonieQuantity;
}

// Gets the specific amounts of money given and calculates the received value

double Cash::pay(double cost){

	int input = 0;


	std::cout << "Input number of five dollar bills: ";
	fiveDollarbillQuantity = inputValidation(fiveDollarbillQuantity);
	setFiveDollarbillQuantity(fiveDollarbillQuantity);

	std::cout << "Input number of ten dollar bills: ";
	tenDollarBillQuantity = inputValidation(tenDollarBillQuantity);
	setTenDollarBillQuantity(tenDollarBillQuantity);

	std::cout << "Input number of twenty dollar bills: ";
	twentyDollarBillQuantity = inputValidation(twentyDollarBillQuantity);
	setTwentyDollarBillQuantity(twentyDollarBillQuantity);

	std::cout << "Input number of fifty dollar bills: ";
	fiftyDollarBillQuantity = inputValidation(fiftyDollarBillQuantity);
	setFiftyDollarBillQuantity(fiftyDollarBillQuantity);

	std::cout << "Input number of hundred dollar bills: ";
	hundredDollarBillQuantity = inputValidation(hundredDollarBillQuantity);
	setHundredDollarBillQuantity(hundredDollarBillQuantity);

	std::cout << "Input number of Nickels: ";
	nickelQuantity = inputValidation(nickelQuantity);
	setNickelQuantity(nickelQuantity);

	std::cout << "Input number of dimes: ";
	dimeQuantity = inputValidation(dimeQuantity);
	setDimeQuantity(dimeQuantity);

	std::cout << "Input number of quarters: ";
	quarterQuantity = inputValidation(quarterQuantity);
	setQuarterQuantity(quarterQuantity);

	std::cout << "Input number of loonies: ";
	loonieQuantity = inputValidation(loonieQuantity);
	setLoonieQuantity(loonieQuantity);

	std::cout << "Input number of toonies: ";
	toonieQuantity = inputValidation(toonieQuantity);
	setToonieQuantity(toonieQuantity);
	
	// Gives the tip option

	do{
		std::cout << "Select option for tip: \n";
		std::cout << "Include tip (Press 1)\n";
		std::cout << "Ignore tip (Press 2)\n";
		input = inputValidation(input);
	} while (input < 0 && input < 3);

	if (input == 1){
		Payment::setTipOption(true);
		std::cout << "Input tip: ";
		std::cin >> Payment::tip;
		Payment::setTip(tip);
	}

	if (input == 2){
		Payment::setTipOption(false);
	}


	double totalAmount = getFiveDollarbillQuantity() * 5 + getTenDollarBillQuantity() * 10 + getTwentyDollarBillQuantity() * 20 + getFiftyDollarBillQuantity() * 50
		+ getHundredDollarBillQuantity() * 100 + getNickelQuantity() * 0.05 + getDimeQuantity() * 0.10 + getQuarterQuantity() * 0.25 + getLoonieQuantity() * 1.00 +
		getToonieQuantity() * 2.00 + Payment::getTip();

	Payment::tax = totalAmount * 0.13;

	Payment::setTotalCosts(totalAmount + Payment::tax);

	std::cout << "$" << Payment::getTotalCosts() << "\n";

	return totalCosts;

}

void Cash::fileOutput() {
	
	// Outputs the payment information to the orders file

	std::ofstream orderFile;
	orderFile.open("Orders.txt", std::ios::app);

	if (orderFile) {

		orderFile << "Payment: Cash\n";
		orderFile << "Payed Amount: " << totalCosts << "\n";
	
	} else {
		std::cout << "File not found\n";
	}
	orderFile.close();
}

