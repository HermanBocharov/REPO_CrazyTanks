#include "Tank.h"

Tank::Tank()
{
}



Tank::~Tank()
{
}



void Tank::move()
{
	if (direction_ == UP)
		positionY_--;
	else if (direction_ == DOWN) 
		positionY_++;
	else if (direction_ == LEFT)
		positionX_--;
	else if (direction_ == RIGHT)
		positionX_++;
}



void Tank::fire()
{
}



int Tank::getDirection()
{
	return direction_;
}