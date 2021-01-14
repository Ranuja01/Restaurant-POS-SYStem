#ifndef DEBIT_H
#define DEBIT_H

#include "Payment.h"

class Debit : public Payment
{
protected:
	double debtCardNum;
	int debtPinNum;
	std::string bank;
	std::string name;
public:
	Debit();

	void setDebtCardNum(double);
	void setDebtPinNum(int);
	void setBank(std::string);
	void setName(std::string);

	double getDebtCardNum()const;
	int getDebtPinNum()const;
	std::string getBank()const;
	std::string getName()const;

	virtual double pay(double);
	virtual void fileOutput();
};

#endif // !DEBIT_H