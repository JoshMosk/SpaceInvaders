#pragma once
#include "Laser.h"

class ObjectPool
{
public:
	ObjectPool();
	~ObjectPool();

	Laser** m_pool;
};

