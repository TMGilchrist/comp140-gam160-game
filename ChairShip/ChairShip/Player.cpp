#include "stdafx.h"
#include "Player.h"

void Player::update(float deltaTime, std::vector<Object*>& activeObjects)
{
	//When the player dies
	if (getHealth() <= 0)
	{
		//removeFromVector()

		//Hide player and disable solid collisions
		setSprite(getBlankSprite());
		setIsColliderSolid(false);
	}
}
