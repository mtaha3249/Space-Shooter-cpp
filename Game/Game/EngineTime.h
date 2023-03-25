#pragma once

class EngineTime
{
public:
	// deleting copy constructor
	EngineTime(const EngineTime& obj) = delete;

	static EngineTime* getInstance()
	{
		if (_instancePtr == nullptr)
		{
			_instancePtr = new EngineTime();
			return _instancePtr;
		}
		else {
			return _instancePtr;
		}
	}

	int FPS = 60;
	float deltaTime;

	float getFrameDelay() { return 1000 / FPS; }

private:
	static EngineTime* _instancePtr;

	EngineTime();
	~EngineTime()
	{
		delete _instancePtr;
	}
};

