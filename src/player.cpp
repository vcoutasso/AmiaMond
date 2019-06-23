#include "player.hpp"
#include <string>
#include <iostream>

#define WIDTH 1920
#define HEIGHT 1080

Player::Player() {
	pos = sf::Vector2f(0, 0);

	speed = 0;
}

void Player::setPlayerTexture(std::string pathToTexture) {
	if (!playerTexture.loadFromFile(pathToTexture))
		std::cout << "Error: Could not load texture! Path to file: " << pathToTexture << std::endl;
	else {
		player.setTexture(&playerTexture);
	}

}

void Player::createPlayer(sf::Vector2f pos, sf::Vector2f scale, std::string pathToTexture, float speed)
{
	this->pos = pos;
	player.setPosition(pos.x, pos.y);

	this->scale = scale;

	setPlayerTexture(pathToTexture);
	this->speed = speed;

	player.setSize(sf::Vector2f(playerTexture.getSize()));
	player.setScale(scale);
}

void Player::boolPosition()
{
	if (rise == true && checkPosition() == 1 && player.getPosition().y >= speed)
		player.setPosition(player.getPosition().x, player.getPosition().y - speed);

	if (rise == false && checkPosition() == 1 && (player.getPosition().y + (player.getSize().y * scale.y) <= (HEIGHT - speed)))
		player.setPosition(player.getPosition().x, player.getPosition().y + speed);
}

int Player::checkPosition()
{
	int aux = 1;

	if (player.getPosition().y < 0 || (player.getPosition().y + (player.getSize().y * scale.y)) > HEIGHT){
		aux = -1;
	}

	return aux;
}

float Player::getSpeed() {
	return speed;
}

void Player::setSpeed(float speed)
{
	this->speed = speed;
}

void Player::resetSpeed() {
	speed = 5;
}

float Player::changeSpeed(float extraSpeed) {
	speed += extraSpeed;
	return speed;
}
