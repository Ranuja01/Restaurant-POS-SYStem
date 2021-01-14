#ifndef CREDIT_H
#define CREDIT_H



#include "Payment.h"

class Credit : public Payment
{
protected:
	std::string credCardType;
	int credPinNum;
	std::string bank;
	std::string name;
public:
	Credit();

	void setCredCardType(std::string);
	void setCredPinNum(int);
	void setBank(std::string);
	void setName(std::string);

	std::string getCredCardType()const;
	int getCredPinNum()const;
	std::string getBank()const;
	std::string getName()const;

	virtual double pay(double);
	virtual void fileOutput();
};

#endif // !CREDIT_H