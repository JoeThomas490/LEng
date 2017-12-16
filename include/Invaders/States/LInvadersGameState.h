#ifndef _LINVADERS_GAME_STATE_H_
#define _LINVADERS_GAME_STATE_H_

#include "LApplication.h"

#include "States\LState.h"
#include "Rendering\LRenderer.h"
#include "GameObject\LGameObject.h"

#include "Utils\LMathsUtils.h"

class LInvadersPlayer;
class LInvadersEnemy;
class LInvadersBullet;

class LInvadersGameState : public LState
{
public:
	LInvadersGameState();
	virtual ~LInvadersGameState();

	virtual void InitState();
	virtual void Update(float dTime);

	virtual void ShutdownState();

private:

	void CreatePlayer();
	void CreateEnemies();
	void CreateBullets();

	void HandleBullets(float dTime);

private:
	LInvadersPlayer* m_pPlayer;
	LInvadersEnemy* m_pEnemies;

	LInvadersBullet* m_pBullets;
	int m_iBulletIndx = 0;

	Texture m_textureShip;
};

#endif