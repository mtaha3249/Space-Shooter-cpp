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

	InitRigidBody();
	InitDirection();
	InitMoveSpeed();

	_body->_b2body->ApplyLinearImpulseToCenter(b2Vec2(Helper::random(0, 2), 0), true);
	_body->_b2body->ApplyTorque(Helper::random(10000000, 100000000), true);
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

	InitRigidBody();
	InitDirection();
	InitMoveSpeed();

	_body->_b2body->ApplyLinearImpulseToCenter(b2Vec2(2 * _direction, 0), true);
	_body->_b2body->ApplyTorque(Helper::random(10000000, 100000000), true);
}

void Asteroids::Update()
{
	//_transform._position += Vector2(1, 0) * EngineTime::deltaTime;

	_transform._position.x = _body->_b2body->GetPosition().x;
	_transform._position.y = _body->_b2body->GetPosition().y;
	_transform._rotation.y = _body->_b2body->GetAngle();

	// drawing
	_destRect.x = _transform._position.x;
	_destRect.y = _transform._position.y;
	_destRect.w = _width * _transform._scale.x;
	_destRect.h = _height * _transform._scale.y;
	_center.x = _destRect.w / 2;
	_center.y = _destRect.h / 2;
}

void Asteroids::Draw()
{
	SDL_RenderCopyEx(_renderer, _texture, NULL, &_destRect, _transform._rotation.y, &_center, SDL_FLIP_NONE);
}

void Asteroids::InitRigidBody()
{
	this->_body = new Rigidbody(this->_transform);
	this->collider = new CircleCollider();
	this->collider->SetCircleCollider(this->_size);
	this->collider->Init(this, _body);

	b2MassData b2MassData;
	_body->_b2body->GetMassData(&b2MassData);
	b2MassData.mass = 1;
	b2MassData.center = b2Vec2(0, 0);
	_body->_b2body->SetMassData(&b2MassData);
}

void Asteroids::InitMoveSpeed()
{
	_moveSpeed = Helper::random(1.0f, 3.0f);
	Helper::print(_moveSpeed);
}

void Asteroids::InitDirection()
{
	_direction = Helper::random(-1, 1);
	_direction = _direction == 0 ? 1 : _direction;
}
