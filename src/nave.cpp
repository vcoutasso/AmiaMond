#include "nave.hpp"

Nave::Nave(sf::Vector2f p) {
	pos.x = p.x;
	pos.y = p.y;

	speed = 5;

	shape.setSize(sf::Vector2f(50, 30));
	shape.setPosition(pos.x, pos.y);
}

Nave::Nave(float x, float y) {
	pos.x = x;
	pos.y = y;

	speed = 5;

	shape.setSize(sf::Vector2f(50, 30));
	shape.setPosition(pos.x, pos.y);
}

Nave::Nave() {
	pos = sf::Vector2f(0, 0);

	speed = 0;

}

float Nave::getSpeed() {
	return speed;
}

void Nave::resetSpeed() {
	speed = 5;
}

float Nave::changeSpeed(float x) {
	speed += x;
	return speed;
}
