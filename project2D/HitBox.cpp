#include "HitBox.h"

HitBox::HitBox(bool active, float x, float y, float w, float h)		//constructor sets all variables for hitbox
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

bool HitBox::CheckHit(HitBox* otherHitBox)
{

	if (m_active && otherHitBox->m_active)
	{
		float hitBoxOriginX = m_xPos - (m_width / 2);		//set x origin for where to start drawing the hitbox
		float hitBoxOriginY = m_yPos - (m_height / 2);		//set y origin for where to start drawing the hitbox
		float otherHitBoxOriginX = otherHitBox->m_xPos - (otherHitBox->m_width / 2);		//set x other hitbox's origin for where to start drawing the hitbox
		float otherHitBoxOriginY = otherHitBox->m_yPos - (otherHitBox->m_height / 2);		//set y other hitbox's origin for where to start drawing the hitbox

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
				return true;
			}
		}

	}
	return false;
}