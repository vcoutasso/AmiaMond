#ifndef _JOGO_HPP
#define _JOGO_HPP

#include <SFML/Window.hpp>
#include "menu.hpp"


class Jogo {
	public:
		Jogo();

		sf::RenderWindow window;

		void openInstructions();

		void openJogar();
		
		void mainMenu();

		~Jogo();


};



#endif
