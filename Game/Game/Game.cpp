#include "Engine.h"
#include "EngineTime.h"

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