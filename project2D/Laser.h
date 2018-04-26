#pragma once

class HitBox;

class Laser
{
public:
	Laser();
	~Laser();

	void Update(float deltatime);
	void Shoot(float playerXPos);

	HitBox* m_hitBox;
};

