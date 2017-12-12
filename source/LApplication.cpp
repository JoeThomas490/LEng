#include "LApplication.h"
#include "Rendering\LRenderer.h"
#include "States\LState.h"


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

	Clock mClock;
	mClock.restart();

	TestState testState;

	testState.InitState();
	m_pCurrentState = &testState;

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

		m_pCurrentState->Update(m_dTime);

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
