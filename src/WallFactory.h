#ifndef WALLFACTORY_H
#define WALLFACTORY_H

#include "GameObjectFactory.h"
#include "Wall.h"

class WallFactory : public GameObjectFactory
{
public:
	WallFactory();
	~WallFactory();
	virtual GameObject* createGameObject(int x, int y) override;
};

#endif WALLFACTORY_H