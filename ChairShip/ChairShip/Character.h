#pragma once
#include "Object.h"
#include "Weapon.h"

class Character : public Object
{
public:
	Character() {};

	//Add docstring for constructor!
	Character(int initHealth, float initXSpeed, float initYSpeed, SDL_Renderer* renderer=NULL, char* imagePath=NULL, float height=0, float width=0) : Object(renderer, imagePath, height, width)
	{
		health = initHealth;
		xSpeed = initXSpeed;
		ySpeed = initYSpeed;
	}

	~Character() {};

	//Change health by an amount
	void changehealth(int healthChange)
	{
		health = health + healthChange;
	}

	void initaliseWeapon(int initDamage, int initProjectileSpeed, int initCooldown, SDL_Renderer* renderer, char* imagePath, int height, int width);

	//Getters and Setters
	float getXSpeed()
	{
		return xSpeed;
	}
	float getYSpeed()
	{
		return ySpeed;
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
		xSpeed = newSpeed;
	}
	void setYSpeed(float newSpeed)
	{
		ySpeed = newSpeed;
	}
	
private:
	//Character's hitpoints
	int health;

	//Character's movement speed
	float xSpeed;
	float ySpeed;

	//Character's weapons
	Weapon weapon;

};