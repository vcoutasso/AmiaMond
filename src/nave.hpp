#ifndef _NAVE_HPP
#define _NAVE_HPP

#include "menu.hpp"

class Nave {
	private:
		sf::Vector2f pos;
		float speed;
	public:
		Nave(sf::Vector2f p);
		Nave(float x, float y);
		Nave();
	
		sf::RectangleShape shape;

		float getSpeed();
		void resetSpeed();
		float changeSpeed(float x);
};


#endif
