#include "stdafx.h"
#include "Projectile.h"

void Projectile::update(float deltaTime)
{
	move(deltaTime, 0, -velocity, activeObjects); //Add direction check to shoot in different directions
}
