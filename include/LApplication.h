#ifndef _LAPPLICATION_H_ 
#define _LAPPLICATION_H_

#include <SFML\Graphics.hpp>
#include "constants.h"

using namespace sf;
using namespace std;

struct LApplicationInitData
{
	const int windowWidth;
	const int windowHeight;

	const string appName;

	LApplicationInitData(int width, int height, const string& name) 
		: windowWidth(width), windowHeight(height), appName(name)
	{
	}

};

class LApplication
{
public:
	LApplication();
	~LApplication();

	void InitApplication(const LApplicationInitData& data);

	void RunApplication();

	RenderWindow* GetWindowInstance();

private:

	RenderWindow* m_pRenderWindow;
};

#endif

