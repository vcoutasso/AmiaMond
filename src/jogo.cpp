#include "jogo.hpp"
#include "menu.hpp"

using namespace sf;

Jogo::~Jogo() {
	window.~RenderWindow();
}

Jogo::Jogo() {
}

void Jogo::mainMenu() {
	int width = window.getSize().x;
	int height = window.getSize().y;

	Option jogar(width / 2,  height / 4, 40, "Jogar", "bin/Roboto-Bold.ttf");
	Option sair(width / 2, 3 * height / 4, 40, "Sair", "bin/Roboto-Bold.ttf");

	Clock clock;

	while(window.isOpen()) {
		
		Event event;
		
		/* Tratamento de eventos */ 
		while (window.pollEvent(event)) {

			switch (event.type) {
				case Event::Closed:
					window.close();
					break;

				case Event::MouseButtonPressed:
					if (sair.getHovering())
						window.close();

					break;

				case Event::KeyReleased:
					if (event.key.code == Keyboard::Escape)
						window.close();
					break;
				
				case Event::MouseMoved:
					if (sair.isHovering(event.mouseMove.x, event.mouseMove.y))
						sair.setHovering(true);
					else if (jogar.isHovering(event.mouseMove.x, event.mouseMove.y))
						jogar.setHovering(true);
					else {
						sair.setHovering(false);
						jogar.setHovering(false);
					}

					break;

				default:
					break;
			}
			
			// Atualiza a tela apenas depois de processar os eventos e se tiver passado o tempo minimo necessario.
			// Caso contrário, torna a processar os eventos.
			if (clock.getElapsedTime().asSeconds() >= 1/60.f) {

				if (sair.getHovering()) 
					sair.text.setFillColor(Color::Blue);
				else
					sair.text.setFillColor(Color::Red);
				

				if (jogar.getHovering())
					jogar.text.setFillColor(Color::Blue);
				else
					jogar.text.setFillColor(Color::Red);
				

				window.clear(Color(123, 231, 111));
				window.draw(sair.text);
				window.draw(jogar.text);
				window.display();

				clock.restart();
			}
		}


	}
}
