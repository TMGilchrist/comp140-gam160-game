// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SDL.h"

//Screen dimensions
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 400;

//Game loop runs while true
bool gameRunning = true;


int main(int argc, char *argv[])
{
	SDL_Window* mainWindow = nullptr;

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
	SDL_Renderer* renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	//Load sprite to texture
	SDL_Surface* temp = SDL_LoadBMP("../Resources/Sprites/TestSpriteBit.bmp");	
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_FreeSurface(temp);

	//SDL_SetRenderDrawColor(renderer, 255, 000, 000, 000);
	//SDL_RenderFillRect(renderer, spriteArea);



	SDL_Event event;

	/*------------------------
	      Main game loop 
	------------------------*/
	while (gameRunning)
	{
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
		SDL_RenderClear(renderer);
		//SDL_RenderCopy(renderer, texture, NULL, NULL); //<- draws texture to screen
		SDL_RenderPresent(renderer);
	}


	//Close window
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
	return 0;
}

