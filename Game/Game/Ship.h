#pragma once
#include "GameObject.h"
#include <SDL.h>
#include "TextureManager.h"
#include "InputListener.h"
#include "InputSystem.h"
#include "EngineTime.h"
#include "Engine.h"
#include <string>
#include <iostream>

class Ship :
    public GameObject, InputListener
{
public:
    Ship(const char* _filepath, SDL_Renderer* _renderer, Vector2 _position, int _size);
    Ship(const char* _filepath, SDL_Renderer* _renderer, Vector2 _position, Vector2 _scale, int _size);

    void Update() override;
    void Draw() override;

    ~Ship();
private:
    float _size;
    float _width, _height;
    SDL_Surface* _textureSurface;
    SDL_Texture* _texture;
    SDL_Renderer* _renderer;
    SDL_Rect destRect;
    float _moveSpeed = 0.1f;
    int _movingRight, _movingLeft, _movingUp, _movingDown = 0;

    void move();
    void boundToScreen();

protected:
    // Inherited via InputListener
    virtual void OnKeyDown(SDL_Keycode key) override;

    virtual void OnKeyUp(SDL_Keycode key) override;

};

