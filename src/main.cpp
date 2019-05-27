#include <SFML/Window.hpp>

#include "menu.hpp"

#define WIDTH 1280
#define HEIGHT 720

using namespace sf;

int main(int argc, char** argv) {

	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Amia: Mond");
	window.setFramerateLimit(60);

	Option sair(WIDTH / 2, 3 * HEIGHT / 4, 40, "Sair", "bin/Roboto-Bold.ttf");

	while(window.isOpen()) {
		
		Event event;

		/* Tratamento de eventos */ 
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
				window.close();

			if (event.type == Event::MouseButtonPressed) {
				if (sair.isHovering(event.mouseMove.x, event.mouseMove.y))
						window.close();
			}

			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Escape)
					window.close();
			}

			if (event.type == Event::MouseMoved) {
				sair.isHovering(event.mouseMove.x, event.mouseMove.y);
			}


			window.clear(Color(123, 231, 111));

			window.draw(sair.text);
			window.display();
		}


	}

	return 0;
}
