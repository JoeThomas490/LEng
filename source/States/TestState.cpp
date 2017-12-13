#include "States\TestState.h"


TestState::TestState()
{
	m_bStateInitialised = false;
}

void TestState::InitState()
{
	testObjs = new LGameObject[m_iMaxObjects];
	for (int i = 0; i < m_iMaxObjects; i++)
	{
		testObjs[i].SetSize(Vector2f(60, 60));
		testObjs[i].SetIsActive(false);

		LApplication::GetApplicationInstance()->GetRenderer()->AddToQueue(&testObjs[i]);
	}

	m_iObjCounter = 0;

	m_bStateInitialised = true;
}

void TestState::Update(float dTime)
{
	if (m_bStateInitialised)
	{
		//testObj->Update(dTime);
		//testObj->setPosition(testObj->getPosition().x + (50.0f * dTime), testObj->getPosition().y);

		if (LInputManager::IsMouseButtonPressed(Mouse::Button::Left))
		{
			printf("\nSetting position to - X: %f	Y: %f", LInputManager::GetMousePosition().x, LInputManager::GetMousePosition().y);
			testObjs[m_iObjCounter].setPosition(LInputManager::GetMousePosition());
			testObjs[m_iObjCounter].SetIsActive(true);
			m_iObjCounter++;
			m_iObjCounter %= m_iMaxObjects;
		}
		if (LInputManager::IsMouseButtonReleased(Mouse::Button::Left))
		{
		}

		if (LInputManager::IsMouseButtonHeld(Mouse::Button::Left))
		{
		}
	}
}

void TestState::ShutdownState()
{
	delete[] testObjs;
}

TestState::~TestState()
{
	ShutdownState();
}
