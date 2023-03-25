#pragma once
#include <SDL_keycode.h>

class InputListener
{
public:
	InputListener()
	{
	}
	~InputListener()
	{
	}

	virtual void OnKeyDown(SDL_Keycode key) = 0;
	virtual void OnKeyUp(SDL_Keycode key) = 0;
};