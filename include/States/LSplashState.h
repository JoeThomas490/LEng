#ifndef _LSPLASHSTATE_H_
#define _LSPLASHSTATE_H_

#include "LApplication.h"

#include "States\LState.h"
#include "Rendering\LRenderer.h"
#include "GameObject\LGameObject.h"

#include "Utils\LMathsUtils.h"

class LSplashState : public LState
{
public:
	LSplashState();

	virtual void InitState();

	virtual void Update(float dTime);

	virtual void ShutdownState();

	~LSplashState();


private:

	void UpdateSplashText(float dTime);

	float m_fDeathTime = 3.0f;
	float m_fAliveTime = 0.0f;

	Font m_fontSplash;
	Text m_txtSplash;

};

#endif

