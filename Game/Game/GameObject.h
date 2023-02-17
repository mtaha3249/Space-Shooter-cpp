#pragma once
#include "Transform.h"

class GameObject
{
public:
	GameObject();
	Transform _transform;

	virtual void Draw() {}
	virtual void Update() {}

	~GameObject()
	{

	}
private:

protected:
};