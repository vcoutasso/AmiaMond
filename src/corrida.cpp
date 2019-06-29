#include "corrida.hpp"
#include <cstdlib> 

// Inicializa com a quantiade adequada de jogadores.
Corrida::Corrida(int n) {
	setNumPlayers(n);

	for (int i = 0; i < 4; i++) {
		if (i < n)
			alive[i] = true;
		else
			alive[i] = false;
	}
}

void Corrida::initPlayer(sf::Vector2f pos, sf::Vector2f scale, std::string pathToTexture, float speed) {
	player.push_back(new Player);
	player.back()->createPlayer(pos, scale, pathToTexture, speed, player.size() - 1);
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

// Itera pelo vetores de obstaculos até que remova todos os obstaculos que não estao mais visiveis na tela
void Corrida::removeObstaculos() {
	
	while (!obstaculosEstaticos.empty()) {
		if (obstaculosEstaticos.front()->getPosition().x < - obstaculosEstaticos.front()->sprite.getGlobalBounds().width / 2)
			obstaculosEstaticos.erase(obstaculosEstaticos.begin());
		else
			break;
	}

	while (!obstaculosGiratorios.empty()) {
		if (obstaculosGiratorios.front()->getPosition().x < -obstaculosGiratorios.front()->sprite.getGlobalBounds().width / 2)
			obstaculosGiratorios.erase(obstaculosGiratorios.begin());
		else
			break;
	}

	while (!obstaculosVazados.empty()) {
		if (obstaculosVazados.front()->getPosition().x < -obstaculosVazados.front()->sprite.getGlobalBounds().width / 2)
			obstaculosVazados.erase(obstaculosVazados.begin());
		else
			break;
	}
}

// Itera pelos vetores contendo os obstaculos e imprime os sprites na tela.
void Corrida::desenhaObstaculos(sf::RenderWindow& window) {
	for (auto it = obstaculosEstaticos.begin(); it != obstaculosEstaticos.end(); ++it) {
		window.draw((*it)->sprite);
		(*it)->updatePosition();
	}

	for (auto it = obstaculosGiratorios.begin(); it != obstaculosGiratorios.end(); ++it) {
		window.draw((*it)->sprite);
		(*it)->updatePosition();
	}

	for (auto it = obstaculosVazados.begin(); it != obstaculosVazados.end(); ++it) {
		window.draw((*it)->sprite);
		(*it)->updatePosition();
	}
}

void Corrida::retornaPlayers() {
	for (auto it = player.begin(); it != player.end(); ++it) {
		if ((*it)->elapsedTime().asSeconds() >= 10 && (*it)->getPosition().x < (*it)->initialX) {
			(*it)->voltando = true;
			(*it)->moveX(6);
		}
		if ((*it)->voltando && (*it)->getPosition().x >= (*it)->initialX) {
			(*it)->setPosition(sf::Vector2f(860, (*it)->getPosition().y));
			(*it)->voltando = false;
		}
	}
}

// Itera pelo vetor player e imprime todos os sprites na tela.
void Corrida::desenhaPlayers(sf::RenderWindow & window) {
	for (auto boneco = player.begin(); boneco != player.end(); ++boneco) {
		(*boneco)->updatePosition();
		if (!(*boneco)->morreu)
			window.draw((*boneco)->sprite);
	}
}

// Itera pelo vetor e remove do mesmo os jogadores com a flag morreu setada para true
void Corrida::mataMatado() {
	auto it = player.begin();

	while(it != player.end()) {
		if ((*it)->morreu) {
			alive[(*it)->num] = false;
			it = player.erase(it);
		}
		else
			++it;
	}

}


