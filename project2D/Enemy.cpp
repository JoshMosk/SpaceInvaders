#include "Enemy.h"
#include "HitBox.h"
#include <math.h>

Enemy::Enemy(int xPos, int yPos)
{
	m_hitBox = new HitBox(true, xPos, yPos, 50, 50);
	m_canShoot = false;
}

Enemy::~Enemy()
{
	delete m_hitBox;
}

void Enemy::Move(float timer)
{
	m_hitBox->m_xPos += cos(timer) * 4;
}

void Enemy::Shoot()
{

}