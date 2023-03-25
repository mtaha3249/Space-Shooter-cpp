#pragma once
#include "InputListener.h"
#include <unordered_set>
#include <Windows.h>
using namespace std;

class InputSystem
{
public:
	// deleting copy constructor
	InputSystem(const InputSystem& obj) = delete;

	static InputSystem* getInstance()
	{
		if (_instancePtr == nullptr)
		{
			_instancePtr = new InputSystem();
			return _instancePtr;
		}
		else {
			return _instancePtr;
		}
	}

	enum EventType
	{
		Down,
		Up
	};

	void RaiseEvent(SDL_Keycode keyCode, EventType eventType);
	void addListener(InputListener* listener);
	void removeListener(InputListener* listener);

private:
	static InputSystem* _instancePtr;

	unordered_set<InputListener*> allListeners;

	InputSystem();
	~InputSystem()
	{
		delete _instancePtr;
		allListeners.clear();
	}
};

