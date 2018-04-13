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
	Object(SDL_Renderer* renderer, char* imagePath, float height, float width);
	Object(SDL_Renderer* renderer, char* imagePath, float height, float width, bool isSolid);

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
	void updateLocation();
	void updateLocation(float deltaTime, float xVelocity, float yVelocity, std::vector<Object*> objects);
	
	//Getters and Setters
	float getX()
	{
		return x;
	}
	float getY()
	{
		return y;
	}

	void setX(float newX)
	{
		x = newX;
		collisionBox.getCollider()->x = newX;
		locationRect.x = newX;
	}
	void setY(float newY)
	{
		y = newY;
		collisionBox.getCollider()->y = newY;
		locationRect.y = newY;
	}
	
	void moveX(float deltaTime, float xVelocity)
	{
		x = x + xVelocity * (deltaTime / 1000);
	}
	void moveY(float deltaTime, float yVelocity)
	{
		y = y + yVelocity *(deltaTime / 1000);
	}

private:
	//The object's sprite component
	Sprite sprite;

	//Object's position on screen
	float x;
	float y;

	//Object's location as SDL_Rect
	SDL_Rect locationRect;

	//Collision bounds of the object
	CollisionBox collisionBox;
	CollisionManager collisionManager;

protected:

};
