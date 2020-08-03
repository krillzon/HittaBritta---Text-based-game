#include "pch.h"
#include "player.h"
#include <iostream>

using namespace std;

Player::Player()
{
}

Player::~Player()
{
}

void Player::ShowBackpack()
{
	cout << "You have ";
	if (Key == true)
	{
		cout << "Key, ";
	}
	if (Axe == true)
	{
		cout << "Axe, ";
	}
	if (Flashlight == true)
	{
		cout << "Flashlight, ";
	}
	if (Battery == true)
	{
		cout << "Battery, ";
	}
	if (Knife == true)
	{
		cout << "Knife, ";
	}
	if (Key == false && Axe == false && Flashlight == false && Battery == false && Knife == false)
	{
		cout << "an empty backpack.";
	}
	cout << endl;
}