#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "ObjectPool.h"
#include "Laser.h"

Application2D::Application2D() 
{

}

Application2D::~Application2D() 
{

}

bool Application2D::startup() 
{
	
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/numbered_grid.tga");

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_shipTexture = new aie::Texture("./textures/ship.png");
	m_laserTexture = new aie::Texture("./textures/laser.png");
	m_alienTexture = new aie::Texture("./textures/alien.png");
	m_BackgroundTexture = new aie::Texture("./textures/background.png");

	//m_cameraX = 0;
	//m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() 
{
	delete m_BackgroundTexture;
	delete m_alienTexture;
	delete m_laserTexture;
	delete m_shipTexture;
	delete m_font;
	delete m_texture;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;
	m_shootTimer += deltaTime;

	for (int i = 0; i < m_lasers.m_maxIndex; i++)
	{
		m_lasers.m_pool[i]->Update(deltaTime);
	}

	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera
	//if (input->isKeyDown(aie::INPUT_KEY_UP))
	//	m_cameraY += 500.0f * deltaTime;

	//if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	//	m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_player.m_xPos -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_player.m_xPos += 500.0f * deltaTime;

	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE) && m_shootTimer > 0.7f) //shoots bullets if scpace key is pressed and shoot timer is high enough
	{
		if (m_nextLaser == m_lasers.m_maxIndex)
		{
			m_nextLaser = 0;
		}

		m_lasers.m_pool[m_nextLaser]->Shoot(m_player.m_xPos);

		m_nextLaser++;
		m_shootTimer = 0;
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	//m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	//draw background
	m_2dRenderer->drawSprite(m_BackgroundTexture, 0, 0, 1280, 720, 0, 100, 0, 0);

	// demonstrate animation
	m_2dRenderer->setUVRect(int(m_timer) % 8 / 8.0f, 0, 1.f / 8, 1.f / 8);
	m_2dRenderer->drawSprite(m_texture, 200, 200, 100, 100);

	// draw the player
	m_2dRenderer->setUVRect(0,0,1,1);
	m_2dRenderer->drawSprite(m_shipTexture, m_player.m_xPos, 50, 0, 0, 0, 1);		//JM:STARTHERE, need to get player in front of background

	// draw an enemy sprite
	for (int i = 0; i < m_enemies.m_maxIndex; i++)
	{
		if (m_enemies.m_pool[i]->m_isActive)
		{
			m_2dRenderer->drawSprite(m_alienTexture, sin(m_timer / 3) * 280 + m_enemies.m_pool[i]->m_xPos, m_enemies.m_pool[i]->m_yPos, 0, 0, 0, 0);
		}
	}

	for (int i = 0; i < m_lasers.m_maxIndex; i++) //draw lasers
	{
		if (m_lasers.m_pool[i]->active)
		{
			m_2dRenderer->drawSprite(m_laserTexture, m_lasers.m_pool[i]->m_xPos, m_lasers.m_pool[i]->m_yPos, 0, 0, 0, 1);
		}
	}

	// draw a thin line
	m_2dRenderer->drawLine(300, 300, 600, 400, 2, 1);

	// draw a moving purple circle
	m_2dRenderer->setRenderColour(1, 0, 1, 1);
	m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	// draw a rotating red box
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	// draw a slightly rotated sprite with no texture, coloured yellow
	m_2dRenderer->setRenderColour(1, 1, 0, 1);
	m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);
	
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}