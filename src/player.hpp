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

public:
	Player();

	bool rise = false;
	sf::RectangleShape player;
	
	void setPlayerTexture(std::string pathToTexture);
	void createPlayer(sf::Vector2f pos,sf::Vector2f scale, std::string pathToTexture, float speed);

	void boolPosition(); //Função para verificar se está subindo ou descendo
	int checkPosition();

	float getSpeed();
	void setSpeed(float speed);
	void resetSpeed();
	float changeSpeed(float extraSpeed);
};




#endif