#include "stdafx.h"
#include "Object.h"
#include "Utility.h"
#include "globals.h"
#include <vector>
#include <cmath>

//Constructor (should probably add ability to customise collision box at some point)
Object::Object(SDL_Renderer * renderer, char* imagePath, int height, int width)
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

	isColliderSolid = isSolid;
}

//Constructor where sprite is already loaded
Object::Object(Sprite initSprite, SDL_Renderer* renderer)
{
	sprite = initSprite;

	location.x = 0;
	location.y = 0;
	location.h = sprite.getHeight();
	location.w = sprite.getWidth();

	collisionBox = CollisionBox(0, 0, location.h, location.w, false);
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
void Object::move(float deltaTime, float xVelocity, float yVelocity, std::vector<Object*> &activeObjects)
{
	bool isCollided = false;

	//Location the object wants to move to
	float destX = round(location.x + xVelocity * (deltaTime / 1000));
	float destY = round(location.y + yVelocity *(deltaTime / 1000));
	
	//Check for level edges. Adding width and height to destination x and y, as x and y is top left corner of sprite.
	if ((destX+location.w > global::SCREEN_WIDTH) || (destX < 0))
	{
		return;
	}
	if ((destY+location.h > global::SCREEN_HEIGHT) || (destY < 0))
	{
		return;
	}

	//Update the collision box to match the new destination
	collisionBox.getCollider().x = destX;
	collisionBox.getCollider().y = destY;
	
	//Check collision with each other active object
	for each (Object* object in activeObjects)
	{
		//Make sure object isn't trying to check collision with itself
		if (object != this) 
		{
			//If there are any collisions, break out and set collided flag
			if (collisionManager.checkCollision(collisionBox.getCollider(), object->collisionBox.getCollider()) == true)
			{
				//std::cout << "Collision!" << std::endl;
				isCollided = true;

				//Check that both objects have solid colliders
				if ((object->getIsColliderSolid() == true) && (isColliderSolid == true)) 
				{
					//Reset collision box to original location
					collisionBox.getCollider().x = location.x;
					collisionBox.getCollider().y = location.y;

					onCollide(object);
					break;
				}

				//If the collision is non-solid, update location while still raising collision flag
				location.x = int(destX);
				location.y = int(destY);

				collisionBox.getCollider().x = destX;
				collisionBox.getCollider().y = destY;

				onCollide(object);
				break;
			}
		}
	}

	//If there are no collisions, update object location
	if (isCollided != true)
	{
		location.x = int(destX);
		location.y = int(destY);

		collisionBox.getCollider().x = destX;
		collisionBox.getCollider().y = destY;
	}


}

//Unused currently
int Object::checkCollision(std::vector<Object*> activeObjects)
{
	//0 is no collision, 1 is solid collision, 2 is non-solid collision
	int isCollided = 0;

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
				
				//Check for isSolid
				if (object->getIsColliderSolid() == true)
				{
					//Reset collision box to original location
					collisionBox.getCollider().x = location.x;
					collisionBox.getCollider().y = location.y;
					isCollided = 1;
					return isCollided;
				}

				isCollided = 2;
				return isCollided;
			}
		}
	}

	return isCollided;
}

//Set object location without checking for collision (teleport essentially)
void Object::setLocation(int newX, int newY, int newHeight, int newWidth)
{
	//Update location
	location.x = newX;
	location.y = newY;
	location.h = newHeight;
	location.w = newWidth;

	//Update the collision box to match the new location
	collisionBox.getCollider().x = newX;
	collisionBox.getCollider().y = newY;
}

