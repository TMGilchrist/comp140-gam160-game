// Main.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include "SDL.h"
#include "Level.h"
#include "Object.h" //Probably temp, remove later.

int initaliseSDL();

//Screen dimensions
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 400;

//Game loop runs while true
bool gameRunning = true;

//The SDL renderer. Should be passed to class functions that handle their own rendering.
SDL_Renderer* renderer = NULL;

//The main game window.
SDL_Window* mainWindow = nullptr;

//Sprite destination rectangle. Will be moved later.
SDL_Rect destRect;


int main(int argc, char *argv[]) //find out wtf these arguments *do* and if they need to be here or in initaliseSDL.
{
	destRect.x = 0;
	destRect.y = 0;
	destRect.h = 67;
	destRect.w = 67;

	//Init times
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
	mainLevel.drawBackground(renderer);

	Object shipTest = Object(renderer, "../Resources/Sprites/ShipTemp.png");
	shipTest.drawSelf(renderer, &destRect);

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
		deltaTime = (tickTime - lastTime) * 1000;

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

				//Escape key pressed (could change to another switch statement for more keys)
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						gameRunning = false;
						break;
					}

				break;
			}
		}

		//Update screen
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
