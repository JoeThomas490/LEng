#ifndef _LINPUTMANAGER_H_
#define _LINPUTMANAGER_H_

#include <SFML\Window.hpp>

#include <set>

using namespace sf;
using namespace std;

class LInputManager
{
public:
	typedef set<Mouse::Button> LMouseEventQueue;

	static void SetWindow(Window* mpWindow);

	static void HandleEvents(Event evt);
	static void Update();

	static bool IsMouseButtonPressed(Mouse::Button mBtn);
	static bool IsMouseButtonHeld(Mouse::Button mBtn);
	static bool IsMouseButtonReleased(Mouse::Button mBtn);

	static Vector2f GetMousePosition();

private:
	static void HandleMousePressed(Event evt);
	static void HandleMouseReleased(Event evt);

private:

	static Window* m_spWindow;

	static LMouseEventQueue m_vMousePressedEvents;
	static LMouseEventQueue m_vMouseReleasedEvents;
	static LMouseEventQueue m_vMouseHeldEvents;

	static Vector2f m_v2MousePosition;
};

#endif
