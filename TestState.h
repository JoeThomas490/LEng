#ifndef _TESTSTATE_H_
#define _TESTSTATE_H_

#include "LState.h"

class LGameObject;

class TestState : public LState
{
public:
	TestState();

	void Update(float dTime);

	virtual ~TestState();
private:

	LGameObject* testObj;
};

#endif

