#include "States\TestState.h"


TestState::TestState()
{
	m_bStateInitialised = false;
}

void TestState::InitState()
{
	testObj = new LGameObject();
	LApplication::GetApplicationInstance()->GetRenderer()->AddToQueue(testObj);

	m_bStateInitialised = true;
}

void TestState::Update(float dTime)
{
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
