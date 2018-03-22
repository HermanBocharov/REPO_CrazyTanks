#pragma once

#include "GameObject.h"

class Wall : public GameObject
{
public:
	Wall();
	Wall(int x, int y);
	~Wall();

	int getStrength();

private:
	int strength_;
};

