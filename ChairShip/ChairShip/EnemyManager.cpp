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
	Enemy* newEnemy = new Enemy(4, 100, 100, enemySprite, renderer);
	newEnemy->setLocation(xPos, yPos);
	activeObjects.push_back(newEnemy);
	//newEnemy.addToVector(activeObjects);

}
