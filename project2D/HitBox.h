#pragma once
class HitBox
{
public:
	HitBox();
	~HitBox();

	bool CheckHit(HitBox hitBox);

	bool m_active;

	float m_xPos;
	float m_yPos;
	float m_width;
	float m_height;
};

