#include "menu.hpp"

#define WIDTH 1280
#define HEIGHT 720

using namespace sf;

int main(int argc, char** argv) {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	Jogo jogo;

	// Habilitar anti aliasing se precisar
	jogo.window.create(VideoMode(WIDTH, HEIGHT), "Amia: Mond", sf::Style::Default, settings);

	//jogo.window.setVerticalSyncEnabled(false);
	jogo.mainMenu();

	jogo.~Jogo();
	
	return 0;
}
