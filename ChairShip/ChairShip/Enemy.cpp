#include "stdafx.h"
#include "Enemy.h"

void Enemy::update(float deltaTime, std::vector<Object*>& activeObjects)
{
	move(deltaTime, 0, getYSpeed(), activeObjects);

	if (getHealth() <= 0)
	{
		//std::cout << "dead!" << std::endl;
		//removeFromVector()

		setSprite(getBlankSprite());
		setIsColliderSolid(false);
	}
}
