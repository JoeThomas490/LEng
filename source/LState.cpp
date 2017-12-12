#include "LState.h"



LState::LState()
{
}

void LState::InitState()
{
}

void LState::AddGameObject(LGameObject * mObj)
{
	m_sceneObjects.push_back(mObj);
}

LState::~LState()
{
}
