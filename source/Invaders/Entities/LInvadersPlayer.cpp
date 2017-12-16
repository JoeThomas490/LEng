#include "Invaders\Entities\LInvadersPlayer.h"

LInvadersPlayer::LInvadersPlayer()
{

	CreatePrimitive(LPrimitive::LSQUARE, Vector2f(50, 50));

	setPosition(Vector2f(LengConstants::WINDOW_WIDTH / 2 - (GetSize().x / 2), LengConstants::WINDOW_HEIGHT * 0.85f - (GetSize().y / 2)));

	m_fMoveSpeed = LengConstants::LInvaders::PLAYER_SPEED;

	SetTexture(LTextureManager::GetTextureManagerInstance().LoadTexture("res/sprites/ship.png"));
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

}


