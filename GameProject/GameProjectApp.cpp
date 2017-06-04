#include "GameProjectApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>
#include "DynamicArray.h"
#include "LinkedList.h"
#include <ctime>
#include <assert.h>

GameProjectApp::GameProjectApp() {
}

GameProjectApp::~GameProjectApp() {

}

bool GameProjectApp::startup() {


	m_2dRenderer = new aie::Renderer2D();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	//player position
	m_PlayerCircle[0] = getWindowWidth() / 2;
	m_PlayerCircle[1] = getWindowHeight() / 2;

	//player variables
	playerSize = 20;

	defaultSpeed = 300;
	BOOST = 800;

	//----------FSM----------

	return true;
}

void GameProjectApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
}

void GameProjectApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();


	//changing states
	if (input->wasKeyPressed(aie::INPUT_KEY_RIGHT))
	{

	}
	if (input->wasKeyPressed(aie::INPUT_KEY_LEFT))
	{

	}

	//moving player
	if (input->isKeyDown(aie::INPUT_KEY_W))
		m_PlayerCircle[1] += playerSpeed * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_S))
		m_PlayerCircle[1] -= playerSpeed * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_A))
		m_PlayerCircle[0] -= playerSpeed * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_D))
		m_PlayerCircle[0] += playerSpeed * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_SPACE)){
		playerSpeed = BOOST;
		drawBOOST = true;
	}
	else {
		playerSpeed = defaultSpeed;
		drawBOOST = false;
	}


	//simple collider stopping player leaving screen
	if (m_PlayerCircle[0] > getWindowWidth() - playerSize)
		m_PlayerCircle[0] = getWindowWidth() - playerSize;
	if(m_PlayerCircle[0] < 0 + playerSize)
		m_PlayerCircle[0] = 0 + playerSize;
	if (m_PlayerCircle[1] > getWindowHeight() - playerSize)
		m_PlayerCircle[1] = getWindowHeight() - playerSize;
	if (m_PlayerCircle[1] < 0 + playerSize)
		m_PlayerCircle[1] = 0 + playerSize;

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void GameProjectApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	m_2dRenderer->setRenderColour(1, 1, 0);

	if (drawBOOST == true)
	{
		m_2dRenderer->setRenderColour(0, 1, 1, 1);
		m_2dRenderer->drawText(m_font, "BOOST", m_PlayerCircle[0] + 30, m_PlayerCircle[1] + 30);
		m_2dRenderer->setRenderColour(1, 0, 0);
	}

	// draw your stuff here!
	//draw the player and player colour
	m_2dRenderer->drawCircle(m_PlayerCircle[0], m_PlayerCircle[1], playerSize);

	m_2dRenderer->setRenderColour(1, 1, 1);
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}
