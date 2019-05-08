#include <iostream>
#include <iomanip>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace sf;

int main(int argc, char** argv) {

	RenderWindow window(VideoMode(1280, 720), "Amia: Mond");

	window.setFramerateLimit(60);

	while(window.isOpen()) {
		
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
				window.close();
		}

		window.clear(Color(123, 231, 111));

		window.display();
	}



	return 0;
}
