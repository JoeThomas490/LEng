#include "LApplication.h"

using namespace sf;

int main()
{


	LApplication* app = LApplication::GetApplicationInstance();

	app->InitApplication(LApplicationInitData(LengConstants::WINDOW_WIDTH, LengConstants::WINDOW_HEIGHT, "Hello World!"));

	app->RunApplication();

	app->ClearApplication();

	delete app;

	return 0;
}