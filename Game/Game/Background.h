#pragma once
#include "GameObject.h"
#include <SDL.h>
#include "TextureManager.h"

class Background :
    public GameObject
{
public:
    Background(const char* _filepath, SDL_Renderer* _renderer, Vector2 _position);

    void Update() override;
    void Draw() override;

    ~Background()
    {
    }
private:
    float _width, _height;
    SDL_Surface* _textureSurface;
    SDL_Texture* _texture;
    SDL_Renderer* _renderer;
    SDL_Rect destRect;
};

