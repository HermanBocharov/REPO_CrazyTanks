#pragma once

#include "GameObject.h"

class GameObjectFactory
{
public:
	GameObjectFactory();
	virtual ~GameObjectFactory();
	virtual GameObject* createGameObject() = 0;
};

