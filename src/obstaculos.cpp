#include "obstaculos.hpp"
#include "jogo.hpp"

#include <string>
#include <iostream>

/* M�todos de ObstaculoEstatico */

// Construtor de ObstaculoEstatico. As outras op��es s�o configuradas em setTexture(). setTexture() n�o pode ser chamada aqui, pois � uma fun��o virtual.
// Se for chamada aqui, sempre ser� utilizada a implementa��o de ObstaculoEstatico, e nunca as de ObstaculoGiratorio e ObstaculoVazado.
ObstaculoEstatico::ObstaculoEstatico() {
	speed = -12;
}

// Atualiza a posi��o do objeto com base na velocidade.
void ObstaculoEstatico::updatePosition() {
	setPosition(getPosition().x + speed, getPosition().y);
}

// Escolhe aleatoriamente a posi��o inicial do sprite. Todos come�am na mesma posi��o em x (final da tela) mas y varia
// As posi��es da origem em y permitidas v�o de 0.1 * HEIGHT at� 0.9 * HEIGHT
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

// Retorna a posi��o do objeto.
sf::Vector2f ObstaculoEstatico::getPosition() {
	return pos;
}

// Seta a posi��o do objeto com sf::Vector2f.
void ObstaculoEstatico::setPosition(sf::Vector2f pos) {
	this->pos.x = pos.x;
	this->pos.y = pos.y;
	sprite.setPosition(sf::Vector2f(pos));
}

// Seta a posi��o do objeto com 2 floats.
void ObstaculoEstatico::setPosition(float x, float y) {
	this->pos.x = x;
	this->pos.y = y;
	sprite.setPosition(x, y);
}

// Carrega e usa a textura, que � escolhida aleatoriamente entre a lista (textureFiles) de possiveis arquivos.
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



/* M�todos de ObstaculoGiratorio */

// Carrega e usa a textura, que � escolhida aleatoriamente entre a lista (textureFiles) de possiveis arquivos.
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

// Atualiza a posi��o do objeto com base na velocidade.
void ObstaculoGiratorio::updatePosition() {
	setPosition(getPosition().x + speed, getPosition().y);
	sprite.rotate(angularSpeed);
}



/* M�todos de ObstaculOVazado */

// Carrega e usa a textura, que � escolhida aleatoriamente entre a lista (textureFiles) de possiveis arquivos.
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
	// TODO: Implementar as posi��es dos retangulos para representar os espa�os vazios
}
