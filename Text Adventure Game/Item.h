#pragma once
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Item
{
	string name;
	string description;
	bool opened;
	vector<string> key_item;
	vector<Item> contents;

public:
	Item() { name = "\0"; description = "\0"; opened = false; }		//default constructor
	Item(string _name, string _description, vector<Item> _contents, vector<string> _key_item, bool _open)
	{		//parameteric constructor
		name = _name; description = _description;  opened = _open;
		contents = _contents; key_item = _key_item;
	}
	Item(const Item& item)		//copy constructor
	{
		name = item.name; description = item.description;  opened = item.opened;
		contents = item.contents; key_item = item.key_item;
	}
	//getter members
	string getName() { return name; }
	string getDescription() { return description; }
	bool getOpened() { return opened; }
	vector<Item> getContents() { return contents; }
	vector<string> getKey_item() { return key_item; }
	//setter members 
	void setName(string _name) { name = _name; }
	void setDescription(string _description) { description = _description; }
	void setKey_item(vector<string> _key_item) { key_item = _key_item; }
	void setContents(vector<Item> _contents) { contents = _contents; }
	void setOpened(bool flag) { opened = flag; }
	void setSpecialAttributes(vector<Item> _contents, vector<string> _key_item, bool _opened);
	//caparison overloading
	bool operator == (Item& item);
	//print item contents
	void printItem();
	bool open();
};