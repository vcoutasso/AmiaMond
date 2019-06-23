#ifndef _CORRIDA_HPP
#define _CORRIDA_HPP

#include <vector>

#include "obstaculos.hpp"
#include "player.hpp"

class Corrida {
	public:
		std::vector<ObstaculoEstatico*> obstaculosEstaticos;
		std::vector<ObstaculoGiratorio*> obstaculosGiratorios;
		std::vector<ObstaculoVazado*> obstaculosVazados;

		Player *player;

		Corrida(int n);

		void criaObstaculo();


};


#endif
