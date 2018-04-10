#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(SDL_Renderer * renderer, char * filePath, float initHeight, float initWidth)
{
	//Load image as texture
	texture = IMG_LoadTexture(renderer, filePath);
	height = initHeight;
	width = initWidth;
}
