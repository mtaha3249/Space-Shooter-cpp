#pragma once
#include "GameObject.h"
#include <SDL.h>
#include "TextureManager.h"

class Asteroids :
    public GameObject
{
public:
    Asteroids(const char* _filepath, SDL_Renderer* _renderer, Vector2 _position, int _size);
    Asteroids(const char* _filepath, SDL_Renderer* _renderer, Vector2 _position, Vector2 _scale, int _size);

    void Update() override;
    void Draw() override;

    ~Asteroids()
    {
    }
private:
    float _size;
    float _width, _height;
    SDL_Surface* _textureSurface;
    SDL_Texture* _texture;
    SDL_Renderer* _renderer;
    SDL_Rect destRect;

protected:
};

