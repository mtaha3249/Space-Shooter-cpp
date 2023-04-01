#pragma once

class EngineTime
{
public:
	static int FPS;
	static float frameTime;
	static float deltaTime;

	static float getFrameDelay() { return FPS / 1000.0f; }
};

