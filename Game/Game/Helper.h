#pragma once
#include <string>
#include "Engine.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include "Color.h"
using namespace std;

class Helper
{
public:
	static void print(string log);
	static void print(int log);
	static void print(float log);
	/// <summary>
	/// Give Random number between min and max
	/// min and max inclusive
	/// </summary>
	/// <param name="min">Minimum</param>
	/// <param name="max">Maximum</param>
	/// <returns>random integer</returns>
	static int random(int min, int max);

	/// <summary>
	/// Give Random number between min and max
	/// min and max inclusive
	/// </summary>
	/// <param name="min">Minimum</param>
	/// <param name="max">Maximum</param>
	/// <returns>random integer</returns>
	static float random(float min, float max);

	/// <summary>
	/// Draw Circle Gizmo
	/// </summary>
	/// <param name="_renderer">SDL renderer</param>
	/// <param name="_color">Gizmo Color</param>
	/// <param name="_center">center of the circle</param>
	/// <param name="_radius">radius of circle</param>
	static void DrawCircle(SDL_Renderer* _renderer, Color _color, Vector2 _center, int _radius);

	/// <summary>
	/// Draw Rectangle Gizmo
	/// </summary>
	/// <param name="_renderer">SDL renderer</param>
	/// <param name="_color">Gizmo Color</param>
	/// <param name="_position">Position of the ractangle</param>
	/// <param name="_size">size of the rectangle, x = width, y = height</param>
	static void DrawRectangle(SDL_Renderer* _renderer, Color _color, Vector2 _position, Vector2 _size);
};