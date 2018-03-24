#include "ProjectileFactory.h"

ProjectileFactory::ProjectileFactory()
{
}



ProjectileFactory::~ProjectileFactory()
{
}



GameObject* ProjectileFactory::createGameObject(int x, int y)
{
	return new Projectile();
}