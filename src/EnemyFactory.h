#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "GameObjectFactory.h"
#include "Enemy.h"

class EnemyFactory : public GameObjectFactory
{
public:
	EnemyFactory();
	~EnemyFactory();
	virtual GameObject* createGameObject(int x, int y) override;
};

#endif ENEMYFACTORY_H