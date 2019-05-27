#ifndef _JOGO_HPP
#define _JOGO_HPP

#include <SFML/Window.hpp>
#include "menu.hpp"


class Jogo {
	public:
		Jogo();

		sf::RenderWindow window;
		
		void mainMenu();

		~Jogo();


};



#endif
