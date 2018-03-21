#pragma once

#include "GameObject.h"

class GameObjectFactory
{
public:
	GameObjectFactory();
	~GameObjectFactory();
	virtual GameObject* createGameObject() = 0;
};

