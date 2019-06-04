#include "menu.hpp"

#define WIDTH 1280
#define HEIGHT 720

using namespace sf;

int main(int argc, char** argv) {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	Jogo jogo;

	// Cria a janela e logo em seguida centraliza.
	jogo.window.create(VideoMode(WIDTH, HEIGHT), "Amia: Mond", sf::Style::Default, settings);
	jogo.window.setPosition(Vector2i(VideoMode::getDesktopMode().width / 2 - jogo.window.getSize().x / 2,
			VideoMode::getDesktopMode().height / 2 - jogo.window.getSize().y / 2));

	//jogo.window.setVerticalSyncEnabled(false);
	jogo.mainMenu();

	jogo.~Jogo();
	
	return 0;
}
