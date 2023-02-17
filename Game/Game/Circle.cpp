#include "Circle.h"
#include <iostream>

Circle::Circle(Vector2 _position, int _size)
{
	_transform._position = _position;
	this->_size = _size;
}

void Circle::Draw()
{
}

void Circle::Update()
{
	_transform._position += Vector2(0.01f, 0);
}
