#include <SFML/Graphics.hpp>
#include "animation.hpp"

// Construtor
Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0;

	currentImage.x = 0;
	currentImage.y = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

//Atualizado o tempo, ajeitando a frame rate
// Anima na horizontal
void Animation::updateX(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x) {
			currentImage.x = 0;
		}
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}

// Anima na vertical
void Animation::updateY(int column, float deltaTime)
{
	currentImage.x = column;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.y++;

		if (currentImage.y >= imageCount.y) {
			currentImage.y = 0;
		}
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}

// Anima na vertical e na horizontal
// Usado para arquivos muito grandes que nao cabem em imagens 1xn, como é o caso de bg_game.png
void Animation::updateXY(float deltaTime)
{
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.y++;

		if (currentImage.y >= imageCount.y) {
			currentImage.y = 0;
			currentImage.x += 1;

			if (currentImage.x >= imageCount.x) {
				currentImage.x = 0;
			}
		}
	}

	uvRect.left = currentImage.x * uvRect.width;
	uvRect.top = currentImage.y * uvRect.height;
}