#include "Order.h"

// Default Constructor

Order::Order() {
	waiter = "";
	tableNum = 0;
	numberOfOrders = 0;
	dishes = nullptr;
	in = Inventory();
}

// Non default constructor

Order::Order(std::string name, int num , int numOrders, Dish* order,Inventory inv) {
	waiter = name;
	tableNum = num;
	numberOfOrders = numOrders;
	dishes = order;
	in = inv;
}

void Order::setInventory(Inventory i) {
	in = i;
}

// Creates the order that was placed

bool Order::createOrder() {
	int count = 0;
	bool loop = true;

	// First checks if there is sufficient ingredients for each dish

	for (int i = 0; i < numberOfOrders; i++){
		if (in.recalculateInventory(*(dishes + count)) == true) {
			count++;
		}
		else {
			return false;
		}
	}

	// If there are enough ingredients, they are subsequently subtracted from the inventory to represent them being used

	in.setInventory(dishes, numberOfOrders);
	return true;

	
}