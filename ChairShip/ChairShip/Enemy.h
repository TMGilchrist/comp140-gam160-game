#pragma once
#include "Object.h"
#include "Character.h"


class Enemy : public Character 
{
public:
	Enemy() {};
	Enemy(int initHealth, float initXSpeed, float initYSpeed, Sprite initSprite, SDL_Renderer* renderer=NULL) : Character(initHealth, initXSpeed, initYSpeed, initSprite, renderer) {};
	Enemy(int initHealth, float initXSpeed, float initYSpeed, SDL_Renderer* renderer = NULL, char* imagePath = NULL, float height = 0, float width = 0, bool isSolid = true) : Character(initHealth, initXSpeed, initYSpeed, renderer, imagePath, height, width, isSolid) {};
	~Enemy() {};

	void update(float deltaTime, std::vector<Object*> &activeObjects) override;

private:

};