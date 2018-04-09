// Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "SDL.h"

const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 400;

int main(int argc, char *argv[])
{
	SDL_Window* mainWindow = nullptr;

	/* initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Cannot initalise SDL " << SDL_GetError() << std::endl;
		return -1;
	}

	mainWindow = SDL_CreateWindow("Main Screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN);

	if (mainWindow == nullptr) 
	{
		std::cout << "Cannot create window " << SDL_GetError() << std::endl;
		SDL_QUIT;
		return -1;
	}

	SDL_Event event;
	int gameover = 0;

	//Main game loop
	while (!gameover)
	{
		//Check for SDL events
		if (SDL_PollEvent(&event))
		{
			//Events found
			switch (event.type)
			{
				//Window closed
				case SDL_QUIT:
					gameover = 1;
					break;

				//Escape key pressed
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						gameover = 1;
						break;
					}

				break;
			}
		}
	}



}

