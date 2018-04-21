#include "stdafx.h"
#include "PlayerController.h"


void PlayerController::control(Character* player, InputManager &input, float deltaTime, std::vector<Object*> activeObjects)
{
	/*
	//Check inputs. Could be moved to a seperate function for neatness?
	if (input.isPressed(SDLK_w))
	{
		player->move(deltaTime, 0, -enemyTest->getYSpeed(), activeObjects);
	}

	if (input.isPressed(SDLK_a))
	{
		player->move(deltaTime, -enemyTest->getXSpeed(), 0, activeObjects);
	}

	if (input.isPressed(SDLK_s))
	{
		player->move(deltaTime, 0, enemyTest->getYSpeed(), activeObjects);
	}

	if (input.isPressed(SDLK_d))
	{
		player->move(deltaTime, enemyTest->getXSpeed(), 0, activeObjects);
	}

	if (input.isPressed(SDLK_SPACE))
	{
		//Call &&player->weapon->fire();
	}
	*/

	

	controller.getData();

	//std::cout << controller.getX() << std::endl;
	//std::cout << controller.getY() << std::endl;
	//std::cout << controller.getZ() << std::endl;
	//std::cout << std::endl;

	
	if (controller.getX() > 3) 
	{
		//player->move(deltaTime, player->getXSpeed(), 0, activeObjects);
	}

	else if (controller.getX() < -3)
	{
		//player->move(deltaTime, -player->getXSpeed(), 0, activeObjects);
	}

	if (controller.getZ() < -3) 
	{
		player->move(deltaTime, 0, player->getYSpeed(), activeObjects);
	}

	if (controller.getZ() > -1)
	{
		player->move(deltaTime, 0, -player->getYSpeed(), activeObjects);
	}

}
