#pragma once
#include <string>
#include "Engine.h"
#include <cstdlib>
#include <ctime>
#include <random>
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
};