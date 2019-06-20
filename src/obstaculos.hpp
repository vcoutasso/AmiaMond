#ifndef _OBSTACULOS_HPP
#define _OBSTACULOS_HPP

#include <SFML/Graphics.hpp>

class Obstaculos {
	private:
		sf::Vector2f pos;
		sf::RectangleShape shape;
		sf::Texture texture;

		float speed;

	public:
		Obstaculos(sf::Vector2f pos, std::string pathToFile);
		Obstaculos(float x, float y);

		sf::Vector2f getPosition();
		void setPosition(float x, float y);
		void setPosition(sf::Vector2f pos);
		void draw();

};

class ObstaculoEstatico : public Obstaculos {


};

class ObstaculoGiratorio : public Obstaculos {

};

#endif
