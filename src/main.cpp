#include <SFML/Window.hpp>

#include "menu.hpp"

using namespace sf;

int main(int argc, char** argv) {

	RenderWindow window(VideoMode(1280, 720), "Amia: Mond");
	window.setFramerateLimit(60);

	Option sair(300, 200, 40, "SAIR", "bin/Roboto-Bold.ttf");

	while(window.isOpen()) {
		
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color(123, 231, 111));

		window.draw(sair.text);
		window.display();
	}


	return 0;
}
