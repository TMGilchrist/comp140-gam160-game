#include "stdafx.h"
#include "PlayerController.h"


void PlayerController::control(Character* player, InputManager &input, float deltaTime, std::vector<Object*> &activeObjects)
{	
	//Disable accelerometer input for testing 
	bool manualOverride = true; 

	//std::cout << "control!" << std::endl;

	//Use controller input
	if (controller.getConnected() && manualOverride != true) 
	{
		//Update accelerometer values
		controller.getData();

		//Debug printing
		std::cout << controller.getX() << std::endl;
		std::cout << controller.getY() << std::endl;
		std::cout << controller.getZ() << std::endl;
		std::cout << std::endl;


		/*
		Movement based on accelerometer readings. 

		Important to note: 
		Accelerometer Y-axis is used to calculate player's x movement (side to side).
		Accelerometer Z-axis used to calculate player's y movement (up and down).															
		*/
																	 
		//Move left
		if (controller.getY() > 0.3)
		{
			player->move(deltaTime, -player->getXSpeed(), 0, activeObjects);
		}

		//Move right
		else if (controller.getY() < -0.3)
		{
			player->move(deltaTime, player->getXSpeed(), 0, activeObjects);
		}

		//Move down
		if (controller.getZ() < -3)
		{
			player->move(deltaTime, 0, player->getYSpeed(), activeObjects);
		}

		//Move up
		if (controller.getZ() > -1)
		{
			player->move(deltaTime, 0, -player->getYSpeed(), activeObjects);
		}
	}

	//use keyboard input
	else
	{
		//Check inputs. Could be moved to a seperate function for neatness?
		if (input.isPressed(SDLK_w))
		{
			player->move(deltaTime, 0, -player->getYSpeed(), activeObjects);
		}

		if (input.isPressed(SDLK_a))
		{
			player->move(deltaTime, -player->getXSpeed(), 0, activeObjects);
		}

		if (input.isPressed(SDLK_s))
		{
			player->move(deltaTime, 0, player->getYSpeed(), activeObjects);
		}

		if (input.isPressed(SDLK_d))
		{
			player->move(deltaTime, player->getXSpeed(), 0, activeObjects);
		}

		//This will have to be added to controller input as well!
		if (input.isPressed(SDLK_SPACE))
		{
			player->shootWeapon(activeObjects);
		}
	}


}
