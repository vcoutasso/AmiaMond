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

// Seta o valor do atributo hovering. Não sei se vai ser realmente util em algum momento
void Option::setHovering(bool b) {
	hovering = b;
}

// Retorna o valor do atributo hovering.
bool Option::getHovering() {
	return hovering;
}

// Verifica se as coordenadas x e y representam um ponto que está em cima de Text. A principio para ser usado com as coordenadas do mouse.
// TODO: Implementação.
bool Option::isHovering(int x, int y) {
	sf::FloatRect  pos = text.getGlobalBounds();
	if (pos.contains(x,y))
		return true;
	else
		return false;
}

// Configura text
void Option::setFont(string pathToFile) {
	if (!font.loadFromFile(pathToFile))
		cout << "Error: Could not load font! Path to file: " << pathToFile << endl;
	else {
		text.setFont(font);
		text.setFillColor(sf::Color::Red);
		text.setStyle(sf::Text::Bold);
	}
}
