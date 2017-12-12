#include "TestState.h"
#include "LGameObject.h"


TestState::TestState()
{
	testObj = new LGameObject();
	AddGameObject(testObj);
}

void TestState::Update(float dTime)
{
	testObj->setPosition(testObj->getPosition().x + 0.5f, testObj->getPosition().y);
}

TestState::~TestState()
{
	delete testObj;
}
