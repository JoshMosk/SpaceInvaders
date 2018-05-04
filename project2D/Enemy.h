#pragma once

class HitBox;

class Enemy
{
public:
	Enemy(float xPos, float yPos);
	~Enemy();

	void Move(float timer, float downTimer);
	void Shoot();

	HitBox* m_hitBox;

	bool m_canShoot;
};