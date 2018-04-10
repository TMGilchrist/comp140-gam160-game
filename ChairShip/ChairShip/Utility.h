#pragma once
#include <SDL.h>
#include <iostream>

class Utility
{
public:
	Utility() {};
	~Utility() {};

	SDL_Texture* loadTexture(SDL_Renderer* renderer, char* file);
};