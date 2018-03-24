#include "EnemyFactory.h"

EnemyFactory::EnemyFactory()
{
}



EnemyFactory::~EnemyFactory()
{
}



GameObject* EnemyFactory::createGameObject(int x, int y)
{
	return new Enemy(x, y);
}