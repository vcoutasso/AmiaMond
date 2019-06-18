#ifndef _JOGO_HPP
#define _JOGO_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "animation.hpp"

class Jogo {
	public:
	Jogo();

	sf::RenderWindow window;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Music music;

	int mainMenu();

	int openInstructions();

	int openJogar(Animation& animation, sf::RectangleShape& background);

	int playCorrida(int nplayers);

	void showFPS(float deltaTime);

	~Jogo();

};



#endif
