#include "LApplication.h"

using namespace sf;

int main()
{
	printf("%s", "Engine running... \n");
	printf("%s", "******************\n");

	LApplication* app = LApplication::GetApplicationInstance();

	app->InitApplication(LApplicationInitData(LengConstants::WINDOW_WIDTH, LengConstants::WINDOW_HEIGHT, "Hello World!"));

	app->RunApplication();

	app->ClearApplication();

	printf("%s", "Engine stopping... \n");
	printf("%s", "******************\n");

	delete app;

	return 0;
}