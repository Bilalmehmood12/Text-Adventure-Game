#include "Item.h"

bool Item::operator==(Item& item)	//== overloading
{
	if ((item.name == name) && (item.description == description) && item.contents.size() == contents.size() && item.key_item.size() == key_item.size() && item.opened == opened)
	{
		return true;
	}
	return false;
}
//setting special attributes
void Item::setSpecialAttributes(vector<Item> _contents, vector<string> _key_item, bool _opened)	
{
	contents = _contents; key_item = _key_item; opened = _opened;
}
//print item contents
void Item::printItem()
{
	if (contents.size())	//print if there is a contenet
	{
		cout << name << " has following items inside:" << endl;
		for (int i = 0; i < contents.size();i++)
		{
			cout << contents[i].getName() << " - " << contents[i].getDescription() << endl;
		}
	}
	else
	{
		cout << name << " has nothing inside." << endl;
	}
	
}
bool Item::open()
{
	return true;
}

