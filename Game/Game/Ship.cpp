#include "Ship.h"

Ship::Ship(const char* _filepath, SDL_Renderer* _renderer, Vector2 _position, Vector2 _scale)
{
	_transform._scale = _scale;
	this->_renderer = _renderer;
	this->_textureSurface = TextureManager::LoadFile(_filepath);

	_width = _textureSurface->w;
	_height = _textureSurface->h;

	this->_texture = TextureManager::LoadTexture(_textureSurface, _renderer);

	_transform._position = _position;
	_transform._scale = _scale;

	InitRigidBody();

	InputSystem::getInstance()->addListener(this);
}

void Ship::Update()
{
	move();

	destRect.x = _transform._position.x;
	destRect.y = _transform._position.y;
	destRect.w = _width * _transform._scale.x;
	destRect.h = _height * _transform._scale.y;
}

void Ship::InitRigidBody()
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.linearDamping = 0.02f;
	bodyDef.awake = true;
	bodyDef.gravityScale = 1.0f;

	this->_body = new Rigidbody(this->_transform, bodyDef);
	this->_collider = new BoxCollider();
	this->_collider->SetBoxCollider(this->_height, this->_width);
	this->_collider->Init(this, _body);

	b2MassData b2MassData;
	_body->_b2body->GetMassData(&b2MassData);
	b2MassData.mass = 1;
	b2MassData.center = b2Vec2(0, 0);
	_body->_b2body->SetMassData(&b2MassData);
}

void Ship::move()
{
	Vector2 movementVector = Vector2(0, 0);
	if (_movingRight)
	{
		movementVector.x = 1;
	}
	if (_movingLeft)
	{
		movementVector.x = -1;
	}
	if (_movingUp)
	{
		movementVector.y = -1;
	}
	if (_movingDown)
	{
		movementVector.y = 1;
	}
	// diagonal moving fast
	// multiply with 0.707f to slow down diagonal movement.
	// https://youtu.be/TSkR1HrOQ9I?t=386
	if (movementVector.x != 0 && movementVector.y != 0)
	{
		movementVector *= 0.707f;
	}
	//_transform._position += movementVector * _moveSpeed * EngineTime::deltaTime;
	this->_body->_b2body->ApplyForceToCenter(b2Vec2(movementVector.x * _moveSpeed, movementVector.y * _moveSpeed), true);
	_transform._position.x = _body->_b2body->GetPosition().x;
	_transform._position.y = _body->_b2body->GetPosition().y;

	boundToScreen();
}

void Ship::boundToScreen()
{
	//Vector2 clampedPosition = _transform._position;
	if (_transform._position.x + _width >= (SCREENWIDTH - BORDER))
	{
		// right
		//clampedPosition.x = (SCREENWIDTH - BORDER) - _width;
		_body->_b2body->SetLinearVelocity(b2Vec2(-1, 0));
		Helper::print("Right");
	}
	if (_transform._position.x <= (0 + BORDER))
	{
		// left
		//clampedPosition.x = 0 + BORDER;
		_body->_b2body->SetLinearVelocity(b2Vec2(1, 0));
		Helper::print("Left");
	}
	if (_transform._position.y + _height >= (SCREENHEIGHT - BORDER))
	{
		// bottom
		//clampedPosition.y = (SCREENHEIGHT - BORDER) - _height;
		_body->_b2body->SetLinearVelocity(b2Vec2(0, -1));
		Helper::print("Bottom");
	}
	if (_transform._position.y <= (0 + BORDER))
	{
		// top
		//clampedPosition.y = 0 + BORDER;
		_body->_b2body->SetLinearVelocity(b2Vec2(0, 1));
		Helper::print("Top");
	}
	//_transform._position = clampedPosition;
}

void Ship::Draw()
{
	SDL_RenderCopy(_renderer, _texture, NULL, &destRect);
	Helper::DrawRectangle(_renderer, Color(255, 0, 0, 255), Vector2(destRect.x, destRect.y), Vector2(destRect.w, destRect.h));
}

Ship::~Ship()
{
	InputSystem::getInstance()->removeListener(this);
}

void Ship::OnKeyDown(SDL_Keycode key)
{
	if (key == SDLK_d)
	{
		if (!_movingRight)
		{
			_movingRight = 1;
		}
	}
	if (key == SDLK_a)
	{
		if (!_movingLeft)
		{
			_movingLeft = 1;
		}
	}
	if (key == SDLK_w)
	{
		if (!_movingUp)
		{
			_movingUp = 1;
		}
	}
	if (key == SDLK_s)
	{
		if (!_movingDown)
		{
			_movingDown = 1;
		}
	}
}

void Ship::OnKeyUp(SDL_Keycode key)
{
	if (key == SDLK_d)
	{
		_movingRight = 0;
	}
	if (key == SDLK_a)
	{
		_movingLeft = 0;
	}
	if (key == SDLK_w)
	{
		_movingUp = 0;
	}
	if (key == SDLK_s)
	{
		_movingDown = 0;
	}
}