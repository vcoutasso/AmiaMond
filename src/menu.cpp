#include "menu.hpp"

using namespace std;

// Inicializa a classe. O objeto Text contem as informações de posição do texto e a string da opção. 
Option::Option(float px, float py, unsigned int s, string t, string pathToFont) {
	setFont(pathToFont);

	hovering = false;

	text.setPosition(px, py);
	text.setCharacterSize(s);
	text.setString(t);
}

void Option::setHovering(bool b) {
	hovering = b;
}

bool Option::isHovering(int x, int y) {
	

	return hovering;
}

void Option::setFont(string pathToFile) {
	if (!font.loadFromFile(pathToFile))
		cout << "Error: Could not load font! Path to file: " << pathToFile << endl;
	else {
		text.setFont(font);
		text.setFillColor(sf::Color::Red);
		text.setStyle(sf::Text::Bold);
	}
}
