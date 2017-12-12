#include "LApplication.h"

using namespace sf;

int main()
{
	printf("%s", "Engine running... \n");
	printf("%s", "******************\n");

	LApplication app;
	app.InitApplication(LApplicationInitData(LengConstants::WINDOW_WIDTH, LengConstants::WINDOW_HEIGHT, "Hello World!"));


	RenderWindow* pWindow = app.GetWindowInstance();

	CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (pWindow->isOpen())
	{
		sf::Event event;
		while (pWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				pWindow->close();
		}

		pWindow->clear();
		pWindow->draw(shape);
		pWindow->display();
	}

	printf("%s", "Engine stopping... \n");
	printf("%s", "******************\n");

	return 0;
}