#ifndef PROJECTILEFACTORY_H
#define PROJECTILEFACTORY_H

#include "GameObjectFactory.h"
#include "Projectile.h"

class ProjectileFactory : public GameObjectFactory
{
public:
	ProjectileFactory();
	~ProjectileFactory();
	virtual GameObject* createGameObject(int x, int y) override;
};

#endif PROJECTILEFACTORY_H