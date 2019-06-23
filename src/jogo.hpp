#ifndef _JOGO_HPP
#define _JOGO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "animation.hpp"

constexpr int WIDTH = 1920;
constexpr int HEIGHT = 1080;

class Jogo {
	public:
	Jogo();

	sf::RenderWindow window;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Music music;
	sf::Font font;
	sf::Text fps;

	int mainMenu();

	int openInstructions();

	int openJogar(Animation& animation, sf::RectangleShape& background);

	int playCorrida(int nplayers);

	void showFPS(float deltaTime);

};



#endif
