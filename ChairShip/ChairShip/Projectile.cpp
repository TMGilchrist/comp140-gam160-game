#include "stdafx.h"
#include "Projectile.h"


void Projectile::update(float deltaTime)
{
	move(deltaTime, 0, -velocity, activeObjects); //Add direction check to shoot in different directions
}

void Projectile::onCollide(Object * collidedWith)
{
	if (isActive) 
	{
		std::cout << "Collisions happening!" << std::endl;
		std::cout << damage << std::endl;
		collidedWith->changeHealth(-damage);
		removeFromVector(activeObjects);
  		isActive = false;
	}

}
