#ifndef CHEQUE_H
#define CHEQUE_H

#include "Payment.h"
#include <ctime>

class Cheque : public Payment
{
protected:
	double deposit;
	std::string address;
	int chequeNumber;
	std::string memo;
	std::string name;
	int transitNumber;
	int financialNumber;
	int accountNumber;

public:
	Cheque();

	void setDeposit(double);
	void setAddress(std::string);
	void setChequeNumber(int);
	void setMemo(std::string);
	void setName(std::string);
	void setTransitNumber(int);
	void setFinancialNumber(int);
	void setAccountNumber(int);

	double getDeposit()const;
	std::string getAddress()const;
	int getChequeNumber()const;
	std::string getMemo()const;
	std::string getName()const;
	int getTransitNumber()const;
	int getFinancialNumber()const;
	int getAccountNumber()const;

	virtual double pay(double);
	virtual void fileOutput();

};


#endif // !CHEQUE_H