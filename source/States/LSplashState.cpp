#include "States\LSplashState.h"



LSplashState::LSplashState()
{

}

LSplashState::~LSplashState()
{

}
void LSplashState::InitState()
{
	m_fDeathTime = LengConstants::SPLASH_TIME;

	if (!m_fontSplash.loadFromFile("res/fonts/data-control.ttf"))
	{
		printf("\nFont can't be loaded");
	}

	m_txtSplash.setFont(m_fontSplash);
	m_txtSplash.setString(LSTRING("LEng"));
	m_txtSplash.setCharacterSize(38);

	m_txtSplash.setColor(Color::White);
	m_txtSplash.setOrigin(0.5f, 0.5f);

	m_txtSplash.setPosition(LengConstants::WINDOW_WIDTH/2 - (m_txtSplash.getLocalBounds().width/2), LengConstants::WINDOW_HEIGHT/2 - (m_txtSplash.getLocalBounds().width/2));

	LApplication::GetApplicationInstance()->GetRenderer()->AddToQueue(&m_txtSplash);
}

void LSplashState::Update(float dTime)
{
	m_fAliveTime += dTime;

	UpdateSplashText(dTime);

	if (m_fAliveTime > m_fDeathTime)
	{
		FinishState();
	}
}

void LSplashState::ShutdownState()
{
	LApplication::GetApplicationInstance()->GetRenderer()->RemoveFromQueue(&m_txtSplash);
}

void LSplashState::UpdateSplashText(float dTime)
{
	static Vector2f scale(1, 1);

	scale.x += 0.5f * dTime;
	scale.y += 0.5f * dTime;

	m_txtSplash.setScale(scale);
	m_txtSplash.setPosition(LengConstants::WINDOW_WIDTH / 2 - (m_txtSplash.getGlobalBounds().width / 2), LengConstants::WINDOW_HEIGHT / 2 - (m_txtSplash.getGlobalBounds().width / 2));

	float t = m_fAliveTime / m_fDeathTime;

	float r = Lerp(Color::White.r, Color::Black.r, t);
	float g = Lerp(Color::White.g, Color::Black.g, t);
	float b = Lerp(Color::White.b, Color::Black.b, t);

	m_txtSplash.setColor(Color(r,g,b));

}
