#include "stdafx.h"
#include "Projectile.h"


void Projectile::update(float deltaTime, std::vector<Object*> &activeObjects)
{
	move(deltaTime, 0, -velocity, activeObjects); //Add direction check to shoot in different directions
}

void Projectile::onCollide(Object * collidedWith)
{
	if (isActive) 
	{
		//Cause damage (currently damages the projectile's owner as well)
		collidedWith->changeHealth(-damage);

		//removeFromVector(activeObjects); //Not working :c

		//Disable projectile and hide it
  		isActive = false;
		setSprite(getBlankSprite());
	}

}
