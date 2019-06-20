#include "obstaculos.hpp"

Obstaculos::Obstaculos(sf::Vector2f pos, std::string pathToFile) {
	setPosition(pos);
}

Obstaculos::Obstaculos(float x, float y) {
	setPosition(x, y);
}

sf::Vector2f Obstaculos::getPosition() {
	return pos;
}

void Obstaculos::setPosition(sf::Vector2f pos) {
	this->pos.x = pos.x;
	this->pos.y = pos.y;
}

void Obstaculos::setPosition(float x, float y) {
	this->pos.x = x;
	this->pos.y = y;
}

