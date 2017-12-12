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

	m_pRenderer->AddToQueue(&testObj);


	//Main game loop
	while (m_pRenderWindow->isOpen())
	{
		//Poll events
		Event evt;
		while (m_pRenderWindow->pollEvent(evt))
		{
			if (evt.type == Event::Closed)
			{
				m_pRenderWindow->close();
			}
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

RenderWindow * LApplication::GetWindowInstance()
{
	return m_pRenderWindow;
}
