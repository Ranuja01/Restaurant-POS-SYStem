#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager: public Employee{

private: 
	double salary;

public: 

	Manager(std::string,std::string, double);
	virtual double pay();
	
};

#endif // !MANAGER_H