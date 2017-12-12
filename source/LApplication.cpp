#include "LApplication.h"



LApplication::LApplication()
{
}


LApplication::~LApplication()
{
}

void LApplication::InitApplication(const LApplicationInitData & data)
{
	m_pRenderWindow = new RenderWindow(VideoMode(data.windowWidth, data.windowHeight), data.appName);
}

void LApplication::RunApplication()
{
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



	}
}

RenderWindow * LApplication::GetWindowInstance()
{
	return m_pRenderWindow;
}
