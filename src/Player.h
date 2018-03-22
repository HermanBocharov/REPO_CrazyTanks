#pragma once

#include "Tank.h"

class Player : public Tank
{
public:
	Player();
	~Player();

	virtual void setDirection(Direction direction) override;
};

