#ifndef _MENU_HPP
#define _MENU_HPP

#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "jogo.hpp"
#include "nave.hpp"
#include "obstaculos.hpp"
//#include "corrida.hpp"

using namespace std;

class Option {		//Funcionalidade dos Botões
	private:
		bool hovering;
		bool selected;

	public:
		Option(float px, float py, unsigned int s, string t, string pathToFont);
		sf::Font font;
		sf::Text text;

		void setHovering(bool b);
		bool getHovering();
		bool isHovering(int x, int y);
		void setSelected(bool b);
		bool getSelected();

		void setFont(string pathToFile);
};

#endif
