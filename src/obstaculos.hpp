#ifndef _OBSTACULOS_HPP
#define _OBSTACULOS_HPP

#include "menu.hpp"

class Obstaculos {
	private:
		sf::Vector2f pos;
		sf::RectangleShape shape;
	public:
		Obstaculos(sf::Vector2f p);
		Obstaculos(float x, float y);

		sf::Vector2f getPosition();
		void setPosition(float x, float y);
		void setPosition(sf::Vector2f);

};

#endif
