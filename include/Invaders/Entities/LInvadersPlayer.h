#ifndef _LINVADERS_PLAYER_H_
#define _LINVADERS_PLAYER_H_

#include "GameObject\LGameObject.h"

#include "LApplication.h"

class LInvadersPlayer :
	public LGameObject
{
public:
	LInvadersPlayer();
	~LInvadersPlayer();

	virtual void Update(float dTime) override;

private:

	float m_fMoveSpeed;

};

#endif

