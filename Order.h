#ifndef ORDER_H
#define ORDER_H

#include "Dish.h"
#include "Payment.h"
#include "Inventory.h"

class Order {
private:
	std::string waiter;
	int tableNum;
	int numberOfOrders;
	Dish *dishes;
	Inventory in;

public:
	Order();
	Order(std::string, int,int, Dish*,Inventory);
	void setInventory(Inventory);
	bool createOrder();
};

#endif