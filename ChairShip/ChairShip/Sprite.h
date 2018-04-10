#pragma once
#include <SDL_image.h>

class Sprite
{
public:
	Sprite() {};
	Sprite(SDL_Renderer* renderer, char* filePath);
	~Sprite() {};

	SDL_Texture* getTexture()
	{
		return texture;
	}

	void setTexture(SDL_Texture* newTexture)
	{
		texture = newTexture;
	}

private:
	SDL_Texture* texture;
	//float x;
	//float y;

	float height;
	float width;
};