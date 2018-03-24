#include "Enemy.h"

Enemy::Enemy(int x, int y)
{
	positionX_ = x;
	positionY_ = y;
	displayChar_ = 203;
}



Enemy::~Enemy()
{
}



void Enemy::setDirection(Direction direction)
{
	if (direction == UP)
		displayChar_ = 202;
	else if (direction == DOWN)
		displayChar_ = 203;
	else if (direction == LEFT)
		displayChar_ = 185;
	else if (direction == RIGHT)
		displayChar_ = 204;

	direction_ = direction;
}
