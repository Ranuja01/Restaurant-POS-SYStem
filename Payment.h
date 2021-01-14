#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include<limits>

class Payment
{
protected:
	bool tipOption;
	double totalCosts;
	double tax;
	double tip;
	double subTotal;
public:
	Payment();

	void setTipOption(bool);
	void setTotalCosts(double);
	void setTax(double);
	void setTip(double);
	void setSubTotal(double);

	bool getTipOption()const;
	double getTotalCosts()const;
	double getTax()const;
	double getTip()const;
	double getSubTotal()const;

	double inputValidation(double input);
	int inputValidation(int input);

	virtual double pay(double) = 0;
	virtual void fileOutput() = 0;
};


#endif // !PAYMENT_H