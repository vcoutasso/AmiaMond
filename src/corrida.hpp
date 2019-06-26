#ifndef _CORRIDA_HPP
#define _CORRIDA_HPP

#include <vector>

#include "obstaculos.hpp"
#include "player.hpp"

class Corrida {
	private:
		int numPlayers;

	public:
		std::vector<ObstaculoEstatico*> obstaculosEstaticos;
		std::vector<ObstaculoGiratorio*> obstaculosGiratorios;
		std::vector<ObstaculoVazado*> obstaculosVazados;

		std::vector<Player*> player;

		Corrida(int n);

		void criaObstaculo();
		void initPlayer(int n, sf::Vector2f pos, sf::Vector2f scale, std::string pathToTexture, float speed);

		int getNumPlayers();
		void setNumPlayers(int n);

};


#endif
