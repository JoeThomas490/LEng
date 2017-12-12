#include "LApplication.h"
#include "LRenderer.h"


LApplication::LApplication()
{
}


LApplication::~LApplication()
{
}

void LApplication::InitApplication(const LApplicationInitData & data)
{
	m_pRenderWindow = new RenderWindow(VideoMode(data.windowWidth, data.windowHeight), data.appName);
	m_pRenderer = new LRenderer();
}

void LApplication::RunApplication()
{

	LGameObject testObj;

	testObj.setPosition(LengConstants::WINDOW_WIDTH / 2, LengConstants::WINDOW_HEIGHT / 2);
	m_pRenderer->AddToQueue(&testObj);


	Clock mClock;
	mClock.restart();

	//Main game loop
	while (m_pRenderWindow->isOpen())
	{

		m_dTime = mClock.restart().asSeconds();

		//Poll events
		Event evt;
		while (m_pRenderWindow->pollEvent(evt))
		{
			if (evt.type == Event::Closed)
			{
				m_pRenderWindow->close();
			}
		}

		{
			//m_pCurrentState->Update(0);
			float speed = 100.0f;
			testObj.setPosition(testObj.getPosition().x + (speed * m_dTime), testObj.getPosition().y);
		}

		m_pRenderer->Render();
	}
}

void LApplication::ClearApplication()
{
	delete m_pRenderer;
	m_pRenderer = nullptr;

	delete m_pRenderWindow;
	m_pRenderWindow = nullptr;
}

RenderWindow * LApplication::GetRenderWindow()
{
	return m_pRenderWindow;
}

LRenderer * LApplication::GetRenderer()
{
	return m_pRenderer;
}
