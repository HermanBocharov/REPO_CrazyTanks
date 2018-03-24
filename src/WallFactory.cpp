#include "WallFactory.h"

WallFactory::WallFactory()
{
}



WallFactory::~WallFactory()
{
}



GameObject* WallFactory::createGameObject(int x, int y)
{
	return new Wall(x, y);
}
