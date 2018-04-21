#pragma once
#include "Player.h"
#include "InputManager.h"

class PlayerController 
{
public:
	PlayerController() 
	{
	//controller = SerialInterface();
	}
	~PlayerController() {};

	void control(Character* player, InputManager &input, float deltaTime, std::vector<Object*> activeObjects); //change character to player type later

	SerialInterface getController() 
	{
		return controller;
	}

private:
	SerialInterface controller;

};