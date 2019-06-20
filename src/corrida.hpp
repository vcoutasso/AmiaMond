#ifndef _CORRIDA_HPP
#define _CORRIDA_HPP

#include <vector>
#include "obstaculos.hpp"
#include "nave.hpp"

class Corrida {
	private:
		//Nave *players;
		std::vector<Obstaculos> obstaculos;

	public:
		Corrida(int n);
		Corrida();

		template <typename T>
		T criaObstaculo();



		void Main();



};


#endif
