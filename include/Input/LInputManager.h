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


	static void HandleEvents(Event evt);
	static void Update();

	static bool IsMouseButtonPressed(Mouse::Button mBtn);
	static bool IsMouseButtonReleased(Mouse::Button mBtn);

private:
	static void HandleMousePressed(Event evt);
	static void HandleMouseReleased(Event evt);

private:

	static Window* m_spWindow;

	static LMouseEventQueue m_vMousePressedEvents;
	static LMouseEventQueue m_vMouseReleasedEvents;
};

#endif
