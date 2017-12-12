#ifndef _LAPPLICATION_H_ 
#define _LAPPLICATION_H_

#include <SFML\Graphics.hpp>

#include "Utils\constants.h"

#include "States\TestState.h"

using namespace sf;
using namespace std;

class LRenderer;
class LState;

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

	static LApplication*  GetApplicationInstance()
	{
		static LApplication* m_sAppInstance = new LApplication();

		return m_sAppInstance;
	}

	~LApplication();

	void InitApplication(const LApplicationInitData& data);

	void RunApplication();

	void ClearApplication();

	RenderWindow* GetRenderWindow();
	LRenderer* GetRenderer();

private:

	LApplication();

	RenderWindow* m_pRenderWindow;
	LRenderer* m_pRenderer;	

	LState* m_pCurrentState;

	float m_dTime;
};

#endif

