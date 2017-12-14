#ifndef _LAPPLICATION_H_ 
#define _LAPPLICATION_H_

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>

#include "Utils\constants.h"
#include "Input\LInputManager.h"

#include "States\TestState.h"
#include "States\LSplashState.h"
#include "Invaders\States\LInvadersGameState.h"

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

	void AddState(LState* mState);
	void ChangeState(LState* mState);
	void ChangeState(int mStateIndex);


	RenderWindow* GetRenderWindow();
	LRenderer* GetRenderer();

private:

	LApplication();

	RenderWindow* m_pRenderWindow;
	LRenderer* m_pRenderer;	

	LState* m_pCurrentState;

	typedef vector<LState*> StateList;
	StateList m_vStateList;

	float m_dTime;
};

#endif

