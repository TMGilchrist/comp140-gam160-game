#pragma once
#include "SDL.h"

class CollisionManager 
{
public:
	CollisionManager() {};
	~CollisionManager() {};

	bool checkCollision(SDL_Rect* objectChecking, SDL_Rect* objectToCheck);



private:

};
