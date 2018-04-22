#include "stdafx.h"
#include "Enemy.h"

void Enemy::update(float deltaTime, std::vector<Object*>& activeObjects)
{
	move(deltaTime, 0, getYSpeed(), activeObjects);
}
