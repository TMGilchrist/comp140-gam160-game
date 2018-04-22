#pragma once
#include "Projectile.h"

class Weapon
{
public:
	Weapon() {};
	Weapon(SDL_Rect location, int initDamage, int speed, int initCooldown, SDL_Renderer* renderer, char* imagePath, int height, int width);
	~Weapon() {};

	//Shoot function
	void fire(std::vector<Object*> &activeObjects, SDL_Rect ownerLocation)
	{
		//This is obviously horrible. Should add an object pool for projectiles.

		updateSpawnPoint(ownerLocation);

		//Spawns a new projectile
		Projectile* newProjectile = new Projectile(spawnLocation, projectileSpeed, damage, activeObjects, projectileSprite, renderer);
		activeObjects.push_back(newProjectile); //Add to the list of active objects. Will have to be removed after it is destroyed!

		//newProjectile->move(0, -10, activeObjects); //Make the projectile travel

		std::cout << "Weapon fired!" << std::endl; //Currently weapon fires multiple times because of the way keyboard input works!

	};

	void updateSpawnPoint(SDL_Rect ownerLocation) 
	{
		//Update the projectile spawn point

		spawnLocation.x = ownerLocation.x + (ownerLocation.w / 2);
		spawnLocation.y = ownerLocation.y - 10;
	}


private:
	//Damage the weapon's projectiles will do
	int damage;

	//Speed at which the projectile moves
	int projectileSpeed;

	//The interval between shots
	int cooldown;

	//The sprite this weapon's projectiles will use
	Sprite projectileSprite;
	
	//Location to spawn new projectiles
	SDL_Rect spawnLocation;

	//Renderer
	SDL_Renderer* renderer;

};