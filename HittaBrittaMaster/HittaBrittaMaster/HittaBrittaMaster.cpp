//***********************************************
//*Hitta Britta en CHEF© produktion. 2018	    *
//* Made by Christoffer Stathin & Timmie Nilsson*
//***********************************************
#include "pch.h"

#define NOMINMAX // Must use since std::max wont function with Windows.h
#include <iostream>
#include "player.h"
#include <string>
#include <Windows.h>
#include <limits> // Using with numeric limits

const int GuessingGameNumber = 3; // the magic number for the guessing game
int Guess;

using namespace std;
Player* player = new Player(); // Create a (GLOBAL)player 
bool GameOn = true; // To make sure the do while shall run or not
int choice = 0; // Pick variable
enum Areas  // The map
{
	House,
	Forest,
	Basement,
	Kitchen,
	DeepForest,
	EndForest
};
Areas area = House; // Make map/area object
int GameChoice();  //Declare the GameChoice function witch we use to make sure to only accept numeric input
void Intro(); // Forward declare
void FHouse();
void FForest();
void FBasement();
void FKitchen();
void FDeepForest();
void FEndForest();

int main()
{

	Intro();// INTRO


	do
	{
		switch (area)
		{
			case House:
			{	
				FHouse();
				break;
			}
			case Basement:
			{
				FBasement();
				break;
			}
			case Kitchen:
			{	
				FKitchen();
				break;
			}
			case Forest:
			{
				FForest();
				break;
			}
			case DeepForest:
			{
				FDeepForest();
				break;
				
			}
			case EndForest:
			{
				FEndForest();
				break;
			}
			default:
			{
				break;
			}
		}
	}while (GameOn);
	
player = nullptr; // Nulls the pointer, its a good habbit.
}


void Intro()
{
	cout << "This game is a text based game." << endl;
	cout << "You will, by means of numbers, go through some assignments that will lead you to your girlfriend whom you will save." << endl;
	cout << "But only if you make the right choices." << endl;
	system("pause");

	system("CLS");

	cout << "Hi fella, what is your name? " << endl;
	getline(cin, player->playername);
	cout << "WELCOME " << player->playername << " You wake up from being unconscious for a good five hours. You don't know what happened to you." << endl;
	system("pause");
	cout << "You only remember that you and your girlfriend Britta was on a roadtripp to go grocery shopping." << endl;
	system("pause");
	cout << "Britta is gone and you are locked inside an abandoned house in the middle of nowhere." << endl;
	system("pause");
	cout << "Find Britta and make her comfortable!\n" << endl;
	system("pause");
}

int GameChoice() 
	{
	int x = 0;
		while (cout << "\n" && !(cin >> x))
		{
			cin.clear(); //Cleanses the input else it will start a loop since it will save the error input in x
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Ignores the input if its not a valid input
			cout << "ERROR INPUT TYPE: Invalid choice, try again.";
		}

return x;
}

void FHouse()
{
	player->PlayerPos = "House";
	cout << "***You are currently in the " << player->PlayerPos << ". What do you want to do?***\n" << endl;
	cout << "[1]: Look around for item\n[2]: Go to the Basement\n[3]: Go to the Forest\n[4]: Go to the Kitchen\n[9]: Open Backpack\n[0]: Quit Game\n" << endl;
	choice = GameChoice();
	system("CLS");
	if (choice == 1 && player->Axe == false)
	{
		cout << "Looking around...\n";
		cout << "You have found an axe under the doormat!" << endl;
		player->Axe = true;
	}
	else if (choice == 2 && player->Axe == true && player->DoorBroken == false)
	{
		cout << "You chop down the door with the axe and enter the Basement.\n" << endl;
		area = Basement;
	}
	else if (choice == 2 && player->Axe == true && player->DoorBroken == true)
	{
		cout << "You enter the Basement.\n" << endl;
		area = Basement;
	}
	else if (choice == 2 && player->Axe == false)
	{
		cout << "The door is locked.\n" << endl;
	}
	else if (choice == 1 && player->Axe == true)
	{
		cout << "Looking around..." << endl;
		Sleep(3000);
		cout << "You found nothing.\n" << endl;
	}
	else if (choice == 3 && player->Key == true)
	{
		area = Forest;
	}
	else if (choice == 3 && player->Key == false)
	{
		cout << "The door is locked, try to find a key inside the house." << endl;
		area = House;

	}
	else if (choice == 4)
	{
		area = Kitchen;
	}
	else if (choice == 9)
	{
		player->ShowBackpack();
	}
	else if (choice == 0)
	{
		cout << "We don't want pussies here anyways " << player->playername << "!!" << endl;
		GameOn = false;
	}
}

void FBasement()
{
	player->PlayerPos = "Basement";
	cout << "***You are currently at " << player->PlayerPos << ". What do you want to do?***\n" << endl;
	if (player->Key == false)
	{
		cout << "You see a key on the floor, would you like to pick it up?\n[1]: Yes\n[2]: No, for some stupid reason" << endl;
		choice = GameChoice();
		if (choice == 1)
		{
			player->Key = true;
			cout << "You picked up Key!" << endl;
		}
		else if (choice == 2)
		{
			area = House;
			player->PlayerPos = "House";
			cout << "You walk up the stairs and ignore the key.\n";
		}
	}
	else if (player->Key == true)
	{
		cout << "The basement is empty. Press [1]: Walk up the stairs again.\n";
		choice = GameChoice();
		if (choice == 1) {
			area = House;
		}
	}
}

void FKitchen()
{
	player->PlayerPos = "Kitchen";
	cout << "***You are currently at " << player->PlayerPos << ". What do you want to do?***\n" << endl;
	cout << "[1]: Look around for item\n[2]: Go back\n[9]: Open Backpack\n[0]: Quit Game\n" << endl;
	choice = GameChoice();
	if (choice == 1 && player->Flashlight == false)
	{
		cout << "Looking around...\n";
		Sleep(3000);
		cout << "You were lucky! You have found a flashlight and a sharp knife!!" << endl;
		player->Flashlight = true;
		player->Knife = true;
	}
	else if (choice == 2)
	{
		area = House;
	}
	else if (choice == 9)
	{
		player->ShowBackpack();
	}
	else if (choice == 0)
	{
		cout << "We don't want pussies here anyways " << player->playername << "!!" << endl;
		GameOn = false;
	}
	else if (choice == 1 && player->Flashlight == true)
	{
		cout << "You look around and find nothing." << endl;
	}
}

void FForest()
{
	player->PlayerPos = "Forest";
	cout << "***You are currently at " << player->PlayerPos << " ***.\n";

	if (player->GuessMan == false)
	{

		cout << "A man is blocking the way, he require you to guess a number between 1 and 10 to continue you adventure.\n Press [1] To start guessing game";
		choice = GameChoice();
		if (choice == 1)
		{
			while (GuessingGameNumber != Guess)  // This loop is within the big do while loop there for its nested
			{
				cout << "Enter your guess: \n";
				Guess = GameChoice();
			}
		}
		player->GuessMan = true;
		cout << "The man says: CONGRATULATIONS, you have guess the right number, it was number 3." << endl;

	}
	else if (player->GuessMan == true)
	{
		cout << "You hear a crowded scream from the Deeper Forest." << endl;

		cout << "[1]: Go deeper into the forest\n[2]: Go back the House\n[9]: Open Backpack\n[0]: Quit Game\n" << endl;
		choice = GameChoice();
		if (choice == 1)
		{
			cout << "You go deeper into the forest..\n" << endl;
			Sleep(3000);
			area = DeepForest;
		}
		else if (choice == 2)
		{
			area = House;
		}
		else if (choice == 9)
		{
			player->ShowBackpack();
		}
		else if (choice == 0)
		{
			cout << "We don't want pussies here anyways " << player->playername << "!!" << endl;
			GameOn = false;
		}
	}
}

