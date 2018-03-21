#include "ProjectileFactory.h"

ProjectileFactory::ProjectileFactory()
{
}



ProjectileFactory::~ProjectileFactory()
{
}



GameObject* ProjectileFactory::createGameObject()
{
	return new Projectile();
}