#include "stdafx.h"
#include "Projectile.h"


void Projectile::update(float deltaTime, std::vector<Object*> &activeObjects)
{
	move(deltaTime, 0, -velocity, activeObjects); //Add direction check to shoot in different directions
	//std::cout << activeObjects.size() << std::endl;
}

void Projectile::onCollide(Object * collidedWith)
{
	//std::cout << activeObjects.size() << std::endl;
	if (isActive) 
	{
		collidedWith->changeHealth(-damage);
		//removeFromVector(activeObjects); //Not working :c
  		isActive = false;
		setSprite(getBlankSprite());
	}

}
