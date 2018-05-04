#include "Player.h"
#include "HitBox.h"
#include <assert.h>

Player::Player()		//constructor sets the player's x and y position
{
	m_hitBox = new HitBox();
	assert(m_hitBox);
	m_hitBox->m_xPos = 640;
	m_hitBox->m_yPos = 80;
}

Player::~Player()
{
	delete m_hitBox;
}
