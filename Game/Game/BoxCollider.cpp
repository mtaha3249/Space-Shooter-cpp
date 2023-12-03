#include "BoxCollider.h"

void BoxCollider::SetBoxCollider(float _height, float _width)
{
	this->_height = _height / 2;
	this->_width = _width / 2;
}

void BoxCollider::Init(GameObject* _go, Rigidbody* _body)
{
	_polygonShape = new b2PolygonShape();
	_bShape = _polygonShape;
	_polygonShape->SetAsBox(this->_width, this->_height);
}

void BoxCollider::CheckCollision()
{
	//do something
}
