#include "stdafx.h"
#include "CollisionManager.h"

bool CollisionManager::checkCollision(SDL_Rect& objectChecking, SDL_Rect& objectToCheck)
{
	return SDL_HasIntersection(&objectChecking, &objectToCheck);
}
