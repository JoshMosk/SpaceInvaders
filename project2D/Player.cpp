#include "Player.h"
#include "HitBox.h"

Player::Player()
{
	m_hitBox = new HitBox();
	m_hitBox->m_xPos = 650;
}

Player::~Player()
{
	delete m_hitBox;
}
