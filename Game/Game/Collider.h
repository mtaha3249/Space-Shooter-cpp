#pragma once
#include "CollisionListener.h"
#include "Rigidbody.h"
#include <box2d/box2d.h>

class Collider
{
public:
	virtual void Init(GameObject* _go, Rigidbody* _body) = 0;
	virtual void CheckCollision() = 0;
private:
protected:
	b2Shape* _bShape;
};

