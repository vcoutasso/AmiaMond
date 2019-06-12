#ifndef _JOGO_HPP
#define _JOGO_HPP

#include "menu.hpp"

//Colocando classe Animation, que vai fazer toda a animação do menu
class Animation {
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchtime);

	sf::IntRect uvRect;

	void update(int row, float deltaTime);

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

class Jogo {
	public:
	Jogo();

	sf::RenderWindow window;
	sf::SoundBuffer buffer;
	sf::Sound sound;

	
	int mainMenu();

	int openInstructions();

	int openJogar();

	int playCorrida(int nplayers);

	~Jogo();

};



#endif
