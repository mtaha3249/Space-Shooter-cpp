#include "Helper.h"

void Helper::print(string log)
{
	if (USE_LOGS)
	{
		std::cout << log << endl;
	}
}

void Helper::print(int log)
{
	if (USE_LOGS)
	{
		std::cout << log << endl;
	}
}

void Helper::print(float log)
{
	if (USE_LOGS)
	{
		std::cout << log << endl;
	}
}

int Helper::random(int min, int max)
{
	srand(time(0));
	return (rand() % (max - min + 1)) + min;
}

float Helper::random(float min, float max)
{
	srand(time(0));
	float randval = (float)rand();
	/*print(randval);
	print(RAND_MAX);
	print(randval / (float)RAND_MAX);*/
	return ((float)rand() / (RAND_MAX / (max - min))) + min;
}

void Helper::DrawCircle(SDL_Renderer* _renderer, Color _color, Vector2 _center, int _radius)
{
	if (!DRAWGIZMO)
		return;

	const int diameter = (_radius * 2);
	int x = (_radius - 1);
	int y = 0;
	int tx = 1;
	int ty = 1;
	int error = (tx - diameter);

	while (x >= y)
	{
		SDL_SetRenderDrawColor(_renderer, _color.r, _color.g, _color.b, _color.a);
		//  Each of the following renders an octant of the circle
		SDL_RenderDrawPoint(_renderer, _center.x + x, _center.y - y);
		SDL_RenderDrawPoint(_renderer, _center.x + x, _center.y + y);
		SDL_RenderDrawPoint(_renderer, _center.x - x, _center.y - y);
		SDL_RenderDrawPoint(_renderer, _center.x - x, _center.y + y);
		SDL_RenderDrawPoint(_renderer, _center.x + y, _center.y - x);
		SDL_RenderDrawPoint(_renderer, _center.x + y, _center.y + x);
		SDL_RenderDrawPoint(_renderer, _center.x - y, _center.y - x);
		SDL_RenderDrawPoint(_renderer, _center.x - y, _center.y + x);

		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}
}

void Helper::DrawRectangle(SDL_Renderer* _renderer, Color _color, Vector2 _position, Vector2 _size)
{
	if (!DRAWGIZMO)
		return;

	SDL_Rect rect;
	rect.x = _position.x;
	rect.y = _position.y;
	rect.w = _size.x;
	rect.h = _size.y;

	SDL_SetRenderDrawColor(_renderer, _color.r, _color.g, _color.b, _color.a);
	SDL_RenderDrawRect(_renderer, &rect);
}