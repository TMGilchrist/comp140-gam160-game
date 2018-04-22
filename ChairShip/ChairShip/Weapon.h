#pragma once
#include "Projectile.h"

class Weapon 
{
public:
	Weapon() {};
	Weapon(SDL_Rect location, int initDamage, int initProjectileSpeed, int initCooldown, SDL_Renderer* renderer, char* imagePath, int height, int width);
	~Weapon() {};

	//Shoot function
	void fire(std::vector<Object*> activeObjects)
	{
		//This is obviously horrible. Should add an object pool for projectiles.
		//Spawns a new projectile
		Projectile* newProjectile = new Projectile(spawnLocation, projectileSpeed, damage, activeObjects, projectileSprite, renderer);
		newProjectile->setLocation(300, 300, 10, 10);
		activeObjects.push_back(newProjectile);
		//newProjectile.move();

		std::cout << "Weapon fired!" << std::endl;

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