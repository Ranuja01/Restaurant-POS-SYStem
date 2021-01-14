#include "Dish.h"

// Default Constructor

Dish::Dish() {

	//ingredients[0] = 0;

	for (int i = 0; i < 15; i++) {
		ingredients[i] = 0;
	}

	price = 0;

}

// Non default constructor

Dish::Dish(double in [15],double price) {
	
	ingredients [0] = 0;

	for (int i = 0; i < 15; i++){
		ingredients[i] = in [i];
	}
	
	this->price = price;

}

// Accessor / Mutator methods

void Dish::setIngredients(double in[15]) {


	for (int i = 0; i < 15; i++) {
		ingredients[i] = in[i];
	}


}

void Dish::setPrice(double price) {

	this->price = price;

}

// Specifically accesses a given index of the member array

double Dish::getQuantity(int index) const {
	return ingredients[index];
}

double Dish::getCost() const {
	return price;
}
