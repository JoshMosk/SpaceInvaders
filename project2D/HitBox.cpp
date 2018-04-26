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

		if		//check x
			(((hitBoxOriginX >= otherHitBoxOriginX										&&
			hitBoxOriginX <= (otherHitBoxOriginX + otherHitBox->m_width))				||		//if origin point X is within other hitbox X
			(hitBoxOriginX + m_width >= otherHitBoxOriginX								&&
			hitBoxOriginX + m_width <= otherHitBoxOriginX + otherHitBox->m_width))		||		//if width is within other hitbox X
			((otherHitBoxOriginX >= hitBoxOriginX										&&
			otherHitBoxOriginX <= hitBoxOriginX + m_width)								||		//if other origin X is within hitbox X
			(otherHitBoxOriginX + otherHitBox->m_width >= hitBoxOriginX				&&
			otherHitBoxOriginX + otherHitBox->m_width <= hitBoxOriginX + m_width)))			//if other width is within hitbox X
		{
			if		//check y
				(((hitBoxOriginY >= otherHitBoxOriginY										&&
				hitBoxOriginY <= (otherHitBoxOriginY + otherHitBox->m_height))				||		//if origin point X is within other hitbox X
				(hitBoxOriginY + m_height >= otherHitBoxOriginY							&&
				hitBoxOriginY + m_height <= otherHitBoxOriginY + otherHitBox->m_height)) 	||		//if width is within other hitbox X
				((otherHitBoxOriginY >= hitBoxOriginY 										&&
				otherHitBoxOriginY <= hitBoxOriginY + m_height)							||		//if other origin X is within hitbox X
				(otherHitBoxOriginY + otherHitBox->m_height >= hitBoxOriginY				&&
				otherHitBoxOriginY + otherHitBox->m_height <= hitBoxOriginY + m_height)))			//if other width is within hitbox X
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