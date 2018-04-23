#include "stdafx.h"
#include "Character.h"

void Character::initaliseWeapon(int initDamage, int projectileSpeed, int initCooldown, SDL_Renderer * renderer, char * imagePath, int height, int width)
{
	weapon = Weapon(getLocation(), initDamage, projectileSpeed, initCooldown, renderer, imagePath, height, width);
}

void Character::update(float deltaTime, std::vector<Object*> &activeObjects)
{
	//Base death for characters
	if (health <= 0) 
	{
		//removeFromVector()

		//Hide sprite and disable solid collision
		setSprite(getBlankSprite());
		setIsColliderSolid(false);
	}
}
