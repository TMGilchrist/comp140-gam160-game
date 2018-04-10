#pragma once
#include <SDL.h>

class Level
{
public:
	Level();
	Level(SDL_Renderer* renderer, char* imagePath);
	~Level();

	void drawBackground(SDL_Renderer* renderer);

	SDL_Texture* getBackground()
	{
		return background;
	}

private:
	//Background sprite
	SDL_Texture* background;

protected:

};