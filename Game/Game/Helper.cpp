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
	print(randval);
	print(RAND_MAX);
	print(randval / (float)RAND_MAX);
	return ((float)rand() / (RAND_MAX / (max - min))) + min;
}
