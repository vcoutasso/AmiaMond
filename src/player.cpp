#include <string>
#include <iostream>

#include "player.hpp"


#define WIDTH 1920
#define HEIGHT 1080

// Construtor padrão
Player::Player() {
	pos = sf::Vector2f(0, 0);

	initialX = 860;

	speed = 9;
	voltando = true;
	morreu = false;
}

// Move o jogador no eixo x. Normalmente o jogador fica parado e os obstaculos que se movem.
// Esse método permite com que o jogador possa mudar sua posição no eixo x
void Player::moveX(float x) {
	setPosition(sf::Vector2f(getPosition().x + x, getPosition().y));
}

// Carrega a textura
void Player::setPlayerTexture(std::string pathToTexture) {
	if (!playerTexture.loadFromFile(pathToTexture))
		std::cout << "Error: Could not load texture! Path to file: " << pathToTexture << std::endl;
	else
		sprite.setTexture(playerTexture);

}

// Seta todos os atributos necessarios do objeto
void Player::createPlayer(sf::Vector2f pos, sf::Vector2f scale, std::string pathToTexture, float speed, int num) {

	setPlayerTexture(pathToTexture);
	sprite.setScale(scale);
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	setPosition(pos);
	setSpeed(speed);

	this->num = num;

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

	if (getPosition().x < -50)
			morreu = true;
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

// Ajusta a posição do boneco de acordo com a colisão (por exemplo se colidiu de cima pra baixo ou de frente)
void Player::ajustaPosicao(const sf::Sprite& obstaculo, const bool vertical, const float speedObstaculo) {
	const sf::Vector2f prancha(this->getPosition().x, this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height);
	const sf::Vector2f cabeca(this->getPosition().x, this->sprite.getGlobalBounds().top);

	const sf::Vector2f playerTopLeft(this->sprite.getGlobalBounds().left, this->sprite.getGlobalBounds().top);
	const sf::Vector2f playerTopRight(this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().top);

	const sf::Vector2f playerBottomLeft(this->sprite.getGlobalBounds().left, this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height);
	const sf::Vector2f playerBottomRight(this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height);

	const sf::Vector2f topLeft(obstaculo.getGlobalBounds().left, obstaculo.getGlobalBounds().top);
	const sf::Vector2f topRight(obstaculo.getGlobalBounds().left + obstaculo.getGlobalBounds().width, obstaculo.getGlobalBounds().top);

	const sf::Vector2f bottomLeft(obstaculo.getGlobalBounds().left, obstaculo.getGlobalBounds().top + obstaculo.getGlobalBounds().height);
	const sf::Vector2f bottomRight(obstaculo.getGlobalBounds().left + obstaculo.getGlobalBounds().width, obstaculo.getGlobalBounds().top + obstaculo.getGlobalBounds().height);


	if (vertical) {
		if (abs(prancha.y - topLeft.y) < 5) // Colisão de cima para baixo. Boneco deve subir para compensar
			this->setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y - this->getSpeed()));
		else if (abs(cabeca.y - bottomLeft.y) < 5) // Colisão de baixo para cima. Boneco deve descer para compensar.
			this->setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + this->getSpeed()));
		else if (cabeca.x <= topLeft.x) // Colisão de frente. Boneco deve ser arrastado pelo obstaculo.
			this->setPosition(sf::Vector2f(this->getPosition().x + speedObstaculo, this->getPosition().y));
	}
	else {
		if (abs(prancha.y - topLeft.y) < 10) // Colisão de cima para baixo. Boneco deve subir para compensar.
			this->setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y - this->getSpeed()));
		else if (abs(cabeca.y - bottomLeft.y) < 10) // Colisão de baixo para cima. Boneco deve descer para compensar.
			this->setPosition(sf::Vector2f(this->getPosition().x, this->getPosition().y + this->getSpeed()));
		else if (cabeca.x <= topLeft.x) // Colisão de frente. Boneco deve ser arrastado pelo obstaculo.
			this->setPosition(sf::Vector2f(this->getPosition().x + speedObstaculo, this->getPosition().y));
	}

	restartTemporizador();
}

void Player::restartTemporizador() {
	temporizador.restart();
}

sf::Time Player::elapsedTime() {
	return temporizador.getElapsedTime();
}
