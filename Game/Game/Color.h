#pragma once
class Color
{
public:
	Color(float r, float g, float b, float a) { this->r = r; this->g = g; this->b = b; this->a = a; }
	float r = 255;
	float g = 255;
	float b = 255;
	float a = 255;
	~Color()
	{
	}
};
