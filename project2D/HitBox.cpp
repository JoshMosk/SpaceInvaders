#include "HitBox.h"

HitBox::HitBox(bool active, float x, float y, float w, float h)
{
	m_active = active;
	m_xPos = x;
	m_yPos = y;
	m_width = w;
	m_height = h;
}

HitBox::~HitBox()
{

}

bool HitBox::CheckHit(HitBox* otherHitBox)		//JM:STARTHERE
{

	if (m_active && otherHitBox->m_active)
	{
		float hitBoxOriginX = m_xPos - (m_width / 2);
		float hitBoxOriginY = m_yPos - (m_height / 2);
		float otherHitBoxOriginX = otherHitBox->m_xPos - (otherHitBox->m_width / 2);
		float otherHitBoxOriginY = otherHitBox->m_yPos - (otherHitBox->m_height / 2);

		//if origin point X is within other hitbox X

		//if width is within other hitbox X

		//if other origin X is within hitbox X

		//if other width is within hitbox X

		if		//check x
			(((hitBoxOriginX >= otherHitBoxOriginX											&&		//if origin point X is within other hitbox X
			hitBoxOriginX <= (otherHitBoxOriginX + otherHitBox->m_width))					||
			(hitBoxOriginX + m_width >= otherHitBoxOriginX									&&		//if width is within other hitbox X
			hitBoxOriginX + m_width <= otherHitBoxOriginX + otherHitBox->m_width))			||
			((otherHitBoxOriginX >= hitBoxOriginX											&&		//if other origin X is within hitbox X
			otherHitBoxOriginX <= hitBoxOriginX + m_width)									||
			(otherHitBoxOriginX + otherHitBox->m_width >= hitBoxOriginX						&&		//if other width is within hitbox X
			otherHitBoxOriginX + otherHitBox->m_width <= hitBoxOriginX + m_width)))
		{
			if		//check y
				(((hitBoxOriginY >= otherHitBoxOriginY										&&		//if origin point X is within other hitbox X
				hitBoxOriginY <= (otherHitBoxOriginY + otherHitBox->m_height))				||
				(hitBoxOriginY + m_height >= otherHitBoxOriginY								&&		//if width is within other hitbox X
				hitBoxOriginY + m_height <= otherHitBoxOriginY + otherHitBox->m_height))	||
				((otherHitBoxOriginY >= hitBoxOriginY										&&		//if other origin X is within hitbox X
				otherHitBoxOriginY <= hitBoxOriginY + m_height)								||
				(otherHitBoxOriginY + otherHitBox->m_height >= hitBoxOriginY				&&		//if other width is within hitbox X
				otherHitBoxOriginY + otherHitBox->m_height <= hitBoxOriginY + m_height)))		
			{
				return true;
			}
		}



		////check y
		//if (m_height < otherHitBox->m_height)		//check to see which box is taller
		//{
		//	if ((hitBoxOriginY >= otherHitBoxOriginY &&
		//		hitBoxOriginY <= (otherHitBoxOriginY + otherHitBox->m_height)) ||		//if origin point Y is within other hitbox Y
		//		((hitBoxOriginY + m_height) >= otherHitBoxOriginY &&
		//		(hitBoxOriginY + m_height) <= (otherHitBoxOriginY + otherHitBox->m_height)))		//if height is within other hitbox Y
		//	{
		//	}
		//}
		//else 
		//if	((otherHitBoxOriginY >= hitBoxOriginY &&
		//	otherHitBoxOriginY <= (hitBoxOriginY + m_height)) ||		//if other origin Y is within hitbox Y
		//	((otherHitBoxOriginY + otherHitBox->m_height) >= hitBoxOriginY &&
		//	(otherHitBoxOriginY + otherHitBox->m_height) <= (hitBoxOriginY + m_height)))		//if other height is within hitbox Y
		//{
		//}

	}
	return false;
}