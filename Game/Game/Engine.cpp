#include "Engine.h"

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::update()
{
	//print("Delta Time " + std::to_string(EngineTime::deltaTime));

	if (_isFullScreen)
	{
		SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN);
	}
	else {
		SDL_SetWindowFullscreen(_window, 0);
	}

	for (int i = 0; i < GameManager::getInstance()->_worldObjects.size(); i++)
	{
		GameManager::getInstance()->_worldObjects[i]->Update();
	}
}

void Engine::init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENWIDTH, SCREENHEIGHT, 0);
		_renderer = SDL_CreateRenderer(_window, -1, 0);
		SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
		GameManager::getInstance()->Init(_renderer);
		_isRunning = true;
		_isFullScreen = false;
	}
	else
	{
		_isRunning = false;
	}
}

void Engine::sdlevent()
{
	SDL_Event sdlEvent;
	SDL_PollEvent(&sdlEvent);
	switch (sdlEvent.type)
	{
	case SDL_QUIT:
		_isRunning = false;
		break;
	case SDL_KEYDOWN:
		InputSystem::getInstance()->RaiseEvent(sdlEvent.key.keysym.sym, InputSystem::Down);
		break;
	case SDL_KEYUP:
		InputSystem::getInstance()->RaiseEvent(sdlEvent.key.keysym.sym, InputSystem::Up);
		break;
	}
	const std::uint8_t* keyState = SDL_GetKeyboardState(NULL);
	if (keyState[SDL_SCANCODE_ESCAPE]) _isRunning = false;
	if (keyState[SDL_SCANCODE_F11]) _isFullScreen = !_isFullScreen;
}

void Engine::render()
{
	SDL_RenderClear(_renderer);
	for (int i = 0; i < GameManager::getInstance()->_worldObjects.size(); i++)
	{
		GameManager::getInstance()->_worldObjects[i]->Draw();
	}
	SDL_RenderPresent(_renderer);
}

void Engine::clean()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	SDL_Quit();
}

void Engine::print(string log)
{
	if (USE_LOGS)
	{
		std::cout << log << endl;
	}
}
