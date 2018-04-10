#pragma once
#include "SDL.h"
#include "Sprite.h"

class Object
{
public:
	Object() {};

	//Constructor: passed renderer and the file path for the object sprite.
	Object(SDL_Renderer* renderer, char* imagePath);

	~Object() {};

	void drawSelf(SDL_Renderer* renderer);
	void drawSelf(SDL_Renderer* renderer, SDL_Rect* destinationRect);
	void drawSelf(SDL_Renderer* renderer, SDL_Rect* sourceRect, SDL_Rect* destinationRect);

private:
	//The object's sprite component
	Sprite sprite;

	//Object's position on screen
	float x;
	float y;

protected:

};
