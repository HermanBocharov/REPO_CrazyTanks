#pragma once
#include "GameObjectFactory.h"
#include "Enemy.h"
class EnemyFactory :
	public GameObjectFactory
{
public:
	EnemyFactory();
	~EnemyFactory();
	virtual GameObject* createGameObject() override;
};

