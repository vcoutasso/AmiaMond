#ifndef _OBSTACULOS_HPP
#define _OBSTACULOS_HPP

#include <SFML/Graphics.hpp>

class ObstaculoEstatico {
	private:
		sf::Vector2f pos;
		float speed;

	protected:
		void setInitialPosition();

	public:
		ObstaculoEstatico();
		sf::Texture texture;
		sf::Sprite sprite;

		virtual void setTexture();

		void updatePosition();
		sf::Vector2f getPosition();

		void setPosition(float x, float y);
		void setPosition(sf::Vector2f pos);

};

class ObstaculoGiratorio : public ObstaculoEstatico {
	private:
		float angularSpeed;

	public:
		ObstaculoGiratorio();

		void setTexture() override;

};

class ObstaculoVazado : public ObstaculoEstatico {
	private:
		sf::RectangleShape vazado1;
		sf::RectangleShape vazado2;

	public:
		ObstaculoVazado();

		void setTexture() override;

};

#endif
