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
	void move(float deltaTime, float xVelocity, float yVelocity, std::vector<Object*> objects);
	
	//Getters and Setters
	void setLocation(int x, int y);

private:
	//The object's sprite component
	Sprite sprite;

	//Object's location as SDL_Rect
	SDL_Rect location;

	//Collision bounds of the object
	CollisionBox collisionBox;
	CollisionManager collisionManager;

protected:

};
