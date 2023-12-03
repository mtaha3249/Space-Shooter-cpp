#include "Rigidbody.h"

Rigidbody::Rigidbody(Transform _t, float _gravityScale, PhysicsBodyType _bodyType)
{
	_bodyDef.type = (b2BodyType)((int)_bodyType);
	_bodyDef.gravityScale = _gravityScale;
	_bodyDef.position.Set(_t._position.x, _t._position.y);

	_b2body = Physics::getInstance()->_phsyicsWorld->CreateBody(&_bodyDef);
}

Rigidbody::Rigidbody(Transform _t, b2BodyDef _bodyDefinition)
{
	this->_bodyDef = _bodyDefinition;
	this->_bodyDef.position.Set(_t._position.x, _t._position.y);
	_b2body = Physics::getInstance()->_phsyicsWorld->CreateBody(&this->_bodyDef);
}
