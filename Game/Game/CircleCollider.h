#pragma once
#include "Collider.h"

class CircleCollider :
    public Collider
{
public:
    void SetCircleCollider(float _radius);
    void Init(GameObject* _go, Rigidbody* _body) override;
    void CheckCollision() override;
private:
    b2CircleShape* _circleShape;
    float _radius;
protected:
};

