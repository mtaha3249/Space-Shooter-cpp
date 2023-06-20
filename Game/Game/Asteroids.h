#pragma once
#include "GameObject.h"
#include <SDL.h>
#include "TextureManager.h"
#include "EngineTime.h"
#include "Rigidbody.h"
#include "Collider.h"
#include "CircleCollider.h"
#include "Engine.h"
#include "Helper.h"

class Asteroids :
    public GameObject
{
public:
    Asteroids(const char* _filepath, SDL_Renderer* _renderer, Vector2 _position, int _size);
    Asteroids(const char* _filepath, SDL_Renderer* _renderer, Vector2 _position, Vector2 _scale, int _size);

    void Update() override;
    void Draw() override;

    Rigidbody* _body;
    CircleCollider* collider;

    ~Asteroids()
    {
    }
private:
    float _size;
    float _width, _height;
    float _moveSpeed;
    int _direction;
    SDL_Surface* _textureSurface;
    SDL_Texture* _texture;
    SDL_Renderer* _renderer;
    SDL_Rect _destRect;
    SDL_Point _center;

    void InitRigidBody();
    void InitMoveSpeed();
    void InitDirection();

protected:
};

