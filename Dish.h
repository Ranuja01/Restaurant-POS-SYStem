#ifndef DISH_H
#define DISH_H

#include <iostream>

class Dish{

protected:
	
	/*double salt, sugar, blackPepper, chilliPowder,
		   onions, peppers, cheese, oil, chicken, fish,
		   beef, mushrooms,carrots, flour, garlic;*/

	double ingredients [15];
	double price;
	
public:
	Dish();
	Dish(double [15],double);

	void setIngredients(double[15]);
	void setPrice(double);
	double getQuantity(int) const;
	double getCost() const;
	virtual void print() {}
	//void makeDish(Inventory in);

};

#endif 