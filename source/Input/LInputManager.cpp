#include "Input\LInputManager.h"

LInputManager::LMouseEventQueue LInputManager::m_vMousePressedEvents;
LInputManager::LMouseEventQueue LInputManager::m_vMouseReleasedEvents;

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
}

bool LInputManager::IsMouseButtonPressed(Mouse::Button mBtn)
{
	return (m_vMousePressedEvents.find(mBtn) != m_vMousePressedEvents.end());
}

bool LInputManager::IsMouseButtonReleased(Mouse::Button mBtn)
{
	return (m_vMouseReleasedEvents.find(mBtn) != m_vMouseReleasedEvents.end());
}

void LInputManager::HandleMousePressed(Event evt)
{
	m_vMousePressedEvents.insert(evt.mouseButton.button);
}

void LInputManager::HandleMouseReleased(Event evt)
{
	auto mouseBtn = m_vMousePressedEvents.find(evt.mouseButton.button);
	if (mouseBtn != m_vMousePressedEvents.end())
	{
		m_vMousePressedEvents.erase(mouseBtn);
	}

	m_vMouseReleasedEvents.insert(evt.mouseButton.button);
}
