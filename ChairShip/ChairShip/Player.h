#pragma once

#include "Character.h"

class Player : public Character
{
public:
	Player() {};
	//Constructor using preloaded sprite. (Note: no option to set isSolid. Could be added)
	Player(int initHealth, float initXSpeed, float initYSpeed, Sprite initSprite, SDL_Renderer* renderer = NULL) : Character(initHealth, initXSpeed, initYSpeed, initSprite, renderer) {};
	
	//Constructor to load sprite from file
	Player(int initHealth, float initXSpeed, float initYSpeed, SDL_Renderer* renderer = NULL, char* imagePath = NULL, float height = 0, float width = 0, bool isSolid = true) 
																	             : Character(initHealth, initXSpeed, initYSpeed, renderer, imagePath, height, width, isSolid) {};
	~Player() {};

	//Update called every tick
	void update(float deltaTime, std::vector<Object*> &activeObjects) override;

private:
	//abilities and blah

};
