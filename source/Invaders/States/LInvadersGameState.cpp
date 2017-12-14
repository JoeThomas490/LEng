#include "Invaders\States\LInvadersGameState.h"
#include "Invaders\Entities\LInvadersPlayer.h"


LInvadersGameState::LInvadersGameState()
{
}

void LInvadersGameState::InitState()
{
	CreatePlayer();
}

void LInvadersGameState::Update(float dTime)
{
	m_pPlayer->Update(dTime);
}

void LInvadersGameState::ShutdownState()
{
	LApplication::GetApplicationInstance()->GetRenderer()->RemoveFromQueue(m_pPlayer);
	LFREE(m_pPlayer);
}

void LInvadersGameState::CreatePlayer()
{
	m_pPlayer = new LInvadersPlayer();
	LApplication::GetApplicationInstance()->GetRenderer()->AddToQueue(m_pPlayer);
	
}

LInvadersGameState::~LInvadersGameState()
{
}
