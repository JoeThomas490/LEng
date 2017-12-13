#include "States\LSplashState.h"



LSplashState::LSplashState()
{
}

void LSplashState::InitState()
{
	if (!m_fontSplash.loadFromFile("res/fonts/data-control.ttf"))
	{
		printf("\n Font can't be loaded");
	}

	m_txtSplash.setFont(m_fontSplash);
	m_txtSplash.setString(L"LEng");
	m_txtSplash.setCharacterSize(38);

	m_txtSplash.setColor(Color::White);
	m_txtSplash.setOrigin(0.5f, 0.5f);

	m_txtSplash.setPosition(LengConstants::WINDOW_WIDTH/2 - (m_txtSplash.getLocalBounds().width/2), LengConstants::WINDOW_HEIGHT/2 - (m_txtSplash.getLocalBounds().width/2));

	LApplication::GetApplicationInstance()->GetRenderer()->AddToQueue(&m_txtSplash);
}

void LSplashState::Update(float dTime)
{
	static float mAliveTime = 0;
	mAliveTime += dTime;

	static Vector2f scale(1, 1);

	scale.x += 0.5f * dTime;
	scale.y += 0.5f * dTime;

	m_txtSplash.setScale(scale);

	m_txtSplash.setPosition(LengConstants::WINDOW_WIDTH / 2 - (m_txtSplash.getGlobalBounds().width / 2), LengConstants::WINDOW_HEIGHT / 2 - (m_txtSplash.getGlobalBounds().width / 2));

	if (mAliveTime > m_fAliveTime)
	{
		FinishState();
	}
}

void LSplashState::ShutdownState()
{
	LApplication::GetApplicationInstance()->GetRenderer()->RemoveFromQueue(&m_txtSplash);
}


LSplashState::~LSplashState()
{
}
