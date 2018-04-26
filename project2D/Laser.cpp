#include "Laser.h"
#include "HitBox.h"

Laser::Laser()
{
	m_hitBox = new HitBox(false, -50, -50, 15, 50);
	m_hitBox->m_active = false;
}

Laser::~Laser()
{
	delete m_hitBox;
}

void Laser::Update(float deltatime)
{
	if (m_hitBox->m_active)
	{
		if (m_hitBox->m_yPos > 720)//if out of screen reset
		{
			m_hitBox->m_active = false;
			m_hitBox->m_xPos = -50;
			m_hitBox->m_yPos = -50;
		}



		m_hitBox->m_yPos += 350.0f * deltatime;
	}
}

void Laser::Shoot(float playerXPos)
{
	m_hitBox->m_active = true;
	m_hitBox->m_xPos = playerXPos;
	m_hitBox->m_yPos = 105;
}