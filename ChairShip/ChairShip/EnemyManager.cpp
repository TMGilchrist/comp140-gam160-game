#include "stdafx.h"
#include "EnemyManager.h"

EnemyManager::EnemyManager(SDL_Renderer* initRenderer)
{
	//Init sprites
	enemySprite = Sprite(initRenderer, "../Resources/Sprites/EnemyShip.png", 55, 55);
	renderer = initRenderer;
}

void EnemyManager::spawnEnemy(std::vector<Object*> &activeObjects)
{
	Enemy newEnemy = Enemy(4, 100, 100, enemySprite, renderer);
	newEnemy.setLocation(200, 0);
	newEnemy.addToVector(activeObjects);

	//newEnemy.drawSelf(renderer);

}
