#include "stdafx.h"
#include "Weapon.h"

//Height and width are the dimensions of the weapon's projectile sprite
Weapon::Weapon(SDL_Rect location, int initDamage, int speed, int initCooldown, SDL_Renderer* initRenderer, char* imagePath, int height, int width)
{
	damage = initDamage;
	projectileSpeed = speed;
	cooldown = initCooldown;
	renderer = initRenderer;

	//Setup projectile spawn point. NOTE! The y location calculation must change from - to + depending on the direction the character wants to shoot!
	spawnLocation = location;

	spawnLocation.h = height;
	spawnLocation.w = width;

	updateSpawnPoint(location);

	//Create a sprite for the weapon's projectiles
	projectileSprite = Sprite(renderer, imagePath, height, width);
}
