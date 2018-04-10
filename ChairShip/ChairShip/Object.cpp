#include "stdafx.h"
#include "Object.h"
#include "Utility.h"

Object::Object(SDL_Renderer * renderer, char* imagePath)
{
	sprite = Sprite(renderer, imagePath);
}

void Object::drawSelf(SDL_Renderer * renderer)
{
	//Add texture to renderer
	//SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, sprite.getTexture(), NULL, NULL);
}

void Object::drawSelf(SDL_Renderer * renderer, SDL_Rect * destinationRect)
{
	//Add texture to renderer
	//SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, sprite.getTexture(), NULL, destinationRect);
}

void Object::drawSelf(SDL_Renderer * renderer, SDL_Rect * sourceRect, SDL_Rect * destinationRect)
{
	//Add texture to renderer
	//SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, sprite.getTexture(), sourceRect, destinationRect);
}
