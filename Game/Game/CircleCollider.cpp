#include "CircleCollider.h"

void CircleCollider::SetCircleCollider(float _radius)
{
    this->_radius = _radius;
}

void CircleCollider::Init(GameObject* _go, Rigidbody* _body)
{
    _circleShape = new b2CircleShape();
    _bShape = _circleShape;
    _circleShape->m_p.Set(_go->_transform._position.x, _go->_transform._position.y);
    _circleShape->m_radius = _radius;

    _body->_b2body->CreateFixture(_bShape, 1.0);
}

void CircleCollider::CheckCollision()
{
    //do something
}
