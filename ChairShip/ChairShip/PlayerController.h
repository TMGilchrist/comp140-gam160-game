#pragma once
#include "Player.h"
#include "InputManager.h"

class PlayerController 
{
public:
	PlayerController() {};
	~PlayerController() {};

	//Convert keyboard or controller inputs into player controls
	void control(Player* player, InputManager &input, float deltaTime, std::vector<Object*> &activeObjects); //change character to player type later

	//Getters
	SerialInterface getController() 
	{
		return controller;
	}

private:
	//The serial interface communicating with the arudino controller
	SerialInterface controller;

};