#pragma once
#include "Sprite.h"
#include "Enemy.h"

class EnemyManager 
{
public:
	EnemyManager() {};
	EnemyManager(SDL_Renderer* initRenderer);
	~EnemyManager() {};

	void spawnEnemy(std::vector<Object*> &objects, int xPos, int yPos);


private:
	//The sprite to use for enemy1
	Sprite enemySprite;

	SDL_Renderer* renderer;


};
