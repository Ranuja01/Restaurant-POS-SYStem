#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee{

protected:

	std::string name;
	std::string password;

public:

	Employee() { password = ""; name = ""; }
	Employee(std::string name, std::string key) { password = key; this->name = name; }
	std::string getPassword()const { return password; }
	virtual double pay() { return 0; }

};

#endif // !EMPLOYEE_H