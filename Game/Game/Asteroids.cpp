#include "Asteroids.h"

Asteroids::Asteroids(const char* _filepath, SDL_Renderer* _renderer, Vector2 _position, int _size)
{
	this->_renderer = _renderer;
	this->_textureSurface = TextureManager::LoadFile(_filepath);

	_width = _textureSurface->w;
	_height = _textureSurface->h;

	this->_texture = TextureManager::LoadTexture(_textureSurface, _renderer);

	_transform._position = _position;

	this->_size = _size;
}

Asteroids::Asteroids(const char* _filepath, SDL_Renderer* _renderer, Vector2 _position, Vector2 _scale, int _size)
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
}

void Asteroids::Update()
{
	_transform._position += Vector2(1, 0);
	//_transform._position += Vector2(1, 0) * EngineTime::getInstance()->deltaTime;
	destRect.x = _transform._position.x;
	destRect.y = _transform._position.y;
	destRect.w = _width * _transform._scale.x;
	destRect.h = _height * _transform._scale.y;
}

void Asteroids::Draw()
{
	SDL_RenderCopy(_renderer, _texture, NULL, &destRect);
}
