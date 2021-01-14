#include "Burger.h"

// Default constructor

Burger::Burger(): Dish() {}

// Non default constructor

Burger::Burger(double ingredients [15],double price) : Dish(ingredients,price) {}

// Prints information on the food item

void Burger::print() {
	std::cout << "Burger:  $" << price << "\n";
}