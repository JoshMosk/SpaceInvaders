#include "Laser.h"
#include "HitBox.h"
#include <assert.h>

Laser::Laser()		//creates a laser with default parameters 
{
	m_hitBox = new HitBox(false, -50, -50, 30, 30);
	assert(m_hitBox);
	m_hitBox->m_active = false;
}

Laser::~Laser()
{
	delete m_hitBox;
}

void Laser::Update(float deltatime)		//updates the laser's position
{
	if (m_hitBox->m_active)
	{
		if (m_hitBox->m_yPos > 720)		//if out of screen reset
		{
			m_hitBox->m_active = false;
			m_hitBox->m_xPos = -50;
			m_hitBox->m_yPos = -50;
		}

		m_hitBox->m_yPos += 500.0f * deltatime;
	}
}

void Laser::Shoot(float playerXPos)		//start the laser's shooting process
{
	m_hitBox->m_active = true;
	m_hitBox->m_xPos = playerXPos;
	m_hitBox->m_yPos = 105;
}