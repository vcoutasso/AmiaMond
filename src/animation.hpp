#ifndef _ANIMATION_HPP
#define _ANIMATION_HPP

#include "menu.hpp"

//Colocando classe Animation, que vai fazer toda a animação do menu
class Animation {
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchtime);

	sf::IntRect uvRect;

	void updateX(int row, float deltaTime);
	void updateY(int column, float deltaTime);

private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

#endif