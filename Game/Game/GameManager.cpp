#include "GameManager.h"

GameManager* GameManager::_instancePtr = nullptr;

void GameManager::Init(SDL_Renderer* _renderer)
{
	_worldObjects.push_back(new Background("assets/Background.jpg", _renderer, Vector2(0, 0)));

	_worldObjects.push_back(new Ship("assets/Ship.png", _renderer, Vector2(SCREENWIDTH / 2, (SCREENHEIGHT - 250) - BORDER), Vector2(0.8f, 0.8f)));

	for (int i = 0; i < ASTEROIDS; i++)
	{
		/*_worldObjects.push_back(new Asteroids("assets/Asteroid.png", _renderer, Vector2(0 + BORDER, 0 + BORDER), Vector2(1, 1), 1));*/
		_worldObjects.push_back(new Asteroids("assets/Asteroid.png", _renderer, Vector2(SCREENWIDTH / 2, 10), Vector2(1, 1), 25, Vector2(0.5f, 1.5f), Vector2(100.0f, 150.0f)));
	}
}

GameManager::GameManager()
{

}