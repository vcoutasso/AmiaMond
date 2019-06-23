#include "obstaculos.hpp"
#include "jogo.hpp"

#include <string>
#include <iostream>


ObstaculoEstatico::ObstaculoEstatico() {
	speed = -12;
}

void ObstaculoEstatico::updatePosition() {
	setPosition(getPosition().x + speed, getPosition().y);
}

ObstaculoGiratorio::ObstaculoGiratorio() {
	angularSpeed = static_cast<int>(rand()) % 5;
}

ObstaculoVazado::ObstaculoVazado() {
	
}

void ObstaculoEstatico::setInitialPosition() {
	float num = rand() % 11;
	num /= 10;

	if (num < 0.1)
		num = 0.1;
	else if (num > 0.9)
		num = 0.9;

	sf::Vector2f pos(WIDTH + sprite.getLocalBounds().width / 2, num * HEIGHT);

	setPosition(pos);

}

sf::Vector2f ObstaculoEstatico::getPosition() {
	return pos;
}

void ObstaculoEstatico::setPosition(sf::Vector2f pos) {
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	sprite.setPosition(sf::Vector2f(pos));
}

void ObstaculoEstatico::setPosition(float x, float y) {
	this->pos.x = x;
	this->pos.y = y;
	sprite.setPosition(x, y);
}

void ObstaculoEstatico::setTexture() {
	auto *textureFiles = new std::string[2];

	textureFiles[0] = "bin/obstaculo_1.png";
	textureFiles[1] = "bin/obstaculo_2.png";

	texture.loadFromFile(textureFiles[rand() % 2]);
	sprite.setTexture(texture);

	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	setInitialPosition();

	delete[] textureFiles;
}

void ObstaculoGiratorio::setTexture() {
	auto *textureFiles = new std::string[2];

	textureFiles[0] = "bin/obstaculo_1.png";
	textureFiles[1] = "bin/obstaculo_2.png";

	texture.loadFromFile(textureFiles[rand() % 2]);
	sprite.setTexture(texture);

	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	setInitialPosition();

	delete[] textureFiles;
}

void ObstaculoVazado::setTexture() {
	auto *textureFiles = new std::string[2];

	textureFiles[0] = "bin/obstaculo_3.png";
	textureFiles[1] = "bin/obstaculo_4.png";

	texture.loadFromFile(textureFiles[rand() % 2]);
	sprite.setTexture(texture);

	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	setInitialPosition();

	delete[] textureFiles;
}

