#include "Physics.h"

Physics* Physics::_instancePtr = nullptr;

int Physics::_velocityIteration = 8;
int Physics::_positionIteration = 3;
b2Vec2 Physics::_gravity = b2Vec2(0, 0);
const float Physics::_baseRotationSpeed = 1000000000.0f;

Physics::Physics()
{
	_phsyicsWorld = new b2World(_gravity);
}