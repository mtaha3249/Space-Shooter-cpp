#pragma once
#include <SDL.h>
#include "SDL_Image.h"

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* _filepath, SDL_Renderer* _renderer);
	static SDL_Texture* LoadTexture(SDL_Surface* _surface, SDL_Renderer* _renderer);
	static SDL_Surface* LoadFile(const char* _filepath);
};

