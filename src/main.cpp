#include <SFML/Graphics.hpp>

#include <ctime>

#include "jogo.hpp"

#ifdef _DEBUG
#define STYLE sf::Style::Default
#else
#define STYLE sf::Style::Fullscreen
#endif


int main(int argc, char** argv) {

	srand(time(nullptr));

	// Seta o nivel de antialiasing para 8
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	// Objeto princpal do jogo
	Jogo jogo;

	// Cria a janela e logo em seguida centraliza.
	jogo.window.create(sf::VideoMode(WIDTH, HEIGHT), "Amia::Mond", STYLE, settings);
	jogo.window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - jogo.window.getSize().x / 2,
		sf::VideoMode::getDesktopMode().height / 2 - jogo.window.getSize().y / 2));
	jogo.window.setVerticalSyncEnabled(true);

	// Chama o menu principal do jogo. É a partir desse método que todos os outros são chamados, formando uma pilha.
	// Para sair do jogo, basta retornar -1 e a pilha será desempilhada até voltar para cá.
	// Para voltar para a tela anterior, basta retornar 1.
	jogo.mainMenu();


	// Apenas para remover o warning de nao estar usando argc e argv
	(void)argv;
	(void)argc;
	
	return 0;
}
