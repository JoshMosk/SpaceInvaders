#include "Player.h"
#include "HitBox.h"

Player::Player()		//constructor sets the player's x and y position
{
	m_hitBox = new HitBox();
	m_hitBox->m_xPos = 650;
	m_hitBox->m_yPos = 50;
}

Player::~Player()
{
	delete m_hitBox;
}
