#pragma once

template<typename T>
class ObjectPool
{
public:
	ObjectPool(int maxIndex)		//creates an array of maxIndex length
	{
		m_maxIndex = maxIndex;
		m_pool = new T*[m_maxIndex];
		for (int i = 0; i < m_maxIndex; i++)
		{
			m_pool[i] = new T();
		}
	}

	ObjectPool(int maxIndex, float xPos, float yPos)		//mainly used for enemy class but can be used for anything with a hitbox defined in the contructor
	{
		m_maxIndex = maxIndex;
		m_pool = new T*[m_maxIndex];
		for (int i = 0; i < m_maxIndex; i++)
		{
			m_pool[i] = new T(i * xPos, yPos);
		}
	}

	~ObjectPool()
	{
		for (int i = 0; i < m_maxIndex; i++)
		{
			delete m_pool[i];
		}
		delete[] m_pool;
	}

	int m_maxIndex;
	T** m_pool;
};

