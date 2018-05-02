#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Player.h"
#include "ObjectPool.h"
#include "Laser.h"
#include "Enemy.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:
	
	Player m_player;		//the player
	ObjectPool<Laser>* m_lasers;		//the laser objectpool
	ObjectPool<Enemy>* m_enemies;		//the enemy objectpool

	int m_nextLaser = 0;		//keeps track of the next laser to use in the laser objectpool
	float m_shootTimer = 0;		//keeps track of the cooldown for the laser firing

	aie::Texture*		m_laserTexture;		//the textures for the laser, ship, aliens and background
	aie::Texture*		m_shipTexture;
	aie::Texture*		m_alienTexture;
	aie::Texture*		m_BackgroundTexture;

	aie::Renderer2D*	m_2dRenderer;		//part of the bootstrap
	aie::Font*			m_font;		//part of the bootstrap

	float m_timer;		//keeps track of the time
};