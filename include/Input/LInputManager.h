#ifndef _LINPUTMANAGER_H_
#define _LINPUTMANAGER_H_

#include <SFML\Window.hpp>

using namespace sf;
using namespace std;

class LInputManager
{
public:

	static void HandleEvents(Event evt);
	static void Update();

private:

	Window* m_pWindow;
};

#endif
