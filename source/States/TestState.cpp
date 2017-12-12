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
	testObj->Update(dTime);
	testObj->setPosition(testObj->getPosition().x + (50.0f * dTime), testObj->getPosition().y);
}

void TestState::ShutdownState()
{
	delete testObj;
}

TestState::~TestState()
{
	ShutdownState();
}
