#include "obstaculos.hpp"

Obstaculos::Obstaculos(sf::Vector2f p) {
	setPosition(p);
}

Obstaculos::Obstaculos(float x, float y) {
	setPosition(x, y);
}

sf::Vector2f Obstaculos::getPosition() {
	return pos;
}

void Obstaculos::setPosition(sf::Vector2f p) {
	pos.x = p.x;
	pos.y = p.y;
}

void Obstaculos::setPosition(float x, float y) {
	pos.x = x;
	pos.y = y;
}

