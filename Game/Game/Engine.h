#pragma once
#include "GameManager.h"
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"

class Engine
{
public:
	Engine();
	~Engine();
	void update();
	void init();
	void sdlevent();
	void render();
	void clean();
	bool running() { return _isRunning; }
private:
	SDL_Renderer* _renderer;
	SDL_Window* _window;
	bool _isRunning;
protected:
};