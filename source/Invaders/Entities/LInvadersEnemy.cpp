#include "Invaders\Entities\LInvadersEnemy.h"

LInvadersEnemy::LInvadersEnemy()
{
}

LInvadersEnemy::~LInvadersEnemy()
{
}

void LInvadersEnemy::InitEnemy()
{
	CreatePrimitive(LPrimitive::LSQUARE, Vector2f(35, 35));
	SetTexture(LTextureManager::GetTextureManagerInstance().LoadTexture("res/sprites/enemy.png"));
}

void LInvadersEnemy::Update(float dTime)
{
}
