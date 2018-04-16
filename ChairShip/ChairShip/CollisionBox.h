#pragma once

class CollisionBox
{
public:
	CollisionBox() {};
	CollisionBox(int initX, int initY, int initHeight, int initWidth, bool initIsSolid);

	CollisionBox(const CollisionBox& box) 
	{
		isSolid = box.isSolid;

		collider = box.collider;
	};

	~CollisionBox() 
	{ 
		//delete collider; 
	};

	//Getters and Setters
	SDL_Rect& getCollider()
	{
		return collider;
	}

	void setColliderX(int newX)
	{
		collider.x = newX;
	};

	void setColliderY(int newY)
	{
		collider.y = newY;
	};

private:
	//Rectangle representing collision box
	SDL_Rect collider;

	//If the collision box should block movement.
	bool isSolid;

};
