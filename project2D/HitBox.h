#pragma once
class HitBox
{
public:
	HitBox(bool active = true, float x = 0, float y = 0, float w = 0, float h = 0);		//constructor has defaults in the case of no initialisation
	~HitBox();

	bool CheckHit(HitBox* hitBox);

	bool m_active;

	float m_xPos;
	float m_yPos;
	float m_width;
	float m_height;
};

