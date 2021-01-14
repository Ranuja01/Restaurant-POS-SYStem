#include "Payment.h"

// Default constructor

Payment::Payment(){
	tipOption = false;
	totalCosts = 0;
	tax = 0;
	tip = 0;
	subTotal = 0;
}

// Accessor/Mutator Methods

void Payment::setTipOption(bool to){
	tipOption = to;
}

void Payment::setTotalCosts(double tc){
	totalCosts = tc;
}

void Payment::setTax(double t){
	tax = t;
}

void Payment::setTip(double t){
	tip = t;
}

void Payment::setSubTotal(double st){
	subTotal = st;
}

bool Payment::getTipOption()const{
	return tipOption;
}

double Payment::getTotalCosts()const{
	return totalCosts;
}

double Payment::getTax()const{
	return tax;
}


double Payment::getTip()const{
	return tip;
}

double Payment::getSubTotal()const{
	return subTotal;
}

double Payment::pay(double d){
	std::cout << "Choose Payment Method: \n";
	return 0;
}

int Payment::inputValidation(int input) {

	bool loop = true;
	std::cin >> input;
	while (loop){

		// Checks if any non integer numbers are entered when an integer is required
		
		if (std::cin.fail()){

			// Clears the input stream and asks for input until an integer is entered

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid Entry!\n";
			std::cin >> input;
		}

		if (!std::cin.fail()) {
			loop = false;
		}

	}

	return input;

}

double Payment::inputValidation(double input) {

	bool loop = true;
	std::cin >> input;
	while (loop){

		// Checks if any non double numbers are entered when an double is required

		if (std::cin.fail()){

			// Clears the input stream and asks for input until an double value is entered

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid Entry!\n";
			std::cin >> input;
		}
		if (!std::cin.fail()) {
			loop = false;
		}

	}

	return input;

}