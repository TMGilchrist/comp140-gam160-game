#pragma once
#include "Object.h"
#include "Character.h"


class Enemy : public Character 
{
public:
	Enemy() {};
	//Constructor to use a preloaded sprite
	Enemy(int initHealth, float initXSpeed, float initYSpeed, Sprite initSprite, SDL_Renderer* renderer=NULL, bool isSolid=false, bool wallCollision=false)
															  : Character(initHealth, initXSpeed, initYSpeed, initSprite, renderer, isSolid, wallCollision) {};

	//Constructor to create sprite from file
	Enemy(int initHealth, float initXSpeed, float initYSpeed, SDL_Renderer* renderer = NULL, char* imagePath = NULL, float height = 0, float width = 0, 
																									       bool isSolid=false, bool wallCollision = false) 
											   : Character(initHealth, initXSpeed, initYSpeed, renderer, imagePath, height, width, isSolid, wallCollision) {};
	~Enemy() {};

	//Called every tick
	void update(float deltaTime, std::vector<Object*> &activeObjects) override;

private:

};