#include "Laser.h"

Laser::Laser()
{
	active = false;
	m_xPos = -50;
	m_yPos = -50;
}

Laser::~Laser()
{

}

void Laser::Update(float deltatime)
{
	if (active)
	{
		if (m_yPos > 720)//if out of screen reset
		{
			active = false;
			m_xPos = -50;
			m_yPos = -50;
		}

		m_yPos += 300.0f * deltatime;
	}
}

void Laser::Shoot(float playerXPos)
{
	active = true;
	m_xPos = playerXPos;
	m_yPos = 105;
}