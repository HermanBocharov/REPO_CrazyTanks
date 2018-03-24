#ifndef TANK_H
#define TANK_H

#include "GameObject.h"

class Tank : public GameObject
{
public:
	Tank();
	virtual ~Tank();

	void move();
	void fire();

	virtual void setDirection(Direction direction) = 0;
	int getDirection();

protected:
	Direction direction_;
};

#endif TANK_H