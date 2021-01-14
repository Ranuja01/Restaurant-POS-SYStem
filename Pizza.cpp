#include "Pizza.h"

// Default Constructor

Pizza::Pizza() : Dish() {}

// Non default constructor

Pizza::Pizza(double ingredients[15],double price) : Dish(ingredients,price) {}

// Prints information on the food item

void Pizza::print() {
	std::cout << "Pizza:  $" << price << "\n";
}