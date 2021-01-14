#include "Manager.h"

// Non default Constructor

Manager::Manager(std::string name, std::string password, double salary) : Employee(name,password) {
	this->salary = salary;
}

// A virtual method that defines how a chef is payed

double Manager::pay() {
	return salary;
}


