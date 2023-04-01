#pragma once
#include "GameManager.h"
#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "InputSystem.h"
#include <string>
using namespace std;

static bool USE_LOGS = true;

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
	static void print(string log);
private:
	SDL_Renderer* _renderer;
	SDL_Window* _window;
	bool _isRunning, _isFullScreen;
protected:
};