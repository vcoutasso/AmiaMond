#include <SFML/Graphics.hpp>

#include <ctime>

#include "jogo.hpp"


int main(int argc, char** argv) {

	srand(time(nullptr));

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	Jogo jogo;

	// Cria a janela e logo em seguida centraliza.
	jogo.window.create(sf::VideoMode(WIDTH, HEIGHT), "Amia: Mond", sf::Style::Fullscreen, settings);
	jogo.window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - jogo.window.getSize().x / 2,
		sf::VideoMode::getDesktopMode().height / 2 - jogo.window.getSize().y / 2));
	jogo.window.setVerticalSyncEnabled(true);


	jogo.mainMenu();

	
	return 0;
}
