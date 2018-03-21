#pragma once
#include "GameObjectFactory.h"
#include "Projectile.h"
class ProjectileFactory :
	public GameObjectFactory
{
public:
	ProjectileFactory();
	~ProjectileFactory();
	virtual GameObject* createGameObject() override;
};

