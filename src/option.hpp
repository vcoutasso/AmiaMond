#ifndef _OPTION_HPP
#define _OPTION_HPP

#define FPS 60.0

#define BUTTON_COLOR sf::Color::White
#define HOVER_COLOR sf::Color(150, 150, 150)
#define SELECTED_COLOR sf::Color::Black

#include <SFML/Graphics.hpp>
#include <string>

class Option {		//Funcionalidade dos Botões
	private:
		bool hovering;
		bool selected;

	public:
		Option(float px, float py, unsigned int s, std::string t, std::string pathToFont);
		sf::Font font;
		sf::Text text;

		void setHovering(bool b);
		bool getHovering() const;
		bool isHovering(int x, int y) const;
		void setSelected(bool b);
		bool getSelected() const;

		void setFont(std::string pathToFile);

		sf::RectangleShape printRect() const;

};

#endif
