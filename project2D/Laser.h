#pragma once
class Laser
{
public:
	Laser();
	~Laser();

	void Update(float deltatime);
	void Shoot(float playerXPos);

	float m_xPos;
	float m_yPos;

	bool active;
};

