#include "stdafx.h"
#include "Character.h"

void Character::initaliseWeapon(int initDamage, int projectileSpeed, int initCooldown, SDL_Renderer * renderer, char * imagePath, int height, int width)
{
	//SDL_Rect weaponLocation = getLocation(); //Get the character's location as a base
	//weaponLocation.y -= weaponLocation.h;
	weapon = Weapon(getLocation(), initDamage, projectileSpeed, initCooldown, renderer, imagePath, height, width);
}

void Character::update(float deltaTime)
{
	if (health <= 0) 
	{
		std::cout << "dead!" << std::endl;
		//removeFromVector()
	}
}
