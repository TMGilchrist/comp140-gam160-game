#pragma once
#include "SDL.h"
#include "Sprite.h"
#include "CollisionBox.h"
#include "CollisionManager.h"
#include <vector>

class Object
{
public:
	Object() {};

	//Constructor: passed renderer and the file path for the object sprite.
	Object(SDL_Renderer* renderer, char* imagePath, float height, float width, bool isSolid, bool wallCollision);

	//Constructor for creating object with ready made sprite
	Object(Sprite initSprite, SDL_Renderer* renderer, bool isSolid, bool wallCollision);

	~Object() {};

	/**
		Copies the object's sprite data to the renderer so it can be drawn to the screen.

		@param renderer The SDL_Renderer* being used to draw the screen
		@param sourceRect (Optional) The SDL_Rect* that defines the portion of the sprite texture to draw.
	*/
	void drawSelf(SDL_Renderer* renderer);
	void drawSelf(SDL_Renderer* renderer, SDL_Rect* sourceRect);

	/**
		Updates the SDL_rect that represents the objects
		location on the screen. Called by drawing funtions.
	*/
	void move(float deltaTime, float xVelocity, float yVelocity, std::vector<Object*> &activeObjects);
	
	//TO check collision with other objects. Incomplete.
	int checkCollision(std::vector<Object*> activeObjects);

	void addToVector(std::vector<Object*> &activeObjects)
	{
		vectorIndex = activeObjects.size();
		activeObjects.push_back(this);
	}

	void removeFromVector(std::vector<Object*> &activeObjects)
	{
		activeObjects.erase(activeObjects.begin()+vectorIndex);
	}


	//Virtual functions to be overriden

	//Dervied classes can override this to provide their update functions.
	virtual void update(float deltaTime, std::vector<Object*> &activeObjects) {};

	//What happens when an object encounters a collision. Overriden by dervied classes.
	virtual void onCollide(Object* collidedWith) {};

	//Workaround. Not sure if it should be done this way.
	virtual void changeHealth(int healthChange) {};


	//Getters and Setters
	SDL_Rect getLocation()
	{
		return location;
	};

	bool getIsColliderSolid() 
	{
		return isColliderSolid;
	}

	int getVectorIndex()
	{
		return vectorIndex;
	}

	Sprite getBlankSprite() 
	{
		return blankSprite;
	}

	//Chained overload to allow member variables as default values
	void setLocation(int x, int y) 
	{
		setLocation(x, y, location.h, location.w);
	};
	void setLocation(int x, int y, int newHeight, int newWidth);

	void setSprite(Sprite newSprite)
	{
		sprite = newSprite;
	};

	void setVectorIndex(int newVectorIndex) 
	{
		vectorIndex = newVectorIndex;
	}

	void setIsColliderSolid(bool isSolid) 
	{
		isColliderSolid = isSolid;
	}

private:
	//The object's sprite components
	Sprite sprite;
	Sprite blankSprite;

	//Object's location as SDL_Rect
	SDL_Rect location;

	//Collision bounds of the object
	CollisionBox collisionBox;
	CollisionManager collisionManager;

	//If the object's collider is solid (ie. blocks other objects)
	bool isColliderSolid;

	//If the object collides with the map edges
	bool collidesWithWalls;

	//Location of an object in the activeObjects vector
	int vectorIndex;

protected:

};
