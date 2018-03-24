#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H

#include "GameObject.h"

class GameObjectFactory
{
public:
	GameObjectFactory();
	virtual ~GameObjectFactory();
	virtual GameObject* createGameObject(int x, int y) = 0;
};

#endif GAMEOBJECTFACTORY_H