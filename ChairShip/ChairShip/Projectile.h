#pragma once
#include "Object.h"

class Projectile : public Object
{
public:
	Projectile() {};
	Projectile(int initSpeed, int initDamage, SDL_Renderer* renderer = NULL, char* imagePath = NULL, float height = 0, float width = 0, bool isSolid=false) : Object(renderer, imagePath, height, width, isSolid) {};

	//Create projectile with pre-loaded sprite
	Projectile(SDL_Rect location, int projectileSpeed, int initDamage, std::vector<Object*> objects, Sprite initSprite, SDL_Renderer* renderer) : Object(initSprite, renderer) 
	{
		setSprite(initSprite);
		velocity = projectileSpeed;
		damage = initDamage;
		activeObjects = objects;

		setLocation(location.x, location.y, location.h, location.w);	
	};

	~Projectile() {};

	//Update method
	void update(float deltaTime) override;
	void onCollide(Object* collidedWith) override;

private:
	//Movement speed
	int velocity;

	//Damage dealt on collision
	int damage;

	std::vector<Object*> activeObjects;
};