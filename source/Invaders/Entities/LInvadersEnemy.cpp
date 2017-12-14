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
	SetColor(Color::Yellow);
}

void LInvadersEnemy::Update(float dTime)
{
}
