#include "Player.h"
//check if inventory has the item
bool Player::hasItem(Item* item)
{
	for (int i = 0; i < inventory.size();i++)
	{
		if (*item == inventory.at(i))
		{
			return true;
		}
	}
	return false;
}
//take item from location add to inventory and remove from location
bool Player::takeItem(Item* item)
{
	if (curLocation.take_item(item))	//removing item from location
	{
		inventory.push_back(*item);		//adding item to inventory if it is been removed from location
		return true;
	}
	return false;
}
//add item to the location and remove from inventory
bool Player::dropItem(Item* item)
{
	if (inventory.empty())	//if you do not have any item
	{
		cout << " There is no item in your inventory." << endl;
		return false;
	}
	else
	{
		for (int i = 0; i < inventory.size();i++)
		{
			if (*item == inventory.at(i))
			{
				inventory.erase(inventory.begin() + i);		//removing from inventory
				cout << item->getName() << " sucessfully removed to your inventory!" << endl;
				setInventory(inventory);		//updating inventory
				curLocation.drop_item(item);	//add to location if it is remove from inventory
				return true;
			}
		}
		cout << " Unable to take " << item->getName() << ". Please try again!" << endl;
		return false;
	}
}
//open item and add contents to inventory
bool Player::openItem(Item* item)
{
	vector<Item> contents = item->getContents();
	if (!item->getOpened())		//if it is not already opened
	{
		item->setOpened(true);	//set it is opened
		if (curLocation.checkPassword(item->getName()))	//if you solve room
		{
			cout << " The password to door is " << curLocation.getPassword() << endl;
			return true;
		}
		cout << item->getName() << " opened! Contents added to inventory." << endl;
		//adding items to inventory
		for (int i = 0; i < contents.size(); i++)
		{
			cout << contents.at(i).getName() << " - " << contents.at(i).getDescription() << endl;
			inventory.push_back(contents.at(i));
		}
		return true;
	}
	cout << item->getName() << " is already opened!" << endl;
	return false;
}
//print items in inventory
void Player::printStatus()
{
	if (!inventory.empty())	//if has any item 
	{
		cout << " You have following items in your invetory:" << endl;
		for (int i = 0;i < inventory.size();i++)	//display all the items
		{
			cout << inventory[i].getName() << " - " << inventory[i].getDescription() << endl;
		}
	}
	cout << " You have already taken " << steps << " steps." << endl;
}