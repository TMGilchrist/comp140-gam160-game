#pragma once
#include "Sprite.h"
#include "Enemy.h"

class EnemyManager 
{
public:
	EnemyManager() {};
	EnemyManager(SDL_Renderer* initRenderer);
	~EnemyManager() {};

	//Spawn a new enemy at a location
	void spawnEnemy(std::vector<Object*> &objects, int xPos, int yPos);


private:
	//The sprite to use for enemy
	Sprite enemySprite;

	//Renderer
	SDL_Renderer* renderer;


};
