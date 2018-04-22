#include "stdafx.h"
#include "Character.h"

void Character::initaliseWeapon(int initDamage, int initProjectileSpeed, int initCooldown, SDL_Renderer * renderer, char * imagePath, int height, int width)
{
	SDL_Rect weaponLocation = getLocation();
	weaponLocation.y -= weaponLocation.h;
	weapon = Weapon(weaponLocation, initDamage, initProjectileSpeed, initCooldown, renderer, imagePath, height, width);
}
