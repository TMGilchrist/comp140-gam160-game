#pragma once

class CollisionBox
{
public:
	CollisionBox() {};
	CollisionBox(int initX, int initY, int initHeight, int initWidth, bool initIsSolid);

	~CollisionBox() 
	{ 
		delete collider; 
	};

	//Getters and Setters
	SDL_Rect* getCollider()
	{
		return collider;
	}

private:
	//Rectangle representing collision box
	SDL_Rect* collider;

	//If the collision box should block movement.
	bool isSolid;

};
