#pragma once
#include "SDL.h"
#include "Sprite.h"

class Object
{
public:
	Object() {};

	//Constructor: passed renderer and the file path for the object sprite.
	Object(SDL_Renderer* renderer, char* imagePath, float height, float width);

	~Object() {};

	void drawSelf(SDL_Renderer* renderer);
	void drawSelf(SDL_Renderer* renderer, SDL_Rect* sourceRect);

	//Update the locationRect
	void updateLocation();

	//Move the object sprite
	void move(float newX, float newY);


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
	}
	void setY(float newY)
	{
		y = newY;
	}

	void moveX(float xChange)
	{
		x = x + xChange;
	}
	void moveY(float yChange)
	{
		y = y + yChange;
	}
private:
	//The object's sprite component
	Sprite sprite;

	//Object's position on screen
	float x;
	float y;

	//Object's location as SDL_Rect
	SDL_Rect locationRect;

protected:

};
