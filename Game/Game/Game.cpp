#include "Engine.h"
#include "EngineTime.h"
#include "Physics.h"

Engine* engine = nullptr;

int main(int argc, char** argv)
{
	engine = new Engine();

	Uint32 frameStart = 0;

	engine->init();
	while (engine->running())
	{
		frameStart = SDL_GetTicks();

		engine->sdlevent();
		engine->update();
		Physics::getInstance()->_phsyicsWorld->Step(1.0 / (float)EngineTime::FPS, Physics::getInstance()->_velocityIteration, Physics::getInstance()->_positionIteration);
		engine->render();

		EngineTime::frameTime = SDL_GetTicks() - frameStart;

		if (EngineTime::getFrameDelay() > EngineTime::frameTime)
		{
			EngineTime::deltaTime = EngineTime::getFrameDelay() - EngineTime::frameTime;
			SDL_Delay(EngineTime::deltaTime);
		}
	}
	engine->clean();
	return 0;
}