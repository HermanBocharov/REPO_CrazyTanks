#pragma once

#include "GameObject.h"

class GameObjectFactory
{
public:
	GameObjectFactory();
	virtual ~GameObjectFactory();
	virtual GameObject* createGameObject(int x, int y) = 0;
};

