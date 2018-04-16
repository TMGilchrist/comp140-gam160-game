#include "stdafx.h"
#include "Weapon.h"

Weapon::Weapon(SDL_Rect location, int initDamage, int initProjectileSpeed, int initCooldown, SDL_Renderer* initRenderer, char* imagePath, int height, int width)
{
	damage = initDamage;
	projectileSpeed = initProjectileSpeed;
	cooldown = initCooldown;
	renderer = initRenderer;
	spawnLocation = location;

	projectileSprite = Sprite(renderer, imagePath, height, width);

	//Initialise projectile
	//projectile = Projectile(spawnLocation, projectileSpeed, initDamage, projectileSprite, renderer);
}
