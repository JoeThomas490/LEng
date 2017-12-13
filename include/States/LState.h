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
	virtual void FinishState();
	virtual void ShutdownState() = 0;
	
	void SetStateNumber(int mStateNum) { m_iStateNumber = mStateNum; };
	int GetStateNumber() { return m_iStateNumber; };

	bool GetIsStateFinished() { return m_bStateFinished; };

protected:

	bool m_bStateInitialised = false;
	bool m_bStateFinished = false;

	int m_iStateNumber;
};

#endif