void FDeepForest()
{
	player->PlayerPos = "Deeper Forest";
	cout << "***You are currently in the " << player->PlayerPos << "***" << endl;
	if (player->AnimalDead == false)
	{
		cout << "\nYou see a sleeping wolf\n" << endl;
		cout << "You can either choose to either\n[1]: Try to sneak pass it\n[2]: Go back\n[9]: Open Backpack\n[0]: Quit Game\n" << endl;
		choice = GameChoice();
		if (choice == 1)
		{
			cout << "Walking..." << endl;
			Sleep(4000);
			cout << "You accidentally step on a branch and wakes the Wolf up!" << endl;

			if (player->Knife == false)
			{
				cout << "You don't have any weapon to fight the wolf with!" << endl;
				cout << "Fighting the wolf...\n" << endl;
				Sleep(4000);
				cout << "You loose the fight and die a horrible death." << endl;
				GameOn = false;
			}
			if (player->Knife == true)
			{
				cout << "You bring out your knife and starts swinging it" << endl;
				cout << "Fighting the wolf...\n" << endl;
				Sleep(4000);
				cout << "You kill the wolf!\nPress [1] to loot the wolf.\n";
				player->AnimalDead = true;
				choice = GameChoice();

				if (choice == 1)
				{
					player->Pelt = true;
					cout << "You cut a pelt from the Wolf.\n" << endl;
					cout << "After killing the Wolf you clear a path in front of you." << endl;
					area = EndForest;
				}
			}
		}
		else if (choice == 2)
		{
			area = Forest;
		}
		else if (choice == 9)
		{
			player->ShowBackpack();
		}
		else if (choice == 0)
		{
			cout << "We don't want pussies here anyways " << player->playername << "!!" << endl;
			GameOn = false;
		}
		
	}
	else if (player->AnimalDead == true)
	{
		player->PlayerPos = "Deeper Forest";
		cout << "***You are currently in the " << player->PlayerPos << "***" << endl;
		cout << "You can either choose to either\n[1]: Go to the End of the Deeper Forest.\n[2]: Go back\n[9]: Open Backpack\n[0]: Quit Game\n" << endl;
		if (choice == 1)
		{
			area = EndForest;
		}
		else if (choice == 2)
		{
			area = Forest;
		}
		else if (choice == 9)
		{
			player->ShowBackpack();
		}
		else if (choice == 0)
		{
			cout << "We don't want pussies here anyways " << player->playername << "!!" << endl;
			GameOn = false;
		}
	}
}

void FEndForest()
{
	player->PlayerPos = "the end of the Deeper Forest";
	cout << "You see a cute girl in the distance under a fallen tree, it is Britta!\n";
	cout << "Press [1]: Remove the tree from the Britta body.\n";

	choice = GameChoice();
	if (choice == 1)
	{
		cout << "You remove the log from Britta, she is freezing.\n";
		if (player->Pelt == true)
		{
			cout << "You put the pelt around Britta and she is saved!\nYOU HAVE WON THE GAME!!!\n";
			cout << "Since your are very proud of your mathematical skills you tell her the whole multiplication table";

			for (int i = 1; i <= 10; i++)  // NESTED FOR LOOP
			{
				cout << "\n" << "Number " << i << " table " << "\n";

				for (int y = 1; y <= 10; y++)
				{
					cout << i << " * " << y << " = " << i * y << " & ";
				}
				cout << endl;
			}


			Sleep(5000);
			GameOn = false;
		}
		else {
			cout << "Britta is freezing to death and you have nothing to warm her with.\n\n";
			cout << "Britta is freezing...";
			Sleep(5000);
			cout << "You have lost! Britta has died.";
			Sleep(3000);
			GameOn = false;
		}
	}
}


