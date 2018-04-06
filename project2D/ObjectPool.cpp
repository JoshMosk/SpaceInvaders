#include "ObjectPool.h"
#include "Laser.h"

ObjectPool::ObjectPool()
{
	Laser** m_pool = new Laser*[50];
	for (int i = 0; i < 50; i++)
	{
		m_pool[i] = new Laser;
	}
}

ObjectPool::~ObjectPool()
{
	for (int i = 0; i < 50; i++)
	{
		delete m_pool[i];
	}
	delete[] m_pool;
}
