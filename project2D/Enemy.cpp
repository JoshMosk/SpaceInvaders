#include "Enemy.h"
#include "HitBox.h"
#include <math.h>

Enemy::Enemy(int xPos, int yPos)		//constructor sets the enemy's x and y postion
{
	m_hitBox = new HitBox(true, xPos, yPos, 50, 50);
	m_canShoot = false;
}

Enemy::~Enemy()
{
	delete m_hitBox;
}

void Enemy::Move(float timer)		//moves the enemy from one side of the screen to the other
{
	m_hitBox->m_xPos += cos(timer) * 4;
}

void Enemy::Shoot()
{

}