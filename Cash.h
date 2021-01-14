#ifndef CASH_H
#define CASH_H


#include "Payment.h"

class Cash : public Payment
{
protected:
	int fiveDollarbillQuantity;
	int tenDollarBillQuantity;
	int twentyDollarBillQuantity;
	int fiftyDollarBillQuantity;
	int hundredDollarBillQuantity;
	double nickelQuantity;
	double dimeQuantity;
	double quarterQuantity;
	double loonieQuantity;
	double toonieQuantity;
public:
	Cash();

	void setFiveDollarbillQuantity(int);
	void setTenDollarBillQuantity(int);
	void setTwentyDollarBillQuantity(int);
	void setFiftyDollarBillQuantity(int);
	void setHundredDollarBillQuantity(int);
	void setNickelQuantity(double);
	void setDimeQuantity(double);
	void setQuarterQuantity(double);
	void setLoonieQuantity(double);
	void setToonieQuantity(double);

	int getFiveDollarbillQuantity()const;
	int getTenDollarBillQuantity()const;
	int getTwentyDollarBillQuantity()const;
	int getFiftyDollarBillQuantity()const;
	int getHundredDollarBillQuantity()const;
	double getNickelQuantity()const;
	double getDimeQuantity()const;
	double getQuarterQuantity()const;
	double getLoonieQuantity()const;
	double getToonieQuantity()const;

	virtual double pay(double);
	virtual void fileOutput();
};

#endif