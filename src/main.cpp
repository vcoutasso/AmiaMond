#include "menu.hpp"

#define WIDTH 1920
#define HEIGHT 1080

int main(int argc, char** argv) {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	Jogo jogo;

	// Cria a janela e logo em seguida centraliza.
	jogo.window.create(sf::VideoMode(WIDTH, HEIGHT), "Amia: Mond", sf::Style::Fullscreen, settings);
	jogo.window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - jogo.window.getSize().x / 2,
			sf::VideoMode::getDesktopMode().height / 2 - jogo.window.getSize().y / 2));

	//jogo.window.setVerticalSyncEnabled(false);
	jogo.mainMenu();

	jogo.~Jogo();
	
	return 0;
}
