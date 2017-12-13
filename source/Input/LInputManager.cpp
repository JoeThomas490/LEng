#include "Input\LInputManager.h"

LInputManager::LMouseEventQueue LInputManager::m_vMousePressedEvents;
LInputManager::LMouseEventQueue LInputManager::m_vMouseReleasedEvents;
LInputManager::LMouseEventQueue LInputManager::m_vMouseHeldEvents;

Window* LInputManager::m_spWindow;

Vector2f LInputManager::m_v2MousePosition;

void LInputManager::SetWindow(Window * mpWindow)
{
	m_spWindow = mpWindow;
}

void LInputManager::HandleEvents(Event evt)
{
	switch (evt.type)
	{
		case Event::EventType::MouseButtonPressed:
			HandleMousePressed(evt);
		break;

		case Event::EventType::MouseButtonReleased:
			HandleMouseReleased(evt);
		break;
	}
}

void LInputManager::Update()
{
	m_vMousePressedEvents.clear();
	m_vMouseReleasedEvents.clear();

	if (m_spWindow != nullptr)
	{
		m_v2MousePosition = Vector2f(Mouse::getPosition(*m_spWindow));
	}
}

bool LInputManager::IsMouseButtonPressed(Mouse::Button mBtn)
{
	return (m_vMousePressedEvents.find(mBtn) != m_vMousePressedEvents.end());
}

bool LInputManager::IsMouseButtonHeld(Mouse::Button mBtn)
{
	return (m_vMouseHeldEvents.find(mBtn) != m_vMouseHeldEvents.end());
}

bool LInputManager::IsMouseButtonReleased(Mouse::Button mBtn)
{
	return (m_vMouseReleasedEvents.find(mBtn) != m_vMouseReleasedEvents.end());
}

Vector2f LInputManager::GetMousePosition()
{
	return m_v2MousePosition;
}

void LInputManager::HandleMousePressed(Event evt)
{
	m_vMousePressedEvents.insert(evt.mouseButton.button);
	m_vMouseHeldEvents.insert(evt.mouseButton.button);
}

void LInputManager::HandleMouseReleased(Event evt)
{
	auto mousePressedBtn = m_vMousePressedEvents.find(evt.mouseButton.button);
	if (mousePressedBtn != m_vMousePressedEvents.end())
	{
		m_vMousePressedEvents.erase(mousePressedBtn);
	}

	auto mouseHeldBtn = m_vMouseHeldEvents.find(evt.mouseButton.button);
	if (mouseHeldBtn != m_vMouseHeldEvents.end())
	{
		m_vMouseHeldEvents.erase(mouseHeldBtn);
	}

	m_vMouseReleasedEvents.insert(evt.mouseButton.button);
}
