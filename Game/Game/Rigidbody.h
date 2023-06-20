#pragma once
#include "Transform.h"
#include <box2d/box2d.h>
#include "Physics.h"

class Rigidbody
{
public:
	enum PhysicsBodyType
	{
		Static = 0,
		Kinematic = 1,
		Dynamic = 2
	};
	Rigidbody(Transform _t, float _gravityScale = 1, PhysicsBodyType _bodyType = Dynamic);
	b2Body* _b2body;

private:
	b2BodyDef _bodyDef;

	~Rigidbody()
	{

	}

protected:
};

