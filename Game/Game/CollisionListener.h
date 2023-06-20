#pragma once
#include "GameObject.h"

class CollisionListener
{
public:
	CollisionListener()
	{
	}
	~CollisionListener()
	{
	}

	virtual GameObject OnCollided() = 0;
};