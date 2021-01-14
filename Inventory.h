#ifndef INVENTORY_H
#define INVENTORY_H

#include "Pizza.h"
#include "Burger.h"

#include <string>
#include <iostream>

using namespace std;

struct inventoryStruct
{
	string ingredient;
	string purchaseDate;
	string expiryDate;
	double unitCost;
	double quantity;
};

class Inventory
{
protected:
	
	inventoryStruct inventory[15];
public:

	Inventory();
	Inventory(inventoryStruct inventory[15]);
	void setInventory(Dish dishes [], int size);
	bool recalculateInventory(Dish);
	void checkInventory();
	string getIngredient(int index) { return inventory[index].ingredient; }
};

#endif // !INVENTORY_H