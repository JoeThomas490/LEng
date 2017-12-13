#include "Input\LInputManager.h"

LInputManager::LMouseEventQueue LInputManager::m_vMousePressedEvents;
LInputManager::LMouseEventQueue LInputManager::m_vMouseHeldEvents;
LInputManager::LMouseEventQueue LInputManager::m_vMouseReleasedEvents;

LInputManager::LKeyEventQueue LInputManager::m_vKeyPressedEvents;
LInputManager::LKeyEventQueue LInputManager::m_vKeyHeldEvents;
LInputManager::LKeyEventQueue LInputManager::m_vKeyReleasedEvents;

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

		case Event::EventType::KeyPressed:
			HandleKeyPressed(evt);
		break;

		case Event::EventType::KeyReleased:
			HandleKeyReleased(evt);
		break;
	}
}

void LInputManager::Update()
{
	m_vMousePressedEvents.clear();
	m_vMouseReleasedEvents.clear();

	m_vKeyPressedEvents.clear();
	m_vKeyReleasedEvents.clear();

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

bool LInputManager::IsKeyPressed(Keyboard::Key mKey)
{
	return (m_vKeyPressedEvents.find(mKey) != m_vKeyPressedEvents.end());
}

bool LInputManager::IsKeyHeld(Keyboard::Key mKey)
{
	return (m_vKeyHeldEvents.find(mKey) != m_vKeyHeldEvents.end());
}

bool LInputManager::IsKeyReleased(Keyboard::Key mKey)
{
	return (m_vKeyReleasedEvents.find(mKey) != m_vKeyReleasedEvents.end());
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
	m_vMouseReleasedEvents.insert(evt.mouseButton.button);

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
}

void LInputManager::HandleKeyPressed(Event evt)
{
	auto keyHeldEvt = m_vKeyHeldEvents.find(evt.key.code);
	if (keyHeldEvt == m_vKeyHeldEvents.end())
	{
		m_vKeyPressedEvents.insert(evt.key.code);
		m_vKeyHeldEvents.insert(evt.key.code);
	}
}

void LInputManager::HandleKeyReleased(Event evt)
{
	m_vKeyReleasedEvents.insert(evt.key.code);

	auto keyPressedBtn = m_vKeyPressedEvents.find(evt.key.code);
	if (keyPressedBtn != m_vKeyPressedEvents.end())
	{
		m_vKeyPressedEvents.erase(keyPressedBtn);
	}

	auto keyHeldBtn =  m_vKeyHeldEvents.find(evt.key.code);
	if (keyHeldBtn != m_vKeyHeldEvents.end())
	{
		m_vKeyHeldEvents.erase(keyHeldBtn);
	}
}
