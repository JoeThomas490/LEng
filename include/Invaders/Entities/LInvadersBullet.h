#ifndef _LINVADERS_BULLET_H_
#define _LINVADERS_BULLET_H_

#include "GameObject\LGameObject.h"
#include "LApplication.h"

class LInvadersBullet : public LGameObject
{
public:
	LInvadersBullet();
	~LInvadersBullet();
	
	void InitBullet();

	virtual void Update(float dTime) override;

private:

	float m_fMoveSpeed;
};


#endif
