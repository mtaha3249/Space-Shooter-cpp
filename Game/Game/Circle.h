#pragma once
#include "GameObject.h"

class Circle :
    public GameObject
{
public:
    Circle(Vector2 _position, int _size);
    void Draw() override;
    void Update() override;
    ~Circle()
    {
    }
private:
    float _size;
protected:
};

