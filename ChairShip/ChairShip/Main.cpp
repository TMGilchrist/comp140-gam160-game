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
		SDL_Quit();
		return -1;
	}

	//load bitmap to temp surface
	//SDL_Surface* temp = SDL_LoadBMP("sdl_logo.bmp");

	// convert bitmap to display format
	//SDL_Surface* bg = SDL_DisplayFormat(temp);

	// free the temp surface
	//SDL_FreeSurface(temp);


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

		//draw the background
		//SDL_BlitSurface(bg, NULL, screen, NULL);

		//update the screen
		//SDL_UpdateRect(screen, 0, 0, 0, 0);

	}

	//free the background surface */
	//SDL_FreeSurface(bg);

	//Close window
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
	return 0;
}

