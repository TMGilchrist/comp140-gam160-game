#include "stdafx.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager(SDL_Renderer* initRenderer)
{
	//Init sprites
	enemySprite = Sprite(initRenderer, "../Resources/Sprites/EnemyShip.png", 55, 55);
	renderer = initRenderer;
}

void EnemyManager::spawnEnemy(std::vector<Object*> &activeObjects, int xPos, int yPos=0)
{
	//Create a new enemy
	Enemy* newEnemy = new Enemy(4, 100, 50, enemySprite, renderer); //Construction data could be moved to constructor, or better, a function to create template enemies.
	newEnemy->setLocation(xPos, yPos);
	activeObjects.push_back(newEnemy);
	//newEnemy.addToVector(activeObjects);

}
