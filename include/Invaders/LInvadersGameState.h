#ifndef _LINVADERS_GAME_STATE_H_
#define _LINVADERS_GAME_STATE_H_

#include "LApplication.h"

#include "States\LState.h"
#include "Rendering\LRenderer.h"
#include "GameObject\LGameObject.h"

#include "Utils\LMathsUtils.h"

class LInvadersGameState : public LState
{
public:
	LInvadersGameState();
	virtual ~LInvadersGameState();

	virtual void InitState();
	virtual void Update(float dTime);

	void UpdatePlayer(float dTime);

	virtual void ShutdownState();

private:

	void CreatePlayer();

private:
	LGameObject* m_pPlayer;
	float m_fMoveSpeed;

};

#endif