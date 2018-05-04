#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "ObjectPool.h"
#include "Laser.h"
#include "HitBox.h"
#include <assert.h>

Application2D::Application2D() 
{

}

Application2D::~Application2D() 
{

}

bool Application2D::startup()		//create variables on the heap
{
	
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_shipTexture = new aie::Texture("./textures/shipanim.png");
	m_laserTexture = new aie::Texture("./textures/laser.png");
	m_alienTexture = new aie::Texture("./textures/alien.png");
	m_BackgroundTexture = new aie::Texture("./textures/backgroundHD.png");

	m_lasers = new ObjectPool<Laser>(5);
	m_enemies = new ObjectPool<Enemy>(10, 50, 640);

	assert(m_2dRenderer);
	assert(m_font);
	assert(m_shipTexture);
	assert(m_laserTexture);
	assert(m_alienTexture);
	assert(m_BackgroundTexture);
	assert(m_lasers);
	assert(m_enemies);

	m_timer = 0;

	return true;
}

void Application2D::shutdown()		//delete variables on the heap
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
	m_downTimer += deltaTime;

	for (int i = 0; i < m_lasers->m_maxIndex; i++)		//checks for a hit between the lasers and enemies
	{
		for (int j = 0; j < m_enemies->m_maxIndex; j++)
		{
			if (m_lasers->m_pool[i]->m_hitBox->CheckHit(m_enemies->m_pool[j]->m_hitBox))		//if hit set active of both enemy and laser hitbox to false
			{
				m_lasers->m_pool[i]->m_hitBox->m_active = false;
				m_enemies->m_pool[j]->m_hitBox->m_active = false;
			}
		}
	}

	for (int i = 0; i < m_enemies->m_maxIndex; i++)		//checks to see if the player has won or lost
	{
		if (m_gameState != GAMESTATE_LOST)
		{
			if (m_enemies->m_pool[i]->m_hitBox->m_yPos < 200 && m_enemies->m_pool[i]->m_hitBox->m_active)
			{
				for (int i = 0; i < m_enemies->m_maxIndex; i++)
				{
					m_enemies->m_pool[i]->m_hitBox->m_yPos = -50;
				}
				m_gameState = GAMESTATE_LOST;
				break;
			}
			else if (m_enemies->m_pool[i]->m_hitBox->m_active)
			{
				m_gameState = GAMESTATE_PLAYING;
				break;
			}
			else
			{
				m_gameState = GAMESTATE_WON;
			}
		}
	}

	//input
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))		//move the player left
		m_player.m_hitBox->m_xPos -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))		//move the player right
		m_player.m_hitBox->m_xPos += 500.0f * deltaTime;

	if (input->wasKeyPressed(aie::INPUT_KEY_SPACE) && m_shootTimer > 0.7f)		//shoots bullets if space key is pressed and shoot timer is high enough
	{
		if (m_nextLaser == m_lasers->m_maxIndex)		//checks to see if m_nextLaser is the the end of the lasers objectpool
		{
			m_nextLaser = 0;
		}

		m_lasers->m_pool[m_nextLaser]->Shoot(m_player.m_hitBox->m_xPos);		//shoots the laser

		m_nextLaser++;
		m_shootTimer = 0;		//resets the timer for shoot
	}
	for (int i = 0; i < m_lasers->m_maxIndex; i++)		//update the lasers position
	{
		m_lasers->m_pool[i]->Update(deltaTime);
	}

	for (int i = 0; i < m_enemies->m_maxIndex; i++)		//update the enemies' position
	{
		m_enemies->m_pool[i]->Move(m_timer, m_downTimer);
	}

	if (m_downTimer > 3.5f)		//resets the downtimer for the enemies
	{
		m_downTimer = 0.0f;
	}

	//exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() 
{
	clearScreen();		//wipe the screen to the background colour
	
	m_2dRenderer->begin();		//begin drawing sprites

	m_2dRenderer->drawSprite(m_BackgroundTexture, 0, 0, 1280, 720, 0, 100, 0, 0);		//draw background

	m_2dRenderer->setUVRect(int(m_timer * 2) % 6 / 6.0f, 0, 0.166f, 1);		//set the UV for the ship animation

	m_2dRenderer->drawSprite(m_shipTexture, m_player.m_hitBox->m_xPos, m_player.m_hitBox->m_yPos, 96, 96, 0, 1);		// draw the player

	m_2dRenderer->setUVRect(0,0,1,1);		//set the UV for drawing sprites
	
	for (int i = 0; i < m_enemies->m_maxIndex; i++)		// draw enemies
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

	char fps[32];
	char centerScreenMessage[32];

	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);
	
	if (m_gameState == GAMESTATE_WON)		//outputs "you win!" to center of screen
	{
		sprintf_s(centerScreenMessage, 32, "You Win!");
		m_2dRenderer->drawText(m_font, centerScreenMessage, 640 - 72, 360 - 12);
	}
	if (m_gameState == GAMESTATE_LOST)		//outputs "you lost!" to center of screen
	{
		sprintf_s(centerScreenMessage, 32, "You Lost!");
		m_2dRenderer->drawText(m_font, centerScreenMessage, 640 - 72, 360 - 12);
	}
	
	m_2dRenderer->end();		//done drawing sprites
}