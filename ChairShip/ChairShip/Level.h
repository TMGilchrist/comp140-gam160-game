#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Level
{
public:
	Level();
	Level(SDL_Renderer* renderer, char* imagePath);
	~Level();

	//Render the background
	void drawBackground(SDL_Renderer* renderer);

	//Getters
	SDL_Texture* getBackground()
	{
		return background;
	}

private:
	//Background sprite
	SDL_Texture* background;

protected:

};