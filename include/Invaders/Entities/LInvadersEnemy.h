#ifndef _LINVADERS_ENEMY_H_
#define _LINVADERS_ENEMY_H_

#include "GameObject\LGameObject.h"
#include "LApplication.h"

class LInvadersEnemy : public LGameObject
{

public:
	LInvadersEnemy();
	~LInvadersEnemy();

	void InitEnemy();

	virtual void Update(float dTime) override;


private:


private:
	float m_fHealth = 100.0f;

};

#endif
