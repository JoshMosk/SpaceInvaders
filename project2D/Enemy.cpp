#include "Enemy.h"

Enemy::Enemy(int xPos, int yPos)
{
	m_canShoot = false;
	m_isActive = true;

	m_xPos = xPos;
	m_yPos = yPos;
}

Enemy::~Enemy()
{
	
}

void Enemy::Move()
{

}

void Enemy::Shoot()
{

}