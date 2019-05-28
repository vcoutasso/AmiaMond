#include "menu.hpp"
#include "jogo.hpp"

using namespace std;

// Inicializa a classe. O objeto Text contem as informações de posição do texto e a string da opção. 
Option::Option(float px, float py, unsigned int s, string t, string pathToFont) {
	setFont(pathToFont);

	hovering = false;

	text.setCharacterSize(s);
	text.setString(t);
	text.setPosition(px - text.getLocalBounds().width / 2, py);
}

// Seta o valor do atributo hovering. 
void Option::setHovering(bool b) {
	hovering = b;
}

// Retorna o valor do atributo hovering.
bool Option::getHovering() {
	return hovering;
}

// Verifica se as coordenadas x e y representam um ponto que está em cima de Text. A principio para ser usado com as coordenadas do mouse.
bool Option::isHovering(int x, int y) {
	sf::FloatRect  pos = text.getGlobalBounds();
	if (pos.contains(x,y))
		return true;
	else
		return false;
}

// Configura text
void Option::setFont(string pathToFile) {
	if (!font.loadFromFile(pathToFile))
		cout << "Error: Could not load font! Path to file: " << pathToFile << endl;
	else {
		text.setFont(font);
		text.setFillColor(sf::Color::Red);
		text.setStyle(sf::Text::Bold);
	}
}

//Abrir a nova janela de instruções, com eventos diferentes e display diferente
void Instructions::openInstructions(sf::RenderWindow *window)
{
	int width = window->getSize().x;
	int height = window->getSize().y;

	Option exit(0, 0, 40, "Voltar para o Menu", "bin/Roboto-Bold.ttf");
	exit.text.setPosition(width - (exit.text.getGlobalBounds().width) - 14, height - 65);
	Option title(160, 30, 40, "Como jogar:", "bin/Roboto-Bold.ttf");

	title.text.setStyle(sf::Text::Bold | sf::Text::Underlined | sf::Text::Italic);

	sf::Clock clock;

	while (window->isOpen()) {

		sf::Event event;

		while (window->pollEvent(event)) {

			switch (event.type)
			{
					case sf::Event::Closed:
						window->close();
						break;

					case sf::Event::MouseMoved:		//Caso aperte no Botão Sair
						if (exit.isHovering(event.mouseMove.x, event.mouseMove.y)) {
							exit.setHovering(true);
						} else 
							exit.setHovering(false); //Para quando estiver fora voltar
						break;
						
					case sf::Event::MouseButtonPressed:
						if (exit.getHovering()) {
							return;
						}
						break;

				default:
					break;
			}

			if (clock.getElapsedTime().asSeconds() >= 1 / 60.f) {

				if (exit.getHovering())
					exit.text.setFillColor(sf::Color::Blue);
				else
					exit.text.setFillColor(sf::Color::Red);

				window->clear(sf::Color(123, 231, 111));
				window->draw(exit.text);
				window->draw(title.text);
				window->display();

				clock.restart();
			}
		}
	}
}
