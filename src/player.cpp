#include "player.hpp"
#include <string>
#include <iostream>

#define WIDTH 1920
#define HEIGHT 1080

// Construtor padrão
Player::Player() {
	pos = sf::Vector2f(0, 0);

	speed = 9;
}

// Carrega a textura
void Player::setPlayerTexture(std::string pathToTexture) {
	if (!playerTexture.loadFromFile(pathToTexture))
		std::cout << "Error: Could not load texture! Path to file: " << pathToTexture << std::endl;
	else
		sprite.setTexture(playerTexture);

}

// Seta todos os atributos necessarios do objeto
void Player::createPlayer(sf::Vector2f pos, sf::Vector2f scale, std::string pathToTexture, float speed) {

	setPlayerTexture(pathToTexture);
	sprite.setScale(scale);
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	sprite.setPosition(pos);
	setSpeed(speed);

}

// Atualiza a posição do objeto com base na velocidade. Só altera a posição se estiver dentro dos limites da janela.
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

// Seta a posição do jogador e do sprite.
void Player::setPosition(sf::Vector2f pos) {
	this->pos = pos;
	sprite.setPosition(pos);
}

// Retoran a posição do jogador e do sprite. Poderia ser utilizado sprite.getPosition(). Ambos tem o mesmo valor.
sf::Vector2f Player::getPosition() {
	return pos;
}
 
// Retorna speed
float Player::getSpeed() {
	return speed;
}

// Seta speed
void Player::setSpeed(float speed) {
	this->speed = speed;
}

// Reseta speed para o valor inicial
void Player::resetSpeed() {
	speed = 9;
}

// Incrementa, ou decrementa, a velocidade do jogador
float Player::changeSpeed(float extraSpeed) {
	speed += extraSpeed;
	return speed;
}
