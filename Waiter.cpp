#include "Waiter.h"

// Non default constructor

Waiter::Waiter(std::string name, std::string password, double hourly) : Employee(name,password) {
	hourlyPay = hourly;
}

// A virtual method that defines how a chef is payed

double Waiter::pay() {

	double hours;

	std::cout << "Enter the hours attended: ";
	std::cin >> hours;

	return hours * hourlyPay;
}