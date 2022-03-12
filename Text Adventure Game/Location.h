#pragma once

#include<string>
#include<vector>
#include<iostream>
using namespace std;

#include"Item.h"
class Location
{
	int num;
	string name, description;
	vector<string> key_items;
	vector<Item> contents;
	string connections;
	bool door;
	vector<string> password;
public:
	//default constructor
	Location() { num = 0;name = "\0"; description = "\0";key_items.clear(); connections = "\0"; door = false; }
	//parameteric constructor
	Location(int _num, string _name, string _description, vector<Item> _contents, vector<string> _key_items, string _connections, bool _door, vector<string> _password)
	{
		num = _num;
		name = _name;
		description = _description;
		contents = _contents;
		key_items = _key_items;
		connections = _connections;
		door = _door;
		password = _password;
	}
	//copy constructor
	Location(const Location& _loc)
	{
		num = _loc.num;
		name = _loc.name;
		description = _loc.description;
		contents = _loc.contents;
		key_items = _loc.key_items;
		connections = _loc.connections;
		door = _loc.door;
		password = _loc.password;
	}
	//setter members
	void setNum(int _num) { num = _num; }
	void setName(string _name) { name = _name; }
	void setDescription(string _description) { description = _description; }
	void setContents(vector<Item> _contents) { contents.clear();contents = _contents; }
	void setKey_items(vector<string> _key_items) { key_items = _key_items; }
	void setConnections(string _connections) { connections = _connections; }
	void setDoor(bool _door) { door = _door; }
	void setPassword(vector<string> _password) { password = _password; }
	//getter members
	int getNum() { return num; }
	string getName() { return name; }
	string getDescription() { return description; }
	vector<Item> getContents() { return contents; }
	vector<string> getKey_items() { return key_items; }
	string getConnections() { return connections; }
	bool getDoor() { return door; }
	string getPassword() { return password[1]; }
	string getPasswordName() { return password[0]; }
	//print name and description of location
	void print();
	//remove item from location
	bool take_item(Item* item);
	//add item to location
	bool drop_item(Item* item);
	//add item to location even inventory does not have it
	bool add_item(Item* item);
	//checking if you solve the room and get password
	bool checkPassword(string str);
	//Item* getKey(string& direction);
	//Location* getConnection(string& direction);
};

