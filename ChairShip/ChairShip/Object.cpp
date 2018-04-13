#include "stdafx.h"
#include "Object.h"
#include "Utility.h"
#include <vector>

//Constructor ( should probably add ability to customise collision box at some point)
Object::Object(SDL_Renderer * renderer, char* imagePath, float height, float width)
{
	sprite = Sprite(renderer, imagePath, height, width);
	x = 0;
	y = 0;
	updateLocation();

	collisionBox = CollisionBox(0, 0, height, width, false);
	collisionManager = CollisionManager();
}

//Constructor specifying if collisionBox is solid (kinda redundant...could just be true?)
Object::Object(SDL_Renderer * renderer, char * imagePath, float height, float width, bool isSolid)
{
	sprite = Sprite(renderer, imagePath, height, width);
	x = 0;
	y = 0;
	updateLocation();

	collisionBox = CollisionBox(0, 0, height, width, isSolid);
	collisionManager = CollisionManager();
}

//Update location and render sprite
void Object::drawSelf(SDL_Renderer * renderer)
{
	//Add texture to renderer
	//updateLocation();
	SDL_RenderCopy(renderer, sprite.getTexture(), NULL, &locationRect);
}

void Object::drawSelf(SDL_Renderer * renderer, SDL_Rect * sourceRect)
{
	//Add texture to renderer
	updateLocation();
	SDL_RenderCopy(renderer, sprite.getTexture(), sourceRect, &locationRect);
}

//Should move the sprite getters into a sprite update function. Probably redundant now.
void Object::updateLocation()
{
	
	//Update object location
	locationRect.x = x;
	locationRect.y = y;
	locationRect.h = sprite.getHeight();
	locationRect.w = sprite.getWidth();

	/*
	//Update collisionBox
	collisionBox.getCollider()->x = x;
	collisionBox.getCollider()->y = y;
	collisionBox.getCollider()->h = sprite.getHeight();
	collisionBox.getCollider()->w = sprite.getWidth();*/

}

//Check collision in new desitination. Move to destination if no collisions are found.
void Object::updateLocation(float deltaTime, float xVelocity, float yVelocity, std::vector<Object*> activeObjects)
{
	bool isCollided = false;

	//Location the object wants to move to
	float destX = x + xVelocity * (deltaTime / 1000);
	float destY = y + yVelocity *(deltaTime / 1000);
	
	//Update the collision box to match the new destination
	collisionBox.getCollider()->x = destX;
	collisionBox.getCollider()->y = destY;

	//Check collision with each other active object
	for each (Object* object in activeObjects)
	{
		if (object != this) 
		{
			//If there are any collisions, break out and don't move the object
			if (collisionManager.checkCollision(collisionBox.getCollider(), object->collisionBox.getCollider()) == true)
			{
				std::cout << "Collision!" << std::endl;
				isCollided = true;

				//Reset collision box to original location
				collisionBox.getCollider()->x = x;
				collisionBox.getCollider()->y = y;
				break;
			}
		}



	}

	//If there are no collisions, update object location
	if (isCollided != true)
	{
		x = destX;
		y = destY;

		locationRect.x = x;
		locationRect.y = y;

		collisionBox.getCollider()->x = destX;
		collisionBox.getCollider()->y = destY;
	}


}

