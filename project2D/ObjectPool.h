#pragma once

template<typename T>
class ObjectPool
{
public:
	ObjectPool(int maxIndex)
	{
		m_maxIndex = maxIndex;
		m_pool = new T*[m_maxIndex];
		for (int i = 0; i < m_maxIndex; i++)
		{
			m_pool[i] = new T();
		}
	}

	ObjectPool(int maxIndex, float space)		//used for enemies and their spacing
	{
		m_maxIndex = maxIndex;
		m_pool = new T*[m_maxIndex];
		for (int i = 0; i < m_maxIndex; i++)
		{
			m_pool[i] = new T(i * space + 320, 640);
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

