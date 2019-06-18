#include <string>
#include <iostream>

#include "option.hpp"

// Inicializa a classe. O objeto Text contem as informações de posição do texto e a string da opção. 
Option::Option(float px, float py, unsigned int s, std::string t, std::string pathToFont) {
	setFont(pathToFont);

	selected = false;
	hovering = false;

	text.setCharacterSize(s);
	text.setString(t);
	text.setPosition(px - text.getLocalBounds().width / 2, py);
}

//Printar para mudar o fundo nas opções para não confundir na imagem
sf::RectangleShape Option::printRect()
{
	sf::RectangleShape rect(sf::Vector2f(text.getGlobalBounds().width + 15, text.getGlobalBounds().height + 15));

	rect.setFillColor(sf::Color::Black);
	rect.setPosition(sf::Vector2f(text.getPosition().x - 7, text.getPosition().y + 6 - 7));

	return rect;
}

// Seta o valor do atributo hovering. 
void Option::setHovering(bool b) {
	hovering = b;
}

// Retorna o valor do atributo hovering.
bool Option::getHovering() {
	return hovering;
}

// Verifica se as coordenadas x e y representam um ponto que está em cima de Text. A principio para ser usado com as coordenadas do mouse.
bool Option::isHovering(int x, int y) {
	sf::FloatRect  pos = text.getGlobalBounds();
	if (pos.contains(x,y))
		return true;
	else
		return false;
}

void Option::setSelected(bool b)
{
	selected = b;
}

bool Option::getSelected() {
	return selected;
}

// Configura text
void Option::setFont(std::string pathToFile) {
	if (!font.loadFromFile(pathToFile))
		std::cout << "Error: Could not load font! Path to file: " << pathToFile << std::endl;
	else {
		text.setFont(font);
		text.setFillColor(BUTTON_COLOR);
		text.setStyle(sf::Text::Bold);
	}
}