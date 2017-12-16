#include "Invaders\Entities\LInvadersBullet.h"

LInvadersBullet::LInvadersBullet()
{
}

LInvadersBullet::~LInvadersBullet()
{
	LApplication::GetApplicationInstance()->GetRenderer()->RemoveFromQueue(this);
}

void LInvadersBullet::InitBullet()
{
	CreatePrimitive(LPrimitive::LSQUARE, Vector2f(10, 30));

	m_fMoveSpeed = LengConstants::LInvaders::BULLET_SPEED;

	SetIsActive(false);

	SetTexture(LTextureManager::GetTextureManagerInstance().LoadTexture("res/sprites/bullet.png"));

	LApplication::GetApplicationInstance()->GetRenderer()->AddToQueue(this);
}

void LInvadersBullet::Update(float dTime)
{
	if (GetIsActive() == true)
	{
		Vector2f currPos = getPosition();

		currPos.y -= m_fMoveSpeed * dTime;

		setPosition(currPos);
		 
		if (currPos.y < -50)
		{
			SetIsActive(false);
		}
	}
}
