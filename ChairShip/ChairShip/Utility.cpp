#include "stdafx.h"
#include "Utility.h"
#include <SDL_image.h>

SDL_Texture * Utility::loadTexture(SDL_Renderer * renderer, char * file)
{
	//Load a texture from file
	SDL_Texture* texture = IMG_LoadTexture(renderer, file);
	return texture;
}
