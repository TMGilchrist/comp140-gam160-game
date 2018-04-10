#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(SDL_Renderer * renderer, char * filePath)
{
	texture = IMG_LoadTexture(renderer, filePath);
}
