#include "stdafx.h"
#include "CollisionBox.h"

CollisionBox::CollisionBox(int initX, int initY, int initHeight, int initWidth, bool initIsSolid)
{
	x = initX;
	y = initY;
	height = initHeight;
	width = initWidth;
	isSolid = initIsSolid;
}
