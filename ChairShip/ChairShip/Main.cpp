// Main.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include "SDL.h"
#include "Level.h"
//#include "Object.h" //Probably temp, remove later.
#include "InputManager.h"
#include "Character.h"
#include "SerialInterface.h"
#include "PlayerController.h"
#include "EnemyManager.h"
#include "Enemy.h" //Should be removed if EnemyManger if fixed
#include "globals.h"
#include <vector>
#include <time.h>


int initaliseSDL();
void drawObjects();
void updateObjects(float deltaTime);

//Game loop runs while true
bool gameRunning = true;

//The SDL renderer. Should be passed to class functions that handle their own rendering.
SDL_Renderer* renderer = NULL;

//The main game window.
SDL_Window* mainWindow = nullptr;

//Vector of the active game objects.
std::vector<Object*> activeObjects;

int main(int argc, char *argv[])
{
	bool inDevelopMode = true;

	//Initalise random seed
	std::srand(time(NULL));

	//Initalise enemy spawn timings
	int enemySpawnDelay = 3000;
	int spawnDelayStart = 0;

	//Initialise times
	float lastTime = 0;
	float tickTime = 0;
	float deltaTime = 0;

	//Initalise the SDL components
	if (initaliseSDL() < 0)
	{
		std::cout << "SDL initalisation failed." << std::endl;
		return -1;
	}

	//Initalise InputManager
	InputManager input = InputManager();

	//Initalise PlayerController (containing the serialInterface)
	PlayerController controller = PlayerController();

	//Initalise enemy manager
	EnemyManager enemies = EnemyManager(renderer);


	//Create new level and draw background. This is temp. Will be replaced.
	Level mainLevel = Level(renderer, "../Resources/Sprites/BackgroundTemp.bmp");

	//Instantiate player character and add to active objects
	Player* shipTest = new Player(10, 200, 200, renderer, "../Resources/Sprites/ShipTemp.png", 67, 67);
	activeObjects.push_back(shipTest);

	if (inDevelopMode) 
	{
		//Move player to center of screen
		shipTest->setLocation(200, 300);
	}

	else 
	{
		//Change player speed for bigger screen size
		shipTest->setYSpeed(400);
		shipTest->setXSpeed(300);

		//Move player to center of screen
		shipTest->setLocation(960, 540);
	}

	//Add a weapon to the player
	shipTest->initaliseWeapon(1, 200, 250, renderer, "../Resources/Sprites/ProjectileTemp.png", 10, 10);



	//Current sdl event
	SDL_Event event;

	/*------------------------
	      Main game loop 
	------------------------*/
	while (gameRunning)
	{
		//Calculate deltaTime
		lastTime = tickTime;
		tickTime = SDL_GetTicks();
		deltaTime = (tickTime - lastTime);

		//Check for SDL events
		if (SDL_PollEvent(&event))
		{
			//Events found
			switch (event.type)
			{
				//Window closed
				case SDL_QUIT:
					gameRunning = false;
					break;

				case SDL_KEYDOWN:
					//Update inputManager
					input.manageKeyboardEvents(event);

					//Check individual keys by code
					switch (event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							gameRunning = false;
							break;
					}

				case SDL_KEYUP:
					//Update inputManager
					input.manageKeyboardEvents(event);
					break;

				break;
			}

		}

		//Check for input
		controller.control(shipTest, input, deltaTime, activeObjects);

		//Spawn enemies after a delay
		if (((SDL_GetTicks() - spawnDelayStart)) >= enemySpawnDelay) 
		{
			//Spawn new enemy in a random location along the top of the screen.
			enemies.spawnEnemy(activeObjects, rand() % global::SCREEN_WIDTH-80 + 80, 0); //(Screen width - 80) + 80 to make sure the sprites don't get stuck off the screen.

			spawnDelayStart = SDL_GetTicks();
		}


		//Update screen
		SDL_RenderClear(renderer);
		mainLevel.drawBackground(renderer);
		updateObjects(deltaTime);
		drawObjects();
		SDL_RenderPresent(renderer);
	}


	//Close window
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
	mainLevel.~Level();
	return 0;
}


//Set up the SDL components
int initaliseSDL() 
{
	//initialise SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Cannot initalise SDL " << SDL_GetError() << std::endl;
		return -1;
	}

	//Initalise the main window
	mainWindow = SDL_CreateWindow("Main Screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, global::SCREEN_WIDTH, global::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (mainWindow == nullptr)
	{
		std::cout << "Cannot create window " << SDL_GetError() << std::endl;
		SDL_Quit();
		return -1;
	}

	//Initalise renderer
	renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	if (renderer == NULL)
	{
		std::cout << "Cannot initalise SDL" << SDL_GetError << std::endl;
		SDL_Quit();
		return -1;
	}

	return 0;
}

//Call the update function for all active objects
void updateObjects(float deltaTime) 
{
	for each (Object* object in activeObjects) 
	{
		object->update(deltaTime, activeObjects);
	}
}

//Render all active objects
void drawObjects()
{
	for each (Object* object in activeObjects)
	{
		object->drawSelf(renderer);
	}
}


