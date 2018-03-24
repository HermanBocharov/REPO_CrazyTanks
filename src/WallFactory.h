#pragma once
#include "GameObjectFactory.h"
#include "Wall.h"
class WallFactory :
	public GameObjectFactory
{
public:
	WallFactory();
	~WallFactory();
	virtual GameObject* createGameObject(int x, int y) override;
};

