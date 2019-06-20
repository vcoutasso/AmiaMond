#include "obstaculos.hpp"
#include <string>

ObstaculoEstatico::ObstaculoEstatico() {
	textureFiles = new std::string[4];
	textureFiles[0] = "bin/obstaculo_1.png";
	textureFiles[1] = "bin/obstaculo_2.png";
	textureFiles[2] = "bin/obstaculo_3.png";
	textureFiles[3] = "bin/obstaculo_4.png";

	texture.loadFromFile(textureFiles[1]);
	sprite.setPosition(sf::Vector2f(0, 0));
	sprite.setTexture(texture);

	setPosition(0, 0);
}

sf::Vector2f ObstaculoEstatico::getPosition() {
	return pos;
}

void ObstaculoEstatico::setPosition(sf::Vector2f pos) {
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

void ObstaculoEstatico::setPosition(float x, float y) {
	this->pos.x = x;
	this->pos.y = y;
}

