#pragma once

class Enemy
{
public:
	Enemy(int xPos, int yPos);
	~Enemy();

	void Move();
	void Shoot();

	float m_xPos;
	float m_yPos;

	bool m_isActive;
	bool m_canShoot;
};