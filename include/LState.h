#ifndef _LSTATE_H_
#define _LSTATE_H_

#include <vector>
#include "LApplication.h"

class LGameObject;

typedef std::vector<LGameObject*> SceneObjects;

class LState
{
public:
	LState();

	virtual void InitState();
	virtual void Update(float dTime) = 0;
	virtual void ShutdownState() = 0;

	void AddGameObject(LGameObject* mObj);

	virtual ~LState();

protected:

	SceneObjects m_sceneObjects;
};

#endif
