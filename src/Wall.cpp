#include "Wall.h"

Wall::Wall(int x, int y)
{
	positionX_ = x;
	positionY_ = y;
	strength_ = 3;
	displayChar_ = 178;
}



Wall::~Wall() {}



int Wall::getStrength()
{
	return strength_;
}