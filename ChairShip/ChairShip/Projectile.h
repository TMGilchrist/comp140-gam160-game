#pragma once
#include "Object.h"

class Projectile : public Object
{
public:
	Projectile() {};
	Projectile(int initSpeed, int initDamage, SDL_Renderer* renderer = NULL, char* imagePath = NULL, float height = 0, float width = 0) : Object(renderer, imagePath, height, width) {};

	//Create projectile with pre-loaded sprite
	Projectile(SDL_Rect location, int initSpeed, int initDamage, std::vector<Object*> activeObjects, Sprite initSprite, SDL_Renderer* renderer) : Object(initSprite, renderer)
	{
		
		setSprite(initSprite);
		speed = initSpeed;
		damage = initDamage;

		setLocation(location.x, location.y, location.h, location.w);

		drawSelf(renderer);
	};

	~Projectile() {};

private:
	//Movement speed
	int speed;

	//Damage dealt on collision
	int damage;

};