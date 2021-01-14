#ifndef BURGER_H
#define BURGER_H

#include "Dish.h"



class Burger : public Dish {

public:
	Burger();
	Burger(double[15],double);
	virtual void print();

};

#endif 
