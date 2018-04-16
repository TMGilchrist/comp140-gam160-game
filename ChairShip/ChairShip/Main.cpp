// Main.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include "SDL.h"
#include "Level.h"
#include "Object.h" //Probably temp, remove later.
#include "InputManager.h"
#include "Character.h"
#include <vector>

int initaliseSDL();
void drawObjects();

//Screen dimensions
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 400;

//Game loop runs while true
bool gameRunning = true;

//The SDL renderer. Should be passed to class functions that handle their own rendering.
SDL_Renderer* renderer = NULL;

//The main game window.
SDL_Window* mainWindow = nullptr;

//Vector of the active game objects.
std::vector<Object*> activeObjects;

int main(int argc, char *argv[]) //find out wtf these arguments *do* and if they need to be here or in initaliseSDL.
{
	//Initalise InputManager
	InputManager input = InputManager();

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

	//Create new level and draw background. This is temp. Will be replaced.
	Level mainLevel = Level(renderer, "../Resources/Sprites/BackgroundTemp.bmp");

	//Instantiate player character and add to active objects
	Character* shipTest = new Character(10, 100, 100, renderer, "../Resources/Sprites/ShipTemp.png", 67, 67);
	activeObjects.push_back(shipTest);

shipTest->initaliseWeapon(1, 200, 1, renderer, "../Resources/Sprites/ProjectileTemp.png", 10, 10);

	//Move player to center of screen
	shipTest->setLocation(200, 200);

	//Instantiate test "enemy" character
	Character* enemyTest = new Character(10, 100, 100, renderer, "../Resources/Sprites/ShipTemp.png", 67, 67);
	activeObjects.push_back(enemyTest);

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

		//Check inputs. Could be moved to a seperate function for neatness?
		if (input.isPressed(SDLK_w))
		{
			shipTest->move(deltaTime, 0, -enemyTest->getYSpeed(), activeObjects);
		}

		if (input.isPressed(SDLK_a))
		{
			shipTest->move(deltaTime, -enemyTest->getXSpeed(), 0, activeObjects);
		}

		if (input.isPressed(SDLK_s))
		{
			shipTest->move(deltaTime, 0, enemyTest->getYSpeed(), activeObjects);
		}

		if (input.isPressed(SDLK_d))
		{
			shipTest->move(deltaTime, enemyTest->getXSpeed(), 0, activeObjects);
		}

		if (input.isPressed(SDLK_SPACE))
		{
			//Call shipTest->weapon->fire();
		}


		//std::cout << deltaTime << std::endl;

		//Update screen
		SDL_RenderClear(renderer);
		mainLevel.drawBackground(renderer);
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
	mainWindow = SDL_CreateWindow("Main Screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN);
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

//Render all active objects
void drawObjects()
{
	for each (Object* object in activeObjects)
	{
		object->drawSelf(renderer);
	}
}


