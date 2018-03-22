#include "Player.h"



Player::Player()
{
	positionX_ = 31;
	positionY_ = 21;
	displayChar_ = 30;
}


Player::~Player()
{
}



void Player::setDirection(Direction direction)
{
	if (direction == UP)
		displayChar_ = 30;
	else if (direction == DOWN)
		displayChar_ = 31;
	else if (direction == LEFT)
		displayChar_ = 17;
	else if (direction == RIGHT)
		displayChar_ = 16;

	direction_ = direction;
}

