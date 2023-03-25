#include "InputSystem.h"

InputSystem* InputSystem::_instancePtr = nullptr;

void InputSystem::RaiseEvent(SDL_Keycode keyCode, EventType eventType)
{
	switch (eventType)
	{
	case InputSystem::Down:
		for (auto listener : allListeners)
		{
			listener->OnKeyDown(keyCode);
		}
		break;
	case InputSystem::Up:
		for (auto listener : allListeners)
		{
			listener->OnKeyUp(keyCode);
		}
		break;
	}
}

void InputSystem::addListener(InputListener* listener)
{
	allListeners.insert(listener);
}

void InputSystem::removeListener(InputListener* listener)
{
	unordered_set<InputListener*>::iterator it = allListeners.find(listener);

	if (it != allListeners.end())
	{
		allListeners.erase(it);
	}
}

InputSystem::InputSystem()
{
}
