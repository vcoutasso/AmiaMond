#include <SFML/Window.hpp>

#include "menu.hpp"

#define WIDTH 1280
#define HEIGHT 720

using namespace sf;

int main(int argc, char** argv) {

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Amia: Mond");
	window.setFramerateLimit(60);

	Option sair(WIDTH / 2, HEIGHT / 2, 40, "SAIR", "bin/Roboto-Bold.ttf");

	while(window.isOpen()) {
		
		Event event;

		/* Tratamento de eventos */ 
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
				window.close();

			if (event.type
		}

		window.clear(Color(123, 231, 111));

		window.draw(sair.text);
		window.display();
	}


	return 0;
}
