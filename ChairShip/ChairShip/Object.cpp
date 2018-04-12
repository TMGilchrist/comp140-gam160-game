#include "stdafx.h"
#include "Object.h"
#include "Utility.h"

//Constructor
Object::Object(SDL_Renderer * renderer, char* imagePath, float height, float width)
{
	sprite = Sprite(renderer, imagePath, height, width);
	x = 0;
	y = 0;
	updateLocation();

	collisionBox = CollisionBox(0, 0, height, width, false);
}

//Constructor specifying if collisionBox is solid (kinda redundant...could just be true?)
Object::Object(SDL_Renderer * renderer, char * imagePath, float height, float width, bool isSolid)
{
	sprite = Sprite(renderer, imagePath, height, width);
	x = 0;
	y = 0;
	updateLocation();

	collisionBox = CollisionBox(0, 0, height, width, isSolid);
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

//Should move the sprite getters into a sprite update function.
void Object::updateLocation()
{
	//Update object location
	locationRect.x = x;
	locationRect.y = y;
	locationRect.h = sprite.getHeight();
	locationRect.w = sprite.getWidth();

	//Update collisionBox
	collisionBox.setX(x);
	collisionBox.setY(y);
	collisionBox.setHeight(sprite.getHeight());
	collisionBox.setWidth(sprite.getWidth());
}

