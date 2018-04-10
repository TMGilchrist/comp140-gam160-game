#include "stdafx.h"
#include "Object.h"
#include "Utility.h"

Object::Object(SDL_Renderer * renderer, char* imagePath, float height, float width)
{
	sprite = Sprite(renderer, imagePath, height, width);
	x = 0;
	y = 0;
	updateLocation();
}

void Object::drawSelf(SDL_Renderer * renderer)
{
	//Add texture to renderer
	updateLocation();
	SDL_RenderCopy(renderer, sprite.getTexture(), NULL, &locationRect);
}

void Object::drawSelf(SDL_Renderer * renderer, SDL_Rect * sourceRect)
{
	//Add texture to renderer
	updateLocation();
	SDL_RenderCopy(renderer, sprite.getTexture(), sourceRect, &locationRect);
}

void Object::updateLocation()
{
	//Update rectangle
	locationRect.x = x;
	locationRect.y = y;
	locationRect.h = sprite.getHeight();
	locationRect.w = sprite.getWidth();
}

void Object::move(float newX, float newY)

{
	//add velocity to position
	x = x + newX;
	y = y + newY;
	//locationRect.x = newX;
	//locationRect.y = newY;
	//locationRect.h = sprite.getHeight();
	//locationRect.w = sprite.getWidth();
}
