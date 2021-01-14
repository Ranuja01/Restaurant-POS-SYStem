#ifndef WAITER_H
#define WAITER_H

#include "Employee.h"


class Waiter: public Employee{

private: 
	double hourlyPay;
public:
	Waiter(std::string, std::string, double);
	virtual double pay();


};

#endif 