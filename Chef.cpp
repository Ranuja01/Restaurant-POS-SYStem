#include "Chef.h"

// Non default constructor

Chef::Chef(std::string name, std::string password, double salary) : Employee(name,password) {
	this->salary = salary;
}

// A virtual method that defines how a chef is payed

double Chef::pay() {

	// Chefs are allowed bonuses based on their performance
	// Bonuses are granted by managers

	double bonus;

	std::cout << "Enter any bonuses for : " << name << "\n";
	std::cin >> bonus;

	return salary + bonus;
}