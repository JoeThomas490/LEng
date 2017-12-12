#ifndef _TESTSTATE_H_
#define _TESTSTATE_H_

#include "LState.h"
#include "LGameObject.h"

#include "LApplication.h"
#include "LRenderer.h"

class TestState : public LState
{
public:
	TestState();

	virtual void InitState();

	virtual void Update(float dTime);

	virtual void ShutdownState();

	virtual ~TestState();
private:

	LGameObject* testObj;


};

#endif

