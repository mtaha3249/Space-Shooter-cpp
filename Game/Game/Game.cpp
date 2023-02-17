#include "Engine.h"
#include "EngineTime.h"

Engine* engine = nullptr;
EngineTime* _engineTime = nullptr;

int main(int argc, char** argv)
{
	engine = new Engine();
	_engineTime = new EngineTime();

	Uint32 frameStart;

	engine->init();
	while (engine->running())
	{
		frameStart = SDL_GetTicks();

		engine->sdlevent();
		engine->update();
		engine->render();

		_engineTime->deltaTime = SDL_GetTicks() - frameStart;

		if (_engineTime->getFrameDelay() > _engineTime->deltaTime)
		{
			SDL_Delay(_engineTime->getFrameDelay() - _engineTime->deltaTime);
		}
	}
	engine->clean();
	return 0;
}