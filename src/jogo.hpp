#ifndef _JOGO_HPP
#define _JOGO_HPP

#include "menu.hpp"

class Jogo {
	public:
	Jogo();

	sf::RenderWindow window;
	sf::SoundBuffer buffer;
	sf::Sound sound;

	
	int mainMenu();

	int openInstructions();

	int openJogar();

	int playCorrida(int nplayers);

	~Jogo();

};



#endif
