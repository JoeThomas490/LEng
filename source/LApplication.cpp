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

	TestState* testState = new TestState();

	TestState* testState2 = new TestState();

	AddState(testState);
	AddState(testState2);

	ChangeState(testState);

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

				if (LInputManager::IsKeyPressed(Keyboard::Key::C))
				{
					ChangeState(testState2->GetStateNumber());
				}
			}
		}

		m_pCurrentState->Update(m_dTime);

		m_pRenderer->Render();
	}

	delete testState;
	testState = nullptr;
	delete testState2;
	testState = nullptr;
}

void LApplication::AddState(LState* mState)
{
	m_vStateList.push_back(mState);
	mState->SetStateNumber(m_vStateList.size() - 1);
}

void LApplication::ChangeState(LState* mState)
{
	if (m_pCurrentState == nullptr)
	{
		m_pCurrentState = mState;
		m_pCurrentState->InitState();
		return;
	}
	else
	{
		m_pCurrentState->ShutdownState();
		m_pCurrentState = mState;
		m_pCurrentState->InitState();
	}

	//TODO Add Initialise checks to states and report an error if init fails
}

void LApplication::ChangeState(int mStateIndex)
{
	if (mStateIndex > 0 && mStateIndex < m_vStateList.size())
	{
		m_pCurrentState->ShutdownState();
		m_pCurrentState = m_vStateList[mStateIndex];
		m_pCurrentState->InitState();
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
