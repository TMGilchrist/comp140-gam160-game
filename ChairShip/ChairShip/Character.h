#pragma once
#include "Object.h"

class Character : public Object
{
public:
	Character() {};

	//Add docstring for constructor!
	Character(int initHealth, float initSpeed, SDL_Renderer* renderer=NULL, char* imagePath=NULL, float height=0, float width=0) : Object(renderer, imagePath, height, width)
	{
		health = initHealth;
		speed = initSpeed;
	}

	~Character() {};

	//Change health by an amount
	void changehealth(int healthChange)
	{
		health = health + healthChange;
	}

	//Getters and Setters
	float getSpeed()
	{
		return speed;
	}
	int getHealth()
	{
		return health;
	}

	void setHealth(int newHealth)
	{
		health = newHealth;
	}
	void setSpeed(float newSpeed)
	{
		speed = newSpeed;
	}
	
private:
	//Character's hitpoints
	int health;

	//Character's movement speed
	float speed;

};