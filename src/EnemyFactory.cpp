#include "EnemyFactory.h"

EnemyFactory::EnemyFactory()
{
}



EnemyFactory::~EnemyFactory()
{
}



GameObject* EnemyFactory::createGameObject()
{
	return new Enemy();
}