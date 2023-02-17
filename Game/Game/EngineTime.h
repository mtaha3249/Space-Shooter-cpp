#pragma once
class EngineTime
{
public:
	int FPS = 60;
	float deltaTime = 0.0f;

	float getFrameDelay() { return 1000 / FPS; }
};

