#ifndef _OBSTACULOS_HPP
#define _OBSTACULOS_HPP

#include <SFML/Graphics.hpp>

class ObstaculoEstatico {
	private:
		sf::Vector2f pos;
		sf::Texture texture;

		float speed;

		std::string *textureFiles;

	public:
		ObstaculoEstatico();
		sf::Sprite sprite;

		sf::Vector2f getPosition();
		void setPosition(float x, float y);
		void setPosition(sf::Vector2f pos);

};

class ObstaculoGiratorio : public ObstaculoEstatico {
	private:
		bool giratorio;
		float angularSpeed;

	public:
		ObstaculoGiratorio();

};

class ObstaculoVazado : public ObstaculoEstatico {
	private:
		sf::RectangleShape vazado1;
		sf::RectangleShape vazado2;

	public:
		ObstaculoVazado();

};

#endif
