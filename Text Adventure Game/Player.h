#pragma once

#include<string>
#include<iostream>
#include<vector>
using namespace std;

#include"Location.h"
#include"Item.h"

class Player
{
	Location curLocation;
	vector<Item> inventory;
	int steps;
	
public:
	Player() { steps = 0; curLocation = Location(); }	//default constructor
	//parameteric constructor
	Player(Location _loc, vector<Item> _items, int _steps) { curLocation = _loc;inventory = _items;steps = _steps; }
	//copy constructor
	Player(const Player& _player) { curLocation = _player.curLocation;inventory = _player.inventory;steps = _player.steps; }
	//setter & getter members
	void setLocation(Location& _loc) { curLocation = _loc; }
	Location& getLocation() { return curLocation; }
	vector<Item> getInventory() { return inventory; }
	void setInventory(vector<Item> _inventory) { inventory = _inventory; }
	void setSteps(int _steps) { steps = _steps; }
	int getSteps() { return steps; }
	//check if inventory has the item
	bool hasItem(Item* item);
	//take item from location
	bool takeItem(Item* item);
	//add item to the location
	bool dropItem(Item* item);
	//open item and add contents to inventory
	bool openItem(Item* item);
	//reset the player for next room
	void clear() { inventory.clear(); steps = 0; curLocation = Location(); }
	//print items in inventory
	void printStatus();
};

