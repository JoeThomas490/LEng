#include "LApplication.h"
#include "Rendering\LRenderer.h"
#include "States\LState.h"


LApplication::LApplication()
{
	printf("%s", "Engine running... \n");
	printf("%s", "******************\n");
}


LApplication::~LApplication()
{
	printf("%s", "Engine stopping... \n");
	printf("%s", "******************\n");
}

void LApplication::InitApplication(const LApplicationInitData & data)
{
	m_pRenderWindow = new RenderWindow(VideoMode(data.windowWidth, data.windowHeight), data.appName);
	m_pRenderer = new LRenderer();

	LInputManager::SetWindow(m_pRenderWindow);
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

		LInputManager::Update();

		//Poll events
		Event evt;
		while (m_pRenderWindow->pollEvent(evt))
		{
			if (evt.type == Event::Closed)
			{
				m_pRenderWindow->close();
			}
			else
			{
				LInputManager::HandleEvents(evt);
			}
		}

		m_pCurrentState->Update(m_dTime);

		m_pRenderer->Render();
	}
}


void LApplication::ClearApplication()
{
	LFREE(m_pRenderer);
	LFREE(m_pRenderWindow);
}

RenderWindow * LApplication::GetRenderWindow()
{
	return m_pRenderWindow;
}

LRenderer * LApplication::GetRenderer()
{
	return m_pRenderer;
}
