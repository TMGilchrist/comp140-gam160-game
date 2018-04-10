#pragma once
#include <SDL_image.h>

class Sprite
{
public:
	Sprite() {};
	Sprite(SDL_Renderer* renderer, char* filePath, float height, float width);
	~Sprite() {};

	SDL_Texture* getTexture()
	{
		return texture;
	}

	void setTexture(SDL_Texture* newTexture)
	{
		texture = newTexture;
	}


	float getHeight() 
	{
		return height;
	}

	float getWidth()
	{
		return width;
	}


	void setHeight(float newHeight)
	{
		height = newHeight;
	}

	void setWidth(float newWidth)
	{
		width = newWidth;
	}

private:
	//Sprite image
	SDL_Texture* texture;

	//Sprite dimensions
	float height;
	float width;
};