#pragma once
#include "pch.h"
#include <vector>
#include <string>

using namespace std;


class Player
{
public:
	bool Key = false;
	bool Axe = false;
	bool Flashlight = false;
	bool Battery = false;
	bool Knife = false;
	bool Pelt = false;
	bool AnimalDead = false;
	bool DoorBroken = false;
	bool GuessMan = false;
	string playername = "";
	string PlayerPos = "HOUSE";
	Player();
	~Player();
	
	void ShowBackpack();

private:
	


};