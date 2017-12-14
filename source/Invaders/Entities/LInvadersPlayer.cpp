#include "Invaders\Entities\LInvadersPlayer.h"

LInvadersPlayer::LInvadersPlayer()
{
	LGameObject::LGameObject(LPrimitive::LSQUARE, Vector2f(0, 0), Vector2f(25, 25));

	CreatePrimitive(LPrimitive::LSQUARE, Vector2f(25, 25));

	setPosition(Vector2f(LengConstants::WINDOW_WIDTH / 2 - (GetSize().x / 2), LengConstants::WINDOW_HEIGHT * 0.85f - (GetSize().y / 2)));

	m_fMoveSpeed = LengConstants::LInvaders::PLAYER_SPEED;
	m_iBulletIndx = 0;

	for (int i = 0; i < LengConstants::LInvaders::MAX_BULLETS; i++)
	{
		m_aBullets[i].InitBullet(); 
	}
}


LInvadersPlayer::~LInvadersPlayer()
{
}

void LInvadersPlayer::Update(float dTime)
{
	int moveDir = 0;

	if (LInputManager::IsKeyHeld(Keyboard::Key::Left))
	{
		moveDir = -1;
	}
	if (LInputManager::IsKeyHeld(Keyboard::Key::Right))
	{
		moveDir = 1;
	}

	if (LInputManager::IsKeyHeld(Keyboard::Key::Left) && LInputManager::IsKeyHeld(Keyboard::Key::Right))
	{
		moveDir = 0;
	}

	Vector2f currPos = getPosition();
	currPos.x += moveDir * m_fMoveSpeed * dTime;
	if (currPos.x < 0)
	{
		currPos.x = 0;
	}
	if (currPos.x + GetSize().x > LengConstants::WINDOW_WIDTH)
	{
		currPos.x = LengConstants::WINDOW_WIDTH -GetSize().x;
	}
	setPosition(currPos);

	HandleBullets(dTime);

}

void LInvadersPlayer::HandleBullets(float dTime)
{
	if (LInputManager::IsKeyPressed(Keyboard::Key::Space))
	{
		LInvadersBullet* pBullet = &m_aBullets[m_iBulletIndx];
 
 		Vector2f spawnPos = getPosition();
		spawnPos.x += (GetSize().x / 2) - (pBullet->GetSize().x / 2);

		pBullet->setPosition(spawnPos);

		pBullet->SetIsActive(true);

		m_iBulletIndx++;
		m_iBulletIndx %= LengConstants::LInvaders::MAX_BULLETS;
	}

	for (int i = 0; i < LengConstants::LInvaders::MAX_BULLETS; i++)
	{
		m_aBullets[i].Update(dTime);
	}
}


