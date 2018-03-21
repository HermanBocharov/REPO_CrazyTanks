#include "WallFactory.h"

WallFactory::WallFactory()
{
}



WallFactory::~WallFactory()
{
}



GameObject* WallFactory::createGameObject()
{
	return new Wall();
}
