#include "stdafx.h"
#include "Level.h"
#include "Utility.h"

Level::Level()
{
}

Level::Level(SDL_Renderer * renderer, char* imagePath)
{
	Utility utility;
	background = utility.loadTexture(renderer, imagePath);
}

Level::~Level()
{
	//delete background; FIX THIS??
}

void Level::drawBackground(SDL_Renderer * renderer)//SDL_Texture* texture)
{
	//Add texture to renderer
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, NULL, NULL); //<- draws texture to screen
}
