#ifndef _CORRIDA_HPP
#define _CORRIDA_HPP

#include <vector>
#include "obstaculos.hpp"
#include "nave.hpp"

class Corrida {
	private:
		//Nave *players;

	public:
		std::vector<ObstaculoEstatico> obstaculosEstaticos;
		std::vector<ObstaculoGiratorio> obstaculosGiratorios;
		std::vector<ObstaculoVazado> obstaculosVazados;

		Corrida(int n);
		Corrida();
		void criaObstaculo();

		void Main();



};


#endif
