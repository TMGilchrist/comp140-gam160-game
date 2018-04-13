#include "stdafx.h"
#include "Object.h"
#include "Utility.h"
#include <vector>

//Constructor ( should probably add ability to customise collision box at some point)
Object::Object(SDL_Renderer * renderer, char* imagePath, float height, float width)
{
	sprite = Sprite(renderer, imagePath, height, width);

	location.x = 0;
	location.y = 0;
	location.h = height;
	location.w = width;

	collisionBox = CollisionBox(0, 0, height, width, false);
	collisionManager = CollisionManager();
}

//Constructor specifying if collisionBox is solid (kinda redundant...could just be true?)
Object::Object(SDL_Renderer * renderer, char * imagePath, float height, float width, bool isSolid)
{
	sprite = Sprite(renderer, imagePath, height, width);

	location.x = 0;
	location.y = 0;
	location.h = height;
	location.w = width;

	collisionBox = CollisionBox(0, 0, height, width, isSolid);
	collisionManager = CollisionManager();
}

//Update location and render sprite
void Object::drawSelf(SDL_Renderer * renderer)
{
	//Add texture to renderer
	SDL_RenderCopy(renderer, sprite.getTexture(), NULL, &location);
}

void Object::drawSelf(SDL_Renderer * renderer, SDL_Rect * sourceRect)
{
	//Add texture to renderer
	SDL_RenderCopy(renderer, sprite.getTexture(), sourceRect, &location);
}


//Check collision in new desitination. Move to destination if no collisions are found.
void Object::move(float deltaTime, float xVelocity, float yVelocity, std::vector<Object*> activeObjects)
{
	bool isCollided = false;

	//Location the object wants to move to
	float destX = location.x + xVelocity * (deltaTime / 1000);
	float destY = location.y + yVelocity *(deltaTime / 1000);
	
	//Update the collision box to match the new destination
	collisionBox.getCollider()->x = destX;
	collisionBox.getCollider()->y = destY;

	//Check collision with each other active object
	for each (Object* object in activeObjects)
	{
		//Make sure object isn't trying to check collision with itself
		if (object != this) 
		{
			//If there are any collisions, break out and set collided flag
			if (collisionManager.checkCollision(collisionBox.getCollider(), object->collisionBox.getCollider()) == true)
			{
				std::cout << "Collision!" << std::endl;
				isCollided = true;

				//Reset collision box to original location
				collisionBox.getCollider()->x = location.x;
				collisionBox.getCollider()->y = location.y;
				break;
			}
		}
	}

	//If there are no collisions, update object location
	if (isCollided != true)
	{
		location.x = destX;
		location.y = destY;

		//location.x = x;
		//location.y = y;

		collisionBox.getCollider()->x = destX;
		collisionBox.getCollider()->y = destY;
	}


}

void Object::setLocation(int newX, int newY)
{
	//Update location
	location.x = newX;
	location.y = newY;

	//Update the collision box to match the new location
	collisionBox.getCollider()->x = newX;
	collisionBox.getCollider()->y = newY;
}

