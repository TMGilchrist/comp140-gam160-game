#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(SDL_Rect location, int initDamage, int initProjectileSpeed, int initCooldown, SDL_Renderer* initRenderer, char* imagePath, int height, int width)
{
	damage = initDamage;
	projectileSpeed = initProjectileSpeed;
	cooldown = initCooldown;
	renderer = initRenderer;
	spawnLocation = location;

	//Create a sprite for the weapon's projectiles
	projectileSprite = Sprite(renderer, imagePath, height, width);
}
