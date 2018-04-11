// Main.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include "SDL.h"
#include "Level.h"
#include "Object.h" //Probably temp, remove later.

int initaliseSDL();
void handleInput(Object shipTest, float deltaTime);

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

const int X_VELOCITY = 100; //Temporarily doing velocity here.
const int Y_VELOCITY = 100;

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


	Object shipTest = Object(renderer, "../Resources/Sprites/ShipTemp.png", 67, 67);

	shipTest.setX(200);
	shipTest.setY(200);

	//mainLevel.drawBackground(renderer);
	//shipTest.drawSelf(renderer);

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

				//Escape key pressed (could change to another switch statement for more keys)
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						gameRunning = false;
						break;
					}
					/*
					//Movement input.
					case SDLK_w:
						//shipTest.move(0, -2);
						shipTest.moveY(deltaTime, -Y_VELOCITY);
						break;
					case SDLK_a:
						//shipTest.move(-2, 0);
						shipTest.moveX(deltaTime, -X_VELOCITY);
						break;
					case SDLK_s:
						//shipTest.move(0, 2);
						shipTest.moveY(deltaTime, Y_VELOCITY);
						break;
					case SDLK_d:
						//shipTest.move(2, 0);
						shipTest.moveX(deltaTime, X_VELOCITY);
						break;						
					}*/
									
				break;
			}

			handleInput(shipTest, deltaTime);

		}

		//Update screen
		SDL_RenderClear(renderer);
		mainLevel.drawBackground(renderer);
		shipTest.drawSelf(renderer);
		SDL_RenderPresent(renderer);

		//std::cout << deltaTime << std::endl;
		std::cout << shipTest.getX() <<std::endl;
		std::cout << shipTest.getY() << std::endl;
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

void handleInput(Object shipTest, float deltaTime) 
{
	const Uint8* keystate = SDL_GetKeyboardState(NULL);

	//continuous-response keys
	if (keystate[SDLK_LEFT])
	{
		shipTest.moveX(deltaTime, -X_VELOCITY);
	}
	if (keystate[SDLK_RIGHT])
	{
		shipTest.moveX(deltaTime, X_VELOCITY);
	}
	if (keystate[SDLK_UP])
	{
		shipTest.moveX(deltaTime, -Y_VELOCITY);
	}
	if (keystate[SDLK_DOWN])
	{
		shipTest.moveY(deltaTime, Y_VELOCITY);

	}

}