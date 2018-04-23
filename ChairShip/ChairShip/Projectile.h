#pragma once
#include "Object.h"

class Projectile : public Object
{
public:
	Projectile() {};
	//Constructor to load sprite from file
	Projectile(int initSpeed, int initDamage, SDL_Renderer* renderer = NULL, char* imagePath = NULL, float height = 0, float width = 0, bool isSolid=false, bool wallCollision=false)
																												 : Object(renderer, imagePath, height, width, isSolid, wallCollision) {};

	//Create projectile with pre-loaded sprite
	Projectile(SDL_Rect location, int projectileSpeed, int initDamage, std::vector<Object*> &objects, Sprite initSprite, SDL_Renderer* renderer, bool isSolid=false, bool wallCollision=false) 
																																		: Object(initSprite, renderer, isSolid, wallCollision)
	{
		setSprite(initSprite);
		velocity = projectileSpeed;
		damage = initDamage;
		isActive = false;
		activeObjects = objects;

		setLocation(location.x, location.y, location.h, location.w);	
	};

	~Projectile() {};

	//Update called every tick.
	void update(float deltaTime, std::vector<Object*> &activeObjects) override;
	
	//Called when colliding with another object.
	void onCollide(Object* collidedWith) override;


	//Setters and getters
	void setIsActive(bool active) 
	{
		isActive = active;
	}
	void setActiveObjects(std::vector<Object*> &objects)
	{
		activeObjects = objects;
	}

private:
	//Movement speed
	int velocity;

	//Damage dealt on collision
	int damage;

	//If the projectile is active in game
	bool isActive;

	//Active objects. Probably don't need this here.
	std::vector<Object*> activeObjects;
};