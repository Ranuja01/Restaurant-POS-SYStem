#ifndef CHEF_H
#define CHEF_H

#include "Employee.h"

class Chef : public Employee {

private:
	double salary;

public:

	Chef(std::string, std::string, double);
	virtual double pay();

};

#endif