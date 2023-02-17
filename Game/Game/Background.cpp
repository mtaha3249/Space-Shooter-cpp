#include "Background.h"

Background::Background(const char* _filepath, SDL_Renderer* _renderer, Vector2 _position)
{
	this->_renderer = _renderer;
	this->_textureSurface = TextureManager::LoadFile(_filepath);

	_width = _textureSurface->w;
	_height = _textureSurface->h;

	this->_texture = TextureManager::LoadTexture(_textureSurface, _renderer);

	_transform._position = _position;
}

void Background::Update()
{
	destRect.x = _transform._position.x;
	destRect.y = _transform._position.y;
	destRect.w = _width * _transform._scale.x;
	destRect.h = _height * _transform._scale.y;
}

void Background::Draw()
{
	SDL_RenderCopy(_renderer, _texture, NULL, &destRect);
}
