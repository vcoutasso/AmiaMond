#include "obstaculos.hpp"
#include "jogo.hpp"

#include <string>
#include <iostream>

/* Métodos de ObstaculoEstatico */

// Construtor de ObstaculoEstatico. As outras opções são configuradas em setTexture(). setTexture() não pode ser chamada aqui, pois é uma função virtual.
// Se for chamada aqui, sempre será utilizada a implementação de ObstaculoEstatico, e nunca as de ObstaculoGiratorio e ObstaculoVazado.
ObstaculoEstatico::ObstaculoEstatico() {
	speed = -12;
}

// Atualiza a posição do objeto com base na velocidade.
void ObstaculoEstatico::updatePosition() {
	setPosition(getPosition().x + speed, getPosition().y);
}

// Escolhe aleatoriamente a posição inicial do sprite. Todos começam na mesma posição em x (final da tela) mas y varia
// As posições da origem em y permitidas vão de 0.1 * HEIGHT até 0.9 * HEIGHT
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

// Retorna a posição do objeto.
sf::Vector2f ObstaculoEstatico::getPosition() {
	return pos;
}

// Seta a posição do objeto com sf::Vector2f.
void ObstaculoEstatico::setPosition(sf::Vector2f pos) {
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	sprite.setPosition(sf::Vector2f(pos));
}

// Seta a posição do objeto com 2 floats.
void ObstaculoEstatico::setPosition(float x, float y) {
	this->pos.x = x;
	this->pos.y = y;
	sprite.setPosition(x, y);
}

// Carrega e usa a textura, que é escolhida aleatoriamente entre a lista (textureFiles) de possiveis arquivos.
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



/* Métodos de ObstaculoGiratorio */

// Carrega e usa a textura, que é escolhida aleatoriamente entre a lista (textureFiles) de possiveis arquivos.
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

// Construtor de ObstaculoGiratorio. Chamado antes do construror de ObstaculoEstatico
ObstaculoGiratorio::ObstaculoGiratorio() {
	angularSpeed = static_cast<int>(rand()) % 11;
	angularSpeed -= 5;
}

// Atualiza a posição do objeto com base na velocidade.
void ObstaculoGiratorio::updatePosition() {
	setPosition(getPosition().x + speed, getPosition().y);
	sprite.rotate(angularSpeed);
}



/* Métodos de ObstaculOVazado */

// Carrega e usa a textura, que é escolhida aleatoriamente entre a lista (textureFiles) de possiveis arquivos.
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

// Construtor de ObstaculoVazado. Chamado antes do construror de ObstaculoEstatico
ObstaculoVazado::ObstaculoVazado() {
	// TODO: Implementar as posições dos retangulos para representar os espaços vazios
}
