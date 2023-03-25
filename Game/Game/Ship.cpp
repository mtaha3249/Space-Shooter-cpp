#include "Ship.h"

Ship::Ship(const char* _filepath, SDL_Renderer* _renderer, Vector2 _position, int _size)
{
	this->_renderer = _renderer;
	this->_textureSurface = TextureManager::LoadFile(_filepath);

	_width = _textureSurface->w;
	_height = _textureSurface->h;

	this->_texture = TextureManager::LoadTexture(_textureSurface, _renderer);

	_transform._position = _position;

	this->_size = _size;

	InputSystem::getInstance()->addListener(this);
}

Ship::Ship(const char* _filepath, SDL_Renderer* _renderer, Vector2 _position, Vector2 _scale, int _size)
{
	_transform._scale = _scale;
	this->_renderer = _renderer;
	this->_textureSurface = TextureManager::LoadFile(_filepath);

	_width = _textureSurface->w;
	_height = _textureSurface->h;

	this->_texture = TextureManager::LoadTexture(_textureSurface, _renderer);

	_transform._position = _position;
	_transform._scale = _scale;

	this->_size = _size;

	InputSystem::getInstance()->addListener(this);
}

void Ship::Update()
{
	destRect.x = _transform._position.x;
	destRect.y = _transform._position.y;
	destRect.w = _width * _transform._scale.x;
	destRect.h = _height * _transform._scale.y;
}

void Ship::Draw()
{
	SDL_RenderCopy(_renderer, _texture, NULL, &destRect);
}

Ship::~Ship()
{
	InputSystem::getInstance()->removeListener(this);
}

void Ship::OnKeyDown(SDL_Keycode key)
{
	if (key == SDLK_d)
	{
		_transform._position += Vector2(1, 0) * MOVESPEED * EngineTime::getInstance()->deltaTime;
	}
	if (key == SDLK_a)
	{
		_transform._position -= Vector2(1, 0) * MOVESPEED * EngineTime::getInstance()->deltaTime;
	}
	if (key == SDLK_w)
	{
		_transform._position -= Vector2(0, 1) * MOVESPEED * EngineTime::getInstance()->deltaTime;
	}
	if (key == SDLK_s)
	{
		_transform._position += Vector2(0, 1) * MOVESPEED * EngineTime::getInstance()->deltaTime;
	}
}

void Ship::OnKeyUp(SDL_Keycode key)
{
	if (key == SDLK_d)
	{
		_transform._position += Vector2(0, 0);
	}
	if (key == SDLK_a)
	{
		_transform._position -= Vector2(0, 0);
	}
	if (key == SDLK_w)
	{
		_transform._position -= Vector2(0, 0);
	}
	if (key == SDLK_s)
	{
		_transform._position += Vector2(0, 0);
	}
}