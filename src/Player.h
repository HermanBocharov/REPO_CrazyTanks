#ifndef PLAYER_H
#define PLAYER_H

#include "Tank.h"

class Player : public Tank
{
public:
	Player();
	~Player();

	virtual void setDirection(Direction direction) override;
};

#endif PLAYER_H