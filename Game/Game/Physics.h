#include <box2d/box2d.h>

#pragma once
class Physics
{
public:
	static int _velocityIteration;
	static int _positionIteration;
	static b2Vec2 _gravity;

	// deleting copy constructor
	Physics(const Physics& obj) = delete;

	static Physics* getInstance()
	{
		if (_instancePtr == nullptr)
		{
			_instancePtr = new Physics();
			return _instancePtr;
		}
		else {
			return _instancePtr;
		}
	}

	b2World* _phsyicsWorld;

private:
	static Physics* _instancePtr;

	Physics();
	~Physics()
	{
		delete _instancePtr;
		delete _phsyicsWorld;
	}
};

