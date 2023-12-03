#pragma once
#include "GameObject.h"
#include "Asteroids.h"
#include "Background.h"
#include "Ship.h"
#include <vector>
using namespace std;

#define ASTEROIDS 1
#define SCREENHEIGHT 720
#define SCREENWIDTH 1280
#define BORDER 20
#define DRAWGIZMO true

class GameManager
{ 
public:
	// deleting copy constructor
	GameManager(const GameManager& obj) = delete;

	static GameManager* getInstance()
	{
		if (_instancePtr == nullptr)
		{
			_instancePtr = new GameManager();
			return _instancePtr;
		}
		else {
			return _instancePtr;
		}
	}

	void Init(SDL_Renderer* _renderer);
	vector<GameObject*> _worldObjects;

private:
	static GameManager* _instancePtr;
	GameManager();
	~GameManager()
	{
		delete _instancePtr;
		_worldObjects.clear();
	}

protected:
};
