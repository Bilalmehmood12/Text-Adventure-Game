#include "Location.h"
//print name and description of location
void Location::print()
{
	Item item;
	cout << name << endl;
	cout << description << endl;
	if (!contents.empty())	//if location has items
	{
		for (int i = 0; i < contents.size();i++)
		{
			item = contents.at(i);
			cout << item.getName() << " - " << item.getDescription() << endl;
		}
	}
	else
	{
		cout << " There is no item in the location" << endl;
	}

}
//remove item from location
bool Location::take_item(Item* item)
{
	if (contents.empty())	
	{
		cout << "There is no item in this location (" << name << ")." << endl;
		return false;
	}
	else	//if location has item
	{
		for (int i = 0; i < contents.size();i++)
		{
			if (*item == contents.at(i))
			{
				contents.erase(contents.begin() + i);	//remove item
				cout << item->getName() << " sucessfully added to your inventory!" << endl;
				setContents(contents);		//update items
				return true;
			}
		}
		cout << "Unable to take " << item->getName() << ". Please try again!" << endl;
		return false;
	}
}
//add item to location
bool Location::drop_item(Item* item)
{
	if ((item->getName() != "\0" && item->getDescription() != "\0")) //if item is null
	{
		contents.push_back(*item);
		return true;
	}
	return false;
}
//add item to location even inventory does not have it
bool Location::add_item(Item* item)
{
	contents.push_back(*item);
	return true;
}
//checking if you solve the room and get password
bool Location::checkPassword(string str)
{
	if (password[0] == str)
	{
		return true;
	}
	return false;
}
//Item* Location::getKey(string& direction)
//{
//
//}
//Location* Location::getConnection(string& direction)
//{
//
//}