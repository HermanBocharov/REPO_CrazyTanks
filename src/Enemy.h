#pragma once
#include "Tank.h"
class Enemy :
	public Tank
{
public:
	Enemy();
	~Enemy();

	virtual void setDirection(Direction direction) override;
};

