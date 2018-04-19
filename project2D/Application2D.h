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
	
	Player m_player;
	ObjectPool<Laser> m_lasers = ObjectPool<Laser>(50);
	ObjectPool<Enemy> m_enemies = ObjectPool<Enemy>(10, 70);



	int m_nextLaser = 0;
	float m_shootTimer = 0;

	aie::Texture*		m_laserTexture;
	aie::Texture*		m_shipTexture;
	aie::Texture*		m_alienTexture;
	aie::Texture*		m_BackgroundTexture;

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_texture;
	aie::Font*			m_font;

	float m_cameraX, m_cameraY;
	float m_timer;
};