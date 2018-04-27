#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "ObjectPool.h"
#include "Laser.h"
#include "HitBox.h"

Application2D::Application2D() 
{

}

Application2D::~Application2D() 
{

}

bool Application2D::startup() 
{
	
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_laserTexture = new aie::Texture("./textures/laser.png");
	m_alienTexture = new aie::Texture("./textures/alien.png");
	m_BackgroundTexture = new aie::Texture("./textures/background.png");

	m_lasers = new ObjectPool<Laser>(5);
	m_enemies = new ObjectPool<Enemy>(10, 70);

	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	delete m_enemies;
	delete m_lasers;
	delete m_BackgroundTexture;
	delete m_alienTexture;
	delete m_laserTexture;
	delete m_shipTexture;
	delete m_font;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;
	m_shootTimer += deltaTime;

	for (int i = 0; i < m_lasers->m_maxIndex; i++)
	{
		for (int j = 0; j < m_enemies->m_maxIndex; j++)
		{
			if (m_lasers->m_pool[i]->m_hitBox->CheckHit(m_enemies->m_pool[j]->m_hitBox))
			{
				m_lasers->m_pool[i]->m_hitBox->m_active = false;
				m_enemies->m_pool[j]->m_hitBox->m_active = false;
			}
		}
		m_lasers->m_pool[i]->Update(deltaTime);
	}

	// input example
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_player.m_hitBox->m_xPos -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_player.m_hitBox->m_xPos += 500.0f * deltaTime;

	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE) && m_shootTimer > 0.7f) //shoots bullets if space key is pressed and shoot timer is high enough
	{
		if (m_nextLaser == m_lasers->m_maxIndex)
		{
			m_nextLaser = 0;
		}

		m_lasers->m_pool[m_nextLaser]->Shoot(m_player.m_hitBox->m_xPos);

		m_nextLaser++;
		m_shootTimer = 0;
	}

	for (int i = 0; i < m_enemies->m_maxIndex; i++)
	{
		m_enemies->m_pool[i]->Move(m_timer);
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() 
{

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	//m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	//draw background
	m_2dRenderer->drawSprite(m_BackgroundTexture, 0, 0, 1280, 720, 0, 100, 0, 0);

	// demonstrate animation
	//m_2dRenderer->setUVRect(int(m_timer) % 6 / 6.0f, 0, 0.166f, 1);
	m_2dRenderer->drawSprite(m_shipTexture, 400, 400, 128, 128);

	// draw the player
	m_2dRenderer->drawSprite(m_shipTexture, m_player.m_hitBox->m_xPos, 50, 96, 96, 0, 1);		
	m_2dRenderer->setUVRect(0,0,1,1);

	
	for (int i = 0; i < m_enemies->m_maxIndex; i++)		// draw an enemy sprite
	{
		if (m_enemies->m_pool[i]->m_hitBox->m_active)
		{
			m_2dRenderer->drawSprite(m_alienTexture, m_enemies->m_pool[i]->m_hitBox->m_xPos, m_enemies->m_pool[i]->m_hitBox->m_yPos, 0, 0, 0, 0);
		}
	}
	for (int i = 0; i < m_lasers->m_maxIndex; i++)		//draw lasers
	{
		if (m_lasers->m_pool[i]->m_hitBox->m_active)
		{
			m_2dRenderer->drawSprite(m_laserTexture, m_lasers->m_pool[i]->m_hitBox->m_xPos, m_lasers->m_pool[i]->m_hitBox->m_yPos, 0, 0, 0, 1);
		}
	}
	
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}