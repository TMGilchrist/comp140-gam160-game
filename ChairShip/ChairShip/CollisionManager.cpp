#include "stdafx.h"
#include "CollisionManager.h"

bool CollisionManager::checkCollision(SDL_Rect& objectChecking, SDL_Rect& objectToCheck)
{
	//Check to see if two collision boxes are overlapping
	return SDL_HasIntersection(&objectChecking, &objectToCheck);
}
