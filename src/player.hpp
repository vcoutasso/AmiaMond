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
		sf::Clock temporizador; // Conta o tempo que o jogador ficou sem colisoes. Caso se mantenha um tempo minimo sem colidir, ganha velocidade para retornar � posi��o inicial.

	public:
		float initialX; // Posição inicial em x de todos os bonecos.

		bool voltando; // Volta para a posicao x inicial se ficar tempo o suficiente sem colidir
		bool morreu; // Indica se o jogador ainda está no ojogo ou se ficou para tras (morreu)

		int num; // Indica o numero do jogador

		Player(); // Construtor

		bool rise = false;
		sf::Sprite sprite;
		
		void setPlayerTexture(std::string pathToTexture);
		void createPlayer(sf::Vector2f pos, sf::Vector2f scale, std::string pathToTexture, float speed, int num);

		void updatePosition(); // Move para cima e para baixo
		void setPosition(sf::Vector2f pos);
		sf::Vector2f getPosition();

		float getSpeed();
		void setSpeed(float speed);
		void resetSpeed();
		float changeSpeed(float extraSpeed);

		void ajustaPosicao(const sf::Sprite& obstaculo, bool vertical, float speedObstaculo);

		void restartTemporizador();
		sf::Time elapsedTime();

		void moveX(float x);
};




#endif