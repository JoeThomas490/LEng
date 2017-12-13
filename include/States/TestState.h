#ifndef _TESTSTATE_H_
#define _TESTSTATE_H_

#include "LState.h"

#include "LApplication.h"

#include "Rendering\LRenderer.h"
#include "GameObject\LGameObject.h"

class TestState : public LState
{
public:
	TestState();

	virtual void InitState();

	virtual void Update(float dTime);

	virtual void ShutdownState();

	virtual ~TestState();
private:

	LGameObject* testObjs;

	int m_iObjCounter;
	int m_iMaxObjects = 2;


};

#endif

