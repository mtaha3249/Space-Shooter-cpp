#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* _filepath, SDL_Renderer* _renderer)
{
	SDL_Surface* tempSurface = IMG_Load(_filepath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return texture;
}

SDL_Texture* TextureManager::LoadTexture(SDL_Surface* _surface, SDL_Renderer* _renderer)
{
	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, _surface);
	SDL_FreeSurface(_surface);
	return texture;
}

SDL_Surface* TextureManager::LoadFile(const char* _filepath)
{
	SDL_Surface* tempSurface = IMG_Load(_filepath);
	return tempSurface;
}
