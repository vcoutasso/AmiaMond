#include "player.hpp"
#include <string>
#include <iostream>

#define WIDTH 1920
#define HEIGHT 1080

Player::Player() {
	pos = sf::Vector2f(0, 0);

	speed = 9;
}

void Player::setPlayerTexture(std::string pathToTexture) {
	if (!playerTexture.loadFromFile(pathToTexture))
		std::cout << "Error: Could not load texture! Path to file: " << pathToTexture << std::endl;
	else
		sprite.setTexture(playerTexture);

}

void Player::createPlayer(sf::Vector2f pos, sf::Vector2f scale, std::string pathToTexture, float speed) {


	//setPlayerTexture(pathToTexture);
	playerTexture.loadFromFile(pathToTexture);
	sprite.setTexture(playerTexture);
	sprite.setScale(scale);
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	sprite.setPosition(pos);
	setSpeed(speed);

}

void Player::boolPosition() {

	if (rise == true && checkPosition() == 1 && sprite.getPosition().y >= speed)
		sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - speed);

	if (rise == false && checkPosition() == 1 && (sprite.getPosition().y + sprite.getLocalBounds().height) <= (HEIGHT - speed))
		sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + speed);
}


int Player::checkPosition() {
	int aux = 1;

	if (sprite.getPosition().y < 0 || (sprite.getPosition().y + sprite.getLocalBounds().height ) > HEIGHT){
		aux = -1;
	}

	return aux;
}

void Player::updatePosition() {
	if (rise) {
		if (sprite.getPosition().y >= 0 + (sprite.getTexture()->getSize().y * sprite.getScale().y) / 2)
			setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y - speed));
	}
	else {
		if (sprite.getPosition().y <= HEIGHT - (sprite.getTexture()->getSize().y * sprite.getScale().y) / 2)
			setPosition(sf::Vector2f(sprite.getPosition().x, sprite.getPosition().y + speed));
	}
}

void Player::setPosition(sf::Vector2f pos) {
	this->pos = pos;
	sprite.setPosition(pos);
}

sf::Vector2f Player::getPosition() {
	return pos;
}
 

float Player::getSpeed() {
	return speed;
}

void Player::setSpeed(float speed) {
	this->speed = speed;
}

void Player::resetSpeed() {
	speed = 5;
}

float Player::changeSpeed(float extraSpeed) {
	speed += extraSpeed;
	return speed;
}
