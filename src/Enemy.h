#ifndef ENEMY_H
#define ENEMY_H

#include "Tank.h"

class Enemy : public Tank
{
public:
	Enemy(int x, int y);
	~Enemy();

	virtual void setDirection(Direction direction) override;
};

#endif ENEMY_H

