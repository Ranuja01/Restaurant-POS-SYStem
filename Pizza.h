#ifndef PIZZA_H
#define PIZZA_H

#include "Dish.h"



class Pizza: public Dish{

public:
	Pizza();
	Pizza(double[15],double);
	virtual void print();

};

#endif 