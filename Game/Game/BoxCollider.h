#pragma once
#include "Collider.h"

class BoxCollider :
    public Collider
{
public:
    void SetBoxCollider(float _height, float _width);
    void Init(GameObject* _go, Rigidbody* _body) override;
    void CheckCollision() override;
private:
    b2PolygonShape* _polygonShape;
    float _height, _width;
protected:
};