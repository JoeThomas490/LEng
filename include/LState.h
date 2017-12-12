#ifndef _LSTATE_H_
#define _LSTATE_H_

#include <vector>

class LState
{
public:
	LState();

	virtual void InitState() = 0;
	virtual void Update(float dTime) = 0;
	virtual void ShutdownState() = 0;

	virtual ~LState();

protected:

	bool m_bStateInitialised;
};

#endif
