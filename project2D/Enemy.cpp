#include "Enemy.h"
#include "HitBox.h"
#include <math.h>

Enemy::Enemy(float xPos, float yPos)		//constructor sets the enemy's x and y postion
{
	m_hitBox = new HitBox(true, xPos, yPos, 50.0f, 50.0f);
	m_canShoot = false;
}

Enemy::~Enemy()
{
	delete m_hitBox;
}

void Enemy::Move(float timer, float downTimer)		//moves the enemy from one side of the screen to the other
{
	m_hitBox->m_xPos += sin(timer * 0.9f) * 4;

	if (downTimer > 3.5f)		//moves the enemies down the screen
	{
		m_hitBox->m_yPos -= 30;
	}
}

void Enemy::Shoot()
{
	//shoot at the player
}