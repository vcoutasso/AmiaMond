#ifndef _MENU_HPP
#define _MENU_HPP

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Option {
	private:
		bool hovering;

	public:
		Option(float px, float py, unsigned int s, string t, string pathToFont);
		sf::Font font;
		sf::Text text;

		void setHovering(bool b);
		bool getHovering();
		bool isHovering(int x, int y);

		void setFont(string pathToFile);
};


#endif
