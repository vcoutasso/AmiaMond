#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Player {		//Inserindo todos os dados do player generalizado
	private:
		sf::Vector2f pos;
		sf::Vector2f scale;
		float speed;
		sf::Texture playerTexture;
		sf::Clock temporizador; // Conta o tempo que o jogador ficou sem colisoes. Caso se mantenha um tempo minimo sem colidir, ganha velocidade para retornar à posição inicial.

	public:

		Player();

		bool rise = false;
		sf::Sprite sprite;
		
		void setPlayerTexture(std::string pathToTexture);
		void createPlayer(sf::Vector2f pos, sf::Vector2f scale, std::string pathToTexture, float speed);

		void updatePosition();
		void setPosition(sf::Vector2f pos);
		sf::Vector2f getPosition();

		float getSpeed();
		void setSpeed(float speed);
		void resetSpeed();
		float changeSpeed(float extraSpeed);

		void ajustaPosicao(const sf::Sprite& obstaculo, bool vertical, float speedObstaculo);

		void restartTemporizador();
		sf::Time elapsedTime();
};




#endif