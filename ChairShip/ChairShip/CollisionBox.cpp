#include "stdafx.h"
#include "CollisionBox.h"
#include "SDL.h"

CollisionBox::CollisionBox(int initX, int initY, int initHeight, int initWidth, bool initIsSolid)
{
	isSolid = initIsSolid;

	collider = SDL_Rect();
	collider.x = initX;
	collider.y = initY;
	collider.h = initHeight;
	collider.w = initWidth;
}
