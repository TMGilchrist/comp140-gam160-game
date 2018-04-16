#pragma once
#include "Projectile.h"

class Weapon 
{
public:
	Weapon() {};
	Weapon(SDL_Rect location, int initDamage, int initProjectileSpeed, int initCooldown, SDL_Renderer* renderer, char* imagePath, int height, int width);
	~Weapon() {};

	//Shoot function
	void fire()
	{
		//This is obviously horrible. Should add an object pool for projectiles.
		//Spawns a new projectile
		//Projectile newProjectile = Projectile(spawnLocation.x, spawnLocation.y, damage, projectileSpeed, projectileSprite, renderer);
		//newProjectile.move();

	};


private:
	//Damage the weapon's projectiles will do
	int damage;

	//Speed at which the projectile moves
	int projectileSpeed;

	//The interval between shots
	int cooldown;

	//Projectile projectile;

	//The sprite this weapon's projectiles will use
	Sprite projectileSprite;
	
	//Location to spawn new projectiles
	SDL_Rect spawnLocation;

	SDL_Renderer* renderer;

};