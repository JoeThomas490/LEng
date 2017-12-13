#ifndef _LSPLASHSTATE_H_
#define _LSPLASHSTATE_H_

#include "LApplication.h"

#include "States\LState.h"
#include "Rendering\LRenderer.h"
#include "GameObject\LGameObject.h"

class LSplashState : public LState
{
public:
	LSplashState();

	virtual void InitState();

	virtual void Update(float dTime);

	virtual void ShutdownState();

	~LSplashState();


private:

	float m_fAliveTime = 1.5f;

	Font m_fontSplash;
	Text m_txtSplash;

};

#endif

