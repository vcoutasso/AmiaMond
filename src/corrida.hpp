#ifndef _CORRIDA_HPP
#define _CORRIDA_HPP

#include <vector>

#include "obstaculos.hpp"
#include "player.hpp"

class Corrida {
	private:
		

	public:
		Corrida(int n); // Construtor

		bool alive[4];

		int numPlayers; // Quantidade atual de jogadores

		std::vector<ObstaculoEstatico*> obstaculosEstaticos; // Vetor contendo todos os obstaculos estaticos
		std::vector<ObstaculoGiratorio*> obstaculosGiratorios; // Vetor contendo todos os obstaculos giratorios
		std::vector<ObstaculoVazado*> obstaculosVazados; // Vetor contendo todos os obstaculos vazados

		std::vector<Player*> player; // Vetor contendo todos os jogadores

		void criaObstaculo(int velObstaculo); // Cria obstaculo aleatoriamente. É chamado em um intervalo de tempo fixo.
		void initPlayer(sf::Vector2f pos, sf::Vector2f scale, std::string pathToTexture, float speed); // Inicializa o vetor player de acordo com numPlayers

		void removeObstaculos(); // Remove obstaculos que estão fora da tela
		void desenhaObstaculos(sf::RenderWindow& window); // Desenha todos os obstaculos na tela

		int getNumPlayers(); // Retorna o numero atual de jogadores
		void setNumPlayers(int n); // Seta o numero atual de jogadores

		void retornaPlayers(); // Faz com que os bonecos se direcionem ao centro da tela se estiverem tempo suficiente sem colidir

		void desenhaPlayers(sf::RenderWindow& window); // Desenha os bonecos na tela

		void mataMatado(); // Remove do vetor player os jogadores que já morreram

		// Verifica se os jogadores colidiram com algum obstaculo
		void colisaoEstatico();
		void colisaoGiratorio();
		void colisaoVazado();

	
		void handleEvents(sf::Event& event, int& quit, bool& mostraFPS); // Método para tratar os eventos 
};


#endif
