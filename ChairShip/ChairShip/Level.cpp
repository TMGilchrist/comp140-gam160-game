#include "stdafx.h"
#include "Level.h"

Level::Level()
{
}

Level::~Level()
{
}

void Level::drawBackground(SDL_Renderer * renderer)
{
	//Load sprite to texture
	SDL_Surface* temp = SDL_LoadBMP("../Resources/Sprites/BackgroundTemp.bmp");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_FreeSurface(temp);

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL); //<- draws texture to screen
}
