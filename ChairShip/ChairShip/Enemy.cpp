#include "stdafx.h"
#include "Enemy.h"

void Enemy::update(float deltaTime, std::vector<Object*>& activeObjects)
{
	//Do movement
	move(deltaTime, 0, getYSpeed(), activeObjects);

	//When enemy dies
	if (getHealth() <= 0)
	{
		//removeFromVector()

		//Hide sprite and disable solid collision
		setSprite(getBlankSprite());
		setIsColliderSolid(false);
	}
}
