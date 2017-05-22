#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Vector2.h"

class GameProjectApp : public aie::Application {
public:

	GameProjectApp();
	virtual ~GameProjectApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	Vector2      m_PlayerCircle;
	int playerSpeed;
	int playerSize;
	int defaultSpeed;
	int BOOST;
	bool drawBOOST;
};