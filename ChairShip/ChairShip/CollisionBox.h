#pragma once

class CollisionBox
{
public:
	CollisionBox() {};
	CollisionBox(int initX, int initY, int initHeight, int initWidth, bool initIsSolid);


	//Getters and Setters

	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getHeight()
	{
		return height;
	}
	int getWidth()
	{
		return width;
	}

	void setX(int newX)
	{
		x = newX;
	}
	void setY(int newY)
	{
		y = newY;
	}
	void setHeight(int newHeight)
	{
		height = newHeight;
	}
	void setWidth(int newWidth)
	{
		width = newWidth;
	}

private:
	//Origin of collision box
	int x;
	int y;

	//Dimensions of collision box
	int height;
	int width;

	//If the collision box should block movement.
	bool isSolid;

};
