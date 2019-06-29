#include "corrida.hpp"
#include <cstdlib> 

// Inicializa com a quantiade adequada de jogadores.
Corrida::Corrida(int n) {
	setNumPlayers(n);
}

void Corrida::initPlayer(sf::Vector2f pos, sf::Vector2f scale, std::string pathToTexture, float speed) {
	player.push_back(new Player);
	player.back()->createPlayer(pos, scale, pathToTexture, speed);
}

// Decide aleatoriamente o tipo do proximo obstaculo a ser gerado
void Corrida::criaObstaculo() {
	const auto num = rand() % 3;

	if (num == 0) {
		obstaculosEstaticos.push_back(new ObstaculoEstatico);
		obstaculosEstaticos.back()->setTexture();
	}
	else if (num == 1) {
		obstaculosGiratorios.push_back(new ObstaculoGiratorio);
		obstaculosGiratorios.back()->setTexture();
	}
	else { // if num == 2
		obstaculosVazados.push_back(new ObstaculoVazado);
		obstaculosVazados.back()->setTexture();
	}
}

void Corrida::setNumPlayers(int n) {
	numPlayers = n;
}

int Corrida::getNumPlayers() {
	return numPlayers;
}



