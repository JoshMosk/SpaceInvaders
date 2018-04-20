#include "HitBox.h"

HitBox::HitBox()
{

}

HitBox::~HitBox()
{

}

bool HitBox::CheckHit(HitBox otherHitBox)
{

	if (otherHitBox.m_active)
	{
		float hitBoxOriginX = m_xPos - (m_width / 2);
		float hitBoxOriginY = m_yPos - (m_height / 2);
		float otherHitBoxOrigin = otherHitBox.m_xPos - (otherHitBox.m_width / 2);
		float otherHitBoxOrigin = otherHitBox.m_yPos - (otherHitBox.m_height / 2);
		if ()
	}
	//if width and height of other hitbox is within limits of current hitbox then true
	//which means i need a x and y of both other and self
	//and then we cast out width and height from origin point 
}