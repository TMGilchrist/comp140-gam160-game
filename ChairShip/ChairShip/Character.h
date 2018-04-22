#pragma once
#include "Object.h"
#include "Weapon.h"

class Character : public Object
{
public:
	Character() {};

	//Add docstring for constructor!
	Character(int initHealth, float initXSpeed, float initYSpeed, SDL_Renderer* renderer=NULL, char* imagePath=NULL, float height=0, float width=0, bool isSolid=true, bool wallCollision=true) : Object(renderer, imagePath, height, width, isSolid, wallCollision)
	{
		health = initHealth;
		xSpeed = initXSpeed;
		ySpeed = initYSpeed;
	}

	//Constructor with preloaded sprite
	Character(int initHealth, float initXSpeed, float initYSpeed, Sprite initSprite, SDL_Renderer* renderer=NULL, bool isSolid=true, bool wallCollision=true) : Object(initSprite, renderer, isSolid, wallCollision)
	{
		health = initHealth;
		xSpeed = initXSpeed;
		ySpeed = initYSpeed;
	}

	~Character() {};

	void changeHealth(int healthChange) override 
	{
		health = health + healthChange;
	}

	//Setup a weapon for the character
	void initaliseWeapon(int initDamage, int projectileSpeed, int initCooldown, SDL_Renderer* renderer, char* imagePath, int height, int width);

	//Shoots the character's weapon
	void shootWeapon(std::vector<Object*> &activeObjects)
	{
		weapon.fire(activeObjects, getLocation());
	}

	void update(float deltaTime, std::vector<Object*> &activeObjects) override;

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
	void setXSpeed(float newSpeed)
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