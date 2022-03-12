#pragma once
#include <fstream>
#include <iostream>
#include<conio.h>
#include<string>

using namespace std;

#include "Item.h"
#include"Location.h"
#include"Player.h"
class Game
{
	Player player;
	vector<Location> allLocations;
	bool flag;
public:
	Game() { flag = false; player = Player(); }		//default constructor
	void gameManager();								//manages all the games
	void prepareGame();								//looping for each room
	void runGame(int i);							//handles each command for one room 
	void readFile(string name);						//read data file and store if game
	void instructions();							//display	instructions
	int to_int(string num);							//convert string to int 
	vector<string> split(string str, char seperator);//split the string	
	int getCommand(string str);						//get which command user write
	void look(vector<string> subStrings);			//handles look command 
	void take(vector<string> subStrings);			//handles take command
	void drop(vector<string> subStrings);			//handles drop command
	void open(vector<string> subStrings);			//handles open command
	void help(vector<string> sunStrings);			//handles help command
	bool canOpen(Item& item);						//check if you have keys to open item
	int itemIndex(string subStrings, vector<Item> itemList);	//search item through name
	string extractName(vector<string> subStrings, int startPoint);	//get name of item from user input

};

