#include "Invaders\LInvadersGameState.h"



LInvadersGameState::LInvadersGameState()
{
}

void LInvadersGameState::InitState()
{
	CreatePlayer();

	m_fMoveSpeed = 250.0f;
}

void LInvadersGameState::Update(float dTime)
{
	UpdatePlayer(dTime);
}

void LInvadersGameState::UpdatePlayer(float dTime)
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

	Vector2f currPos = m_pPlayer->getPosition();
	currPos.x += moveDir * m_fMoveSpeed * dTime;
	m_pPlayer->setPosition(currPos);

}

void LInvadersGameState::ShutdownState()
{
	LApplication::GetApplicationInstance()->GetRenderer()->RemoveFromQueue(m_pPlayer);
	LFREE(m_pPlayer);
}

void LInvadersGameState::CreatePlayer()
{
	m_pPlayer = new LGameObject(Vector2f(0, 0), Vector2f(25, 25));
	LApplication::GetApplicationInstance()->GetRenderer()->AddToQueue(m_pPlayer);

	m_pPlayer->setPosition(Vector2f(LengConstants::WINDOW_WIDTH/2 - (m_pPlayer->GetSize().x/2), LengConstants::WINDOW_HEIGHT * 0.75f - (m_pPlayer->GetSize().y / 2)));
}

LInvadersGameState::~LInvadersGameState()
{
}
