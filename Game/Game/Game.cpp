#include "Engine.h"
#include "EngineTime.h"

Engine* engine = nullptr;

int main(int argc, char** argv)
{
	engine = new Engine();

	Uint32 frameStart;

	engine->init();
	while (engine->running())
	{
		frameStart = SDL_GetTicks();

		engine->sdlevent();
		engine->update();
		engine->render();

		EngineTime::getInstance()->deltaTime = SDL_GetTicks() - frameStart;

		if (EngineTime::getInstance()->getFrameDelay() > EngineTime::getInstance()->deltaTime)
		{
			SDL_Delay(EngineTime::getInstance()->getFrameDelay() - EngineTime::getInstance()->deltaTime);
		}
	}
	engine->clean();
	return 0;
}