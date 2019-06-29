#include "corrida.hpp"
#include "collision.hpp"

#include <cstdlib> 
#include <iostream>

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


// Checa colisões com obstaculos do tipo estatico.
void Corrida::colisaoEstatico() {

	for (auto it = obstaculosEstaticos.begin(); it != obstaculosEstaticos.end(); ++it) {
		// Faz todas as checagens para cada player
		for (auto it_player = player.begin(); it_player != player.end(); ++it_player) {
			// Se colidiu, ajusta a posição do boneco
			if (Collision::BoundingBoxTest((*it_player)->sprite, (*it)->sprite)) {
				(*it_player)->resetSpeed();
				(*it_player)->ajustaPosicao((*it)->sprite, (*it)->isVertical(), (*it)->getSpeed());
				(*it_player)->restartTemporizador();
			}
		}
	}
}


// Checa colisões com obstaculos do tipo giratorio.
void Corrida::colisaoGiratorio() {

	for (auto it = obstaculosGiratorios.begin(); it != obstaculosGiratorios.end(); ++it) {
		// Faz todas as checagens para cada player
		for (auto it_player = player.begin(); it_player != player.end(); ++it_player) {
			// Se colidiu, ajusta a posição do boneco
			if (Collision::BoundingBoxTest((*it_player)->sprite, (*it)->sprite)) {
				(*it_player)->resetSpeed();
				(*it_player)->ajustaPosicao((*it)->sprite, (*it)->isVertical(), (*it)->getSpeed());
				(*it_player)->restartTemporizador();
			}
		}
	}
}


// Checa colisões com obstaculos do tipo vazado.
void Corrida::colisaoVazado() {			

	for (auto it = obstaculosVazados.begin(); it != obstaculosVazados.end(); ++it) {
		// Faz todas as checagens para cada player
		for (auto it_player = player.begin(); it_player != player.end(); ++it_player)
			// Se colidiu, verifica se não está passando entre o(s) buraco(s)
			if (Collision::BoundingBoxTest((*it_player)->sprite, (*it)->sprite)) {

				if ((*it)->loadedFile == "bin/obstaculo_3.png") { // Se for o obstaculo com apenas um buraco
					if ((*it_player)->sprite.getPosition().y > (*it)->sprite.getGlobalBounds().top + (*it)->sprite.getGlobalBounds().height / 3 &&
							(*it_player)->sprite.getPosition().y < (*it)->sprite.getGlobalBounds().top + 2 * (*it)->sprite.getGlobalBounds().height / 3)
							continue; // Nao faz nada, passou no buraco

					(*it_player)->ajustaPosicao((*it)->sprite, (*it)->isVertical(), (*it)->getSpeed()); // Caso contrario, ajusta a posição do boneco
				}
				else if ((*it)->loadedFile == "bin/obstaculo_4.png") {
					if ((*it_player)->sprite.getPosition().y > (*it)->sprite.getGlobalBounds().top + (*it)->sprite.getGlobalBounds().height / 5 &&
						(*it_player)->sprite.getPosition().y < (*it)->sprite.getGlobalBounds().top + 2 * (*it)->sprite.getGlobalBounds().height / 5 ||
						((*it_player)->sprite.getPosition().y > (*it)->sprite.getGlobalBounds().top + 3 * (*it)->sprite.getGlobalBounds().height / 5 &&
						(*it_player)->sprite.getPosition().y < (*it)->sprite.getGlobalBounds().top + 4 * (*it)->sprite.getGlobalBounds().height / 5))
						continue; // Nao faz nada, passou no buraco

					(*it_player)->ajustaPosicao((*it)->sprite, (*it)->isVertical(), (*it)->getSpeed()); // Caso contrario, ajusta a posição do boneco
				}
			}
	}
}

// Método responsável por tratar os eventos de event
void Corrida::handleEvents(sf::Event& event, int& quit, bool& mostraFPS) {

	switch (event.type) {

		// Ao pressionar a tecla, o respectivo jogador começará a subir
	case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::A) //Player 1
			player[0]->rise = true;
		if (event.key.code == sf::Keyboard::F) //Player 2
			player[1]->rise = true;
		if (event.key.code == sf::Keyboard::J && getNumPlayers() >= 3) //Player 3
			player[2]->rise = true;
		if (event.key.code == sf::Keyboard::L && getNumPlayers() == 4) //Player 4
			player[3]->rise = true;

		break;

		// Ao soltar, volta a cair
	case sf::Event::KeyReleased:
		if (event.key.code == sf::Keyboard::Escape) // Volta para o menu
			quit = 1;
		if (event.key.code == sf::Keyboard::F1) // Botão de toggle para o contador de FPS
			mostraFPS = !mostraFPS;

		if (event.key.code == sf::Keyboard::A)
			player[0]->rise = false;
		if (event.key.code == sf::Keyboard::F)
			player[1]->rise = false;
		if (event.key.code == sf::Keyboard::J && getNumPlayers() >= 3)
			player[2]->rise = false;
		if (event.key.code == sf::Keyboard::L && getNumPlayers() == 4)
			player[3]->rise = false;

		break;

	case sf::Event::Closed: // Sai do jogo
		quit = -1;
		break;

	default:
		break;

	}
}