#include "stdafx.h"
#include "Utility.h"

SDL_Texture * Utility::loadTexture(SDL_Renderer * renderer, char * file)
{
	//Load sprite to texture
	SDL_Surface* temp = SDL_LoadBMP(file);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_FreeSurface(temp);
	return texture;
}
