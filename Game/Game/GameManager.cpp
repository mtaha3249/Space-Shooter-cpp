#include "GameManager.h"

GameManager* GameManager::_instancePtr = nullptr;

void GameManager::Init(SDL_Renderer* _renderer)
{
	_worldObjects.push_back(new Background("assets/Background.jpg", _renderer, Vector2(0, 0)));

	_worldObjects.push_back(new Ship("assets/Ship.png", _renderer, Vector2(SCREENWIDTH / 2, (SCREENHEIGHT - 200) - BORDER), Vector2(1, 1), 1));

	for (int i = 0; i < ASTEROIDS; i++)
	{
		/*_worldObjects.push_back(new Asteroids("assets/Asteroid.png", _renderer, Vector2(0 + BORDER, 0 + BORDER), Vector2(1, 1), 1));*/
		_worldObjects.push_back(new Asteroids("assets/Asteroid.png", _renderer, Vector2(SCREENWIDTH / 2, 10), Vector2(1, 1), 1));
	}
}

GameManager::GameManager()
{

}