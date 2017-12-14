#ifndef _LINVADERS_PLAYER_H_
#define _LINVADERS_PLAYER_H_

#include "GameObject\LGameObject.h"
#include "Invaders\Entities\LInvadersBullet.h"

#include "LApplication.h"

class LInvadersPlayer :
	public LGameObject
{
public:
	LInvadersPlayer();
	~LInvadersPlayer();

	virtual void Update(float dTime) override;

private:

	void HandleBullets(float dTime);

private:

	float m_fMoveSpeed;

	LInvadersBullet m_aBullets[LengConstants::LInvaders::MAX_BULLETS];
	int m_iBulletIndx;
};

#endif

