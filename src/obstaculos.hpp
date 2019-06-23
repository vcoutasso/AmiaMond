#ifndef _OBSTACULOS_HPP
#define _OBSTACULOS_HPP

#include <SFML/Graphics.hpp>

class ObstaculoEstatico {
	protected:
		sf::Vector2f pos;
		void setInitialPosition();
		float speed;

	public:
		virtual ~ObstaculoEstatico() = default;
		ObstaculoEstatico();
		sf::Texture texture;
		sf::Sprite sprite;

		virtual void setTexture();
	
		virtual void updatePosition();

		sf::Vector2f getPosition();

		void setPosition(float x, float y);
		void setPosition(sf::Vector2f pos);

};

class ObstaculoGiratorio : public ObstaculoEstatico {
	private:
		float angularSpeed;

	public:
		ObstaculoGiratorio();

		void updatePosition() override;

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
