#pragma once
struct Vector2
{
public:
	Vector2();
	Vector2(float x, float y);

	~Vector2()
	{
	}
	float x, y;

	Vector2 operator +=(Vector2 v2) {
		x += v2.x;
		y += v2.y;
		return *this;
	}

private:
protected:

};