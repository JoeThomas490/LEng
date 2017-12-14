#include "Invaders\States\LInvadersGameState.h"
#include "Invaders\Entities\LInvadersPlayer.h"
#include "Invaders\Entities\LInvadersEnemy.h"
#include "Invaders\Entities\LInvadersBullet.h"


LInvadersGameState::LInvadersGameState()
{
}

void LInvadersGameState::InitState()
{
	CreatePlayer();
	CreateEnemies();
	CreateBullets();
}

void LInvadersGameState::Update(float dTime)
{
	m_pPlayer->Update(dTime);

	HandleBullets(dTime);

	for (int i = 0; i < LengConstants::LInvaders::MAX_BULLETS; i++)
	{
		if (m_pBullets[i].GetIsActive() == true)
		{
			for (int j = 0; j < LengConstants::LInvaders::MAX_ENEMIES; j++)
			{
				if (m_pEnemies[j].GetIsActive() == true)
				{
					if (LGameObject::IsCollisionBetween(&m_pBullets[i], &m_pEnemies[j]))
					{
						m_pEnemies[j].SetIsActive(false);
						m_pBullets[i].SetIsActive(false);
					}
				}
			}

		}
	}
}

void LInvadersGameState::ShutdownState()
{
	LApplication::GetApplicationInstance()->GetRenderer()->RemoveFromQueue(m_pPlayer);
	LFREE(m_pPlayer);

	for (int i = 0; i < LengConstants::LInvaders::MAX_ENEMIES; i++)
	{
		LApplication::GetApplicationInstance()->GetRenderer()->RemoveFromQueue(&m_pEnemies[i]);
	}

	delete[] m_pEnemies;

	delete[] m_pBullets;
}

void LInvadersGameState::CreatePlayer()
{
	m_pPlayer = new LInvadersPlayer();
	LApplication::GetApplicationInstance()->GetRenderer()->AddToQueue(m_pPlayer);

}

void LInvadersGameState::CreateEnemies()
{
	m_pEnemies = new LInvadersEnemy[LengConstants::LInvaders::MAX_ENEMIES];

	Vector2f startPos = Vector2f(50, 100);
	int row = 0;
	int counter = 0;

	for (int i = 0; i < LengConstants::LInvaders::MAX_ENEMIES; i++)
	{
		LInvadersEnemy* pEnemy = &m_pEnemies[i];
		pEnemy->InitEnemy();
		//If it's an even row
		if (row % 2 == 0)
		{
			Vector2f spawnPos;
			spawnPos.x = startPos.x + ((pEnemy->GetSize().x + 15.0f) * (counter % LengConstants::LInvaders::ENEMIES_PER_ROW));
			spawnPos.y = startPos.y + (row * 65);

			pEnemy->setPosition(spawnPos);
		}
		else
		{
			Vector2f spawnPos;
			spawnPos.x = (startPos.x + 15.0f) + ((pEnemy->GetSize().x + 15.0f) * (counter % LengConstants::LInvaders::ENEMIES_PER_ROW));
			spawnPos.y = startPos.y + (row * 65);

			pEnemy->setPosition(spawnPos);
		}

		counter++;
		if (counter % LengConstants::LInvaders::ENEMIES_PER_ROW == 0)
			row++;

		LApplication::GetApplicationInstance()->GetRenderer()->AddToQueue(pEnemy);
	}


}

void LInvadersGameState::CreateBullets()
{
	m_iBulletIndx = 0;

	m_pBullets = new LInvadersBullet[LengConstants::LInvaders::MAX_BULLETS];

	for (int i = 0; i < LengConstants::LInvaders::MAX_BULLETS; i++)
	{
		m_pBullets[i].InitBullet();
	}
}

void LInvadersGameState::HandleBullets(float dTime)
{
	if (LInputManager::IsKeyPressed(Keyboard::Key::Space))
	{
		LInvadersBullet* pBullet = &m_pBullets[m_iBulletIndx];

		Vector2f spawnPos = m_pPlayer->getPosition();
		spawnPos.x += (m_pPlayer->GetSize().x / 2) - (pBullet->GetSize().x / 2);

		pBullet->setPosition(spawnPos);

		pBullet->SetIsActive(true);

		m_iBulletIndx++;
		m_iBulletIndx %= LengConstants::LInvaders::MAX_BULLETS;
	}

	for (int i = 0; i < LengConstants::LInvaders::MAX_BULLETS; i++)
	{
		LInvadersBullet* pBullet = &m_pBullets[i];
		pBullet->Update(dTime);
	}
}

LInvadersGameState::~LInvadersGameState()
{
}
