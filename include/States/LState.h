#ifndef _LSTATE_H_
#define _LSTATE_H_

#include <vector>

class LState
{
public:
	LState();
	virtual ~LState();

	virtual void InitState() = 0;
	virtual void Update(float dTime) = 0;
	virtual void ShutdownState() = 0;
	
	void SetStateNumber(int mStateNum) { m_iStateNumber = mStateNum; };
	int GetStateNumber() { return m_iStateNumber; };

protected:

	bool m_bStateInitialised;

	int m_iStateNumber;
};

#endif
