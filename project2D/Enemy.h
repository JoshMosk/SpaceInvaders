#pragma once

class HitBox;

class Enemy
{
public:
	Enemy(int xPos, int yPos);
	~Enemy();

	void Move();
	void Shoot();

	HitBox* m_hitBox;

	bool m_canShoot;
};