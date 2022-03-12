#include "Game.h"

void Game::gameManager()
{
	readFile("test.txt");
	instructions();
	prepareGame();
}
void Game::runGame(int i)	
{
	Location curLocation = allLocations[i];
	player.setLocation(curLocation);
	string input;
	while (1)
	{
		if (flag)	//if game win
		{
			break;
		}
		input.clear();
		cout << "\n> ";
		getline(cin, input);	//command input
		system("pause");
		cout << "\n";
		vector<string> subStrings = split(input, ' ');	//split command
		string command = subStrings[0];
		switch (getCommand(command))		//switch for input command
		{
		case 1:
			look(subStrings);
			break;
		case 2:
			take(subStrings);
			break;
		case 3:
			drop(subStrings);
			break;
		case 4:
			open(subStrings);
			break;
		case 5:
			player.printStatus();
			break;
		case 6:
			help(subStrings);
			break;
		case 7:
			instructions();
			break;
		default:
			cout << " Invalid input!!!" << endl;
			break;
		}
	}
}
void Game::readFile(string name)
{
	string title, detail;
	string input;
	ifstream in(name);	//reading variable
	if (in)
	{
		getline(in, title);
		getline(in, detail);
		cout << " " << title << endl;
		vector<string> details = split(detail, '.');
		for (int i = 0; i < details.size(); i++)
		{
			cout << " " << details[i] << endl;
		}
		while (!in.eof())
		{
			in >> input;
			while ((input == "Location:"))	//for each location
			{
				Location loc;
				vector<Item> contentItems;	//contents of item
				Item cItem;					//one item of location
				in >> input;
				loc.setNum(to_int(input));	//location number
				in >> input;
				getline(in, input);
				loc.setName(input);			//location name
				in >> input;
				getline(in, input);
				loc.setDescription(input);	//location description
				loc.setDoor(false);
				in >> input;
				getline(in, input);
				loc.setPassword(split(input,'.'));	//password to clear the room
				//contents
				in >> input;
				while (input == "Contents:")		//contents of the location
				{
					vector<Item> itemContent;
					vector<string> keyItems;
					in >> input;
					getline(in, input);
					//1st item
					cItem.setName(input);
					in >> input;
					getline(in, input);
					cItem.setDescription(input);
					in >> input;
					getline(in, input);
					if (input == " true")	//if opened is true
					{
						cItem.setOpened(true);
						in >> input;
					}
					else
					{
						cItem.setOpened(false);
						in >> input;
						while (input == "content:")	//if not opened means have contents inside the item
						{
							Item contentItem;		//item inside the content of item
							getline(in, input);
							contentItem.setName(input);
							in >> input;
							getline(in, input);
							contentItem.setDescription(input);
							contentItem.setOpened(true);
							itemContent.push_back(contentItem);	//add cotents inside item
							in >> input;
						}
						while (input == "key_item:")	//if item need any keys to open the item
						{
							string keyItem;
							getline(in, input);
							keyItem = input;
							keyItems.push_back(keyItem);
							in >> input;
						}
					}
					cItem.setKey_item(keyItems);	//set keys of item
					cItem.setContents(itemContent);	//set contents of item
					contentItems.push_back(cItem);	//add item to location
				}
				loc.setContents(contentItems);		//set contents of location
				allLocations.push_back(loc);		//add location to allLocation
			}
		}
	}
	else
		cout << " Game not found!!!" << endl;
}
int Game::to_int(string num)
{
	int result = 0;
	for (int i = 0;i < num.size();i++)
	{
		result = num[i]-48;		//converting charactor to int
		result *= 10;
	}
	result /= 10;
	return result;
}
void Game::prepareGame()
{
	for (int i = 0; i < allLocations.size(); i++)	//for all locations
	{
		flag = false;
		player.clear();
		runGame(i);				//game for one location
	}
}
void Game::instructions()
{
	cout << "\n ************************************************************\n";
	cout << " Instructions:\n";
	cout << " Name of the items are case sensitive\n";
	cout << " You can enter following commands in either case\n";
	cout << " 1. Inventory: to the items you currently have\n";
	cout << " 2. LOOK: to list the items(eg, around or inside item_name)\n";
	cout << " 3. TAKE: to pick up an item(eg, TAKE flash light)\n";
	cout << " 4. DROP: to drop an item(eg, DROP flash light)\n";
	cout << " 5. OPEN: to open an item(eg, OPEN box)\n";
	cout << " 6. TURN_ON: for electronic devices(eg, TURN_ON Television)\n";
	cout << " 7. HELP: to see the description of item(eg, HELP item_name)\n";
	cout << " 8. INSTRUCTIONS: to see the list of available commands\n";
	cout << " 9. QUIT: to quit the game\n";
	cout << " ************************************************************\n";
}
vector<string> Game::split(string str, char seperator)
{
	vector<string> subStrings;
	int currIndex = 0, i = 0;
	int startIndex = 0, endIndex = 0;
	while (i <= str.size())
	{
		if (str[i] == seperator || i == str.size())	//if there is a seperator
		{
			endIndex = i;
			string subStr = "";
			subStr.append(str, startIndex, endIndex - startIndex);
			subStrings.push_back(subStr);
			currIndex += 1;
			startIndex = endIndex + 1;
		}
		i++;
	}
	return subStrings;
}
int Game::getCommand(string str)
{
	if (str == "LOOK"|| str == "look")
	{
		return 1;
	}
	else if (str == "TAKE"|| str == "take")
	{
		return 2;
	}
	else if (str == "DROP"|| str == "drop")
	{
		return 3;
	}
	else if (str == "OPEN"|| str == "open"|| str == "TURN_ON"|| str == "turn_on")
	{
		return 4;
	}
	else if (str == "QUIT"|| str == "quit")
	{
		exit(0);
	}
	else if (str == "INVENTORY"|| str == "inventory")
	{
		return 5;
	}
	else if (str == "HELP" || str == "help")
	{
		return 6;
	}
	else if (str == "INSTRUCTIONS" || str == "instructions")
	{
		return 7;
	}
	else
	{
		return -1;
	}
}
void Game::look(vector<string> subStrings)
{
	Location curLocation = player.getLocation();
	vector<Item> contents = curLocation.getContents();
	if (subStrings.size() == 2 && (subStrings[1] == "around" || subStrings[1] == "AROUND")) //for keyword around 
	{
		player.setSteps(player.getSteps() + 1);
		curLocation.print();
	}
	else if (subStrings.size() > 2 && (subStrings[1] == "inside"|| subStrings[1] == "INSIDE"))	//for keyword inside
	{
		string itemName = extractName(subStrings, 2);
		vector<Item> content = player.getInventory();
		int index = itemIndex(itemName,content);	//if you have item
		if (index == -1)
		{
			cout << " You do not have " << itemName << " in your inventory." << endl;
		}
		else
		{
			player.setSteps(player.getSteps() + 1);
			Item item = content.at(index);
			item.printItem();			//print contents of item
		}
	}
	else if (subStrings.size() >= 2 && !(subStrings[1] == "around" || subStrings[1] == "inside"))
	{
		cout << " Incorrect keyword. Try using keyword(LOOK around or LOOK inside name_of_item)" << endl;
	}
	else
	{
		cout << " Too few arguments. Example (LOOK around or LOOK inside name_of_item)" << endl;
	}
}
void Game::take(vector<string> subStrings)
{
	Location curLocation = player.getLocation();
	vector<Item> contents = curLocation.getContents();
	string itemName = extractName(subStrings, 1);
	int index = itemIndex(itemName, contents);
	if (subStrings.size() > 1 && index != -1)	//if item exists
	{
		player.setSteps(player.getSteps() + 1);
		Item item = contents.at(index);
		player.takeItem(&item);					//take item
	}
	else if (subStrings.size() > 1 && index == -1)	//if wrong item name
	{
		cout << " Incorrect item name or item is not pesent in this location" << endl;
	}
	else if (subStrings.size() == 1)	//if there is no item name
	{
		cout << " Too few arguments. Example (TAKE name_of_item)" << endl;
	}
	else
	{
		cout << itemName << " is not present in this location." << endl;
	}
}
void Game::drop(vector<string> subStrings)
{
	Location curLocation = player.getLocation();
	vector<Item> contents = player.getInventory();
	string itemName = extractName(subStrings, 1);
	int index = itemIndex(itemName, contents);
	if (subStrings.size() > 1 && index != -1)	//if item exists
	{
		player.setSteps(player.getSteps() + 1);
		Item item = contents.at(index);
		player.dropItem(&item);					//drop item
	}
	else if (subStrings.size() > 1 && index == -1)	//if wrong item name
	{
		cout << " Incorrect item name or you do not have it" << endl;
	}
	else if (subStrings.size() == 1)	//if no item name
	{
		cout << " Too few arguments. Example (DROP name_of_item)" << endl;
	}
	else
	{
		cout << itemName << " is not present in your inventory." << endl;
	}
}
void Game::open(vector<string> subStrings)
{
	vector<Item> contents = player.getInventory();
	string itemName = extractName(subStrings, 1);
	int index = itemIndex(itemName, contents);
	Location loc = player.getLocation();
	if (subStrings.size() == 3 && (subStrings[1] == "door" || subStrings[1] == "DOOR") && player.getLocation().getDoor()) //for keyword door
	{

		if (subStrings[2] == player.getLocation().getPassword())
		{
			cout << " Conratulations!!! You have cleared the " << player.getLocation().getName() << endl;
			flag = true;
		}
	}
	else if (subStrings.size() > 1 && index != -1)
	{
		Item item = contents[index];
		if (canOpen(item))		//if you have keys
		{
			player.setSteps(player.getSteps() + 1);
			if (player.openItem(&item))		//open item and get contents
			{
				vector<Item> tempContents = player.getInventory();
				tempContents[index] = item;
				player.setInventory(tempContents);
				if (player.getLocation().getPasswordName() == item.getName())	//if password matches
				{
					loc.setDoor(true);
					player.setLocation(loc);
				}
			}
		}
		else
		{
			cout << " You do not have tool to open" << item.getName() << "." << endl;
		}
	}
	else if (subStrings.size() == 1)
	{
		cout << " Too few arguments. Example (OPEN name_of_item)" << endl;
	}
	else
	{
		cout << " Incorrect keyword or item name. Try using keyword(OPEN/TURN_ON name_of_item)" << endl;
	}
}
void Game::help(vector<string> subStrings)
{
	Location curLocation = player.getLocation();
	vector<Item> contents = player.getInventory();
	string itemName = extractName(subStrings, 1);
	int index = itemIndex(itemName, contents);
	if (subStrings.size() > 1 && index != -1)	////if item exists
	{
		player.setSteps(player.getSteps() + 1);
		Item item = contents.at(index);
		cout << " " << item.getDescription() << endl;
	}
	else if (subStrings.size() > 1 && index == -1)		//if wrong item name
	{
		cout << " Incorrect item name or you do not have it" << endl;
	}
	else if (subStrings.size() == 1)		//if no item name
	{
		cout << " Too few arguments. Example (HELP name_of_item)" << endl;
	}
	else
	{
		cout << itemName << " is not present in your inventory." << endl;
	}
}
bool Game::canOpen(Item& item)
{
	vector<string> keys = item.getKey_item();
	vector<Item> inventory = player.getInventory();
	for (int i = 0; i < keys.size(); i++)
	{
		int index = itemIndex(keys[i], inventory);	//if you have key
		if (index != -1)
		{
			Item newItem = inventory[index];
			if (newItem.getKey_item().size() != 0 && canOpen(newItem))	//if you need key to open key
			{
				return true;
			}
			else if (newItem.getKey_item().size() == 0)		//if you do not need key
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	return true;
}
int Game::itemIndex(string itemName, vector<Item> itemList)
{

	for (int i = 0; i < itemList.size(); i++)
	{
		Item item = itemList[i];
		if (item.getName() == itemName)		//item found
		{
			return i;						//return index of item
		}
	}
	return -1;
}
string Game::extractName(vector<string> subStrings, int startPoint)
{
	string itemName = "";
	for (int i = startPoint; i < subStrings.size();i++)
	{
		if (i < subStrings.size() - 1)
		{
			itemName.append(subStrings[i] + " ");	//joining subStrings and space
		}
		else	//for last word 
		{
			itemName.append(subStrings[i]);		//no need to add space
		}
	}
	return " " + itemName;
}