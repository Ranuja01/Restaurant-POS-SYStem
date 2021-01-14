#include "Inventory.h"

// Default Constructor

Inventory::Inventory()
{

	//	Only one instance of the inventory class is made
	//	The struct paramater is file inputted information
	
	for (int i = 0; i < 15; i++) {
		inventory[i].ingredient = "";
		inventory[i].purchaseDate = "";
		inventory[i].expiryDate = "";
		inventory[i].unitCost = 0;
		inventory[i].quantity = 0;
	}

}

// Non default constructor

Inventory::Inventory(inventoryStruct in[15])
{
	
	//	Only one instance of the inventory class is made
	//	The struct paramater is file inputted information
	
	for (int i = 0; i < 15; i++) {
		inventory[i].ingredient = in[i].ingredient;
		inventory[i].purchaseDate = in[i].purchaseDate;
		inventory[i].expiryDate = in[i].expiryDate;
		inventory[i].unitCost = in[i].unitCost;
		inventory[i].quantity = in[i].quantity;
	}

}

/*
void Inventory::addIngredient(string nameOfStructObject, string Ingredient, string PurchaseDate, string ExpireryDate, double UnitCost, int Quantity)
{
	inventoryStruct nameOfStructObject = { Ingredient, PurchaseDate, ExpireryDate, UnitCost, Quantity };
}
*/

void Inventory::setInventory(Dish dishes [], int size)
{

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < 15; j++) {

			/*
				 Takes the inventory item and subtracts the equivalent 
				 ingredients from each dish in the order

			*/
			inventory[j].quantity -= dishes[i].getQuantity(j);
		}
		
	}

	// Checks to see if inventory is running low after the dishes are made
	checkInventory();

}

// Checks to see if there is a shortage on any of the ingredients for an order
// If there is a shortage, false will be returned the order will be remade

bool Inventory::recalculateInventory(Dish dish)
{

	for (int i = 0; i < 15; i++) {
		
		

		if (inventory[i].quantity - dish.getQuantity(i) < 0) {
			return false;
		}
		
	}

	return true;

}

// Checks if any ingredient is out or running low in the inventory

void Inventory::checkInventory() {
	
	

	for (int i = 0; i < 15; i++) {
		if (inventory[i].quantity  <= 10) {
			if (inventory[i].quantity == 0) {
				cout << "Out of " << inventory[i].ingredient << "!" << endl;
			} else {
				cout << "Running low on " << inventory[i].ingredient << "!" << endl;
			}
		}

	}
}
