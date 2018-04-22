#include "stdafx.h"
#include "Player.h"

void Player::update(float deltaTime, std::vector<Object*>& activeObjects)
{
	if (getHealth() <= 0)
	{
		//removeFromVector()

		setSprite(getBlankSprite());
		setIsColliderSolid(false);
	}
}
