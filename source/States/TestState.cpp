#include "States\TestState.h"


TestState::TestState()
{
	m_bStateInitialised = false;
}

void TestState::InitState()
{
	testObj = new LGameObject(LPrimitive::LSQUARE, Vector2f(50, 50), Vector2f(50, 150));
	LApplication::GetApplicationInstance()->GetRenderer()->AddToQueue(testObj);

	m_bStateInitialised = true;
}

void TestState::Update(float dTime)
{
	if (m_bStateInitialised)
	{
		testObj->Update(dTime);
		testObj->setPosition(testObj->getPosition().x + (50.0f * dTime), testObj->getPosition().y);

		if (LInputManager::IsMouseButtonPressed(Mouse::Button::Left))
		{
			printf("\nLeft mouse btn pressed!");
		}
		if (LInputManager::IsMouseButtonReleased(Mouse::Button::Left))
		{
			printf("\nLeft mouse btn released!");
		}
	}
}

void TestState::ShutdownState()
{
	delete testObj;
}

TestState::~TestState()
{
	ShutdownState();
}
