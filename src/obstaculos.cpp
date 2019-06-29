#include "obstaculos.hpp"
#include "jogo.hpp"

#include <string>
#include <iostream>

/* Métodos de ObstaculoEstatico */

// Construtor de ObstaculoEstatico. As outras opcoes sao configuradas em setTexture(). setTexture() nao pode ser chamada aqui, pois e uma funcao virtual.
// Se for chamada aqui, sempre sera utilizada a implementacao de ObstaculoEstatico, e nunca as de ObstaculoGiratorio e ObstaculoVazado.
ObstaculoEstatico::ObstaculoEstatico() {
	speed = -12;
}

// Atualiza a posicao do objeto com base na velocidade.
void ObstaculoEstatico::updatePosition() {
	setPosition(getPosition().x + speed, getPosition().y);
}

// Escolhe aleatoriamente a posicaoo inicial do sprite. Todos come�am na mesma posi��o em x (final da tela) mas y varia
// As posicoes da origem em y permitidas vao de 0.1 * HEIGHT ate 0.9 * HEIGHT
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

// Retorna a posicao do objeto.
sf::Vector2f ObstaculoEstatico::getPosition() {
	return pos;
}

// Seta a posicao do objeto com sf::Vector2f.
void ObstaculoEstatico::setPosition(sf::Vector2f pos) {
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	sprite.setPosition(sf::Vector2f(pos));
}

// Seta a posicao do objeto com 2 floats.
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

	int n = rand() % 2;

	texture.loadFromFile(textureFiles[n]);
	sprite.setTexture(texture);

	if (n == 0)
		this->vertical = true;
	else
		this->vertical = false;

	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	setInitialPosition();

	delete[] textureFiles;
}

void ObstaculoEstatico::setSpeed(float speed) {
	this->speed = speed;
}

float ObstaculoEstatico::getSpeed() {
	return this->speed;
}

bool ObstaculoEstatico::isVertical() {
	return vertical;
}


/* Métodos de ObstaculoGiratorio */

// Carrega e usa a textura, que é escolhida aleatoriamente entre a lista (textureFiles) de possiveis arquivos.
void ObstaculoGiratorio::setTexture() {
	auto *textureFiles = new std::string[2];

	textureFiles[0] = "bin/obstaculo_1.png";
	textureFiles[1] = "bin/obstaculo_2.png";
	
	int n = rand() % 2;

	loadedFile = textureFiles[n];

	texture.loadFromFile(textureFiles[n]);
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

// Atualiza a posicao do objeto com base na velocidade.
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

	int n = rand() % 2;

	loadedFile = textureFiles[n];

	texture.loadFromFile(textureFiles[n]);
	sprite.setTexture(texture);

	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	setInitialPosition();

	delete[] textureFiles;
}

// Construtor de ObstaculoVazado. Chamado antes do construror de ObstaculoEstatico
ObstaculoVazado::ObstaculoVazado() {
	// TODO: Implementar as posicoes dos retangulos para representar os espaços vazios
}
