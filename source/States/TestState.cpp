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

		for (int i = 0; i < m_iMaxObjects; i++)
		{
			testObjs[i].Update(dTime);
		}

		if (LInputManager::IsMouseButtonPressed(Mouse::Button::Left))
		{
			printf("\nSetting position to - X: %f	Y: %f", LInputManager::GetMousePosition().x, LInputManager::GetMousePosition().y);
			testObjs[m_iObjCounter].setPosition(LInputManager::GetMousePosition());
			testObjs[m_iObjCounter].SetIsActive(true);
			m_iObjCounter++;
			m_iObjCounter %= m_iMaxObjects;
		}

		for (int i = 0; i < m_iMaxObjects; i++)
		{
			for (int j = 0; j < m_iMaxObjects; j++)
			{
				LGameObject* obj1 = &testObjs[i];
				LGameObject* obj2 = &testObjs[j];

				if (LGameObject::IsCollisionBetween(obj1, obj2))
				{
					printf("\n Collision!");
				}
			}
		}


		if (LInputManager::IsKeyPressed(Keyboard::Key::A))
		{
			printf("\n 'A' Key pressed!");
		}
		if (LInputManager::IsKeyReleased(Keyboard::Key::A))
		{
			printf("\n 'A' Key released!");
		}
		if (LInputManager::IsKeyHeld(Keyboard::Key::A) && LInputManager::IsKeyHeld(Keyboard::Key::P	))
		{
			printf("\n 'A' & 'P' Keys held!");
		}
	}
}

void TestState::ShutdownState()
{
	LRenderer* renderer = LApplication::GetApplicationInstance()->GetRenderer();
	for (int i = 0; i < m_iMaxObjects; i++)
	{
		renderer->RemoveFromQueue(&testObjs[i]);
	}

	delete[] testObjs;
}

TestState::~TestState()
{
}
