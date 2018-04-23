#pragma once
#include "SDL.h"

class CollisionManager 
{
public:
	CollisionManager() {};
	~CollisionManager() {};

	//If two colliders are overlapping
	bool checkCollision(SDL_Rect& objectChecking, SDL_Rect& objectToCheck);

private:

};
