#include "jogo.hpp"
#include "menu.hpp"

#define WIDTH 1280
#define HEIGHT 720

using namespace sf;

int main(int argc, char** argv) {

	Jogo jogo;

	// Habilitar anti aliasing se precisar
	jogo.window.create(VideoMode(WIDTH, HEIGHT), "Amia: Mond");
	//jogo.window.setVerticalSyncEnabled(false);
	jogo.mainMenu();

	jogo.~Jogo();
	
	return 0;
}
