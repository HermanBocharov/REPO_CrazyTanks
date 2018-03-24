#ifndef WALL_H
#define WALL_H

#include "GameObject.h"

class Wall : public GameObject
{
public:
	Wall(int x, int y);
	~Wall();

	int getStrength();

private:
	int strength_;
};

#endif WALL_H