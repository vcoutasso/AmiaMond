#ifndef _CORRIDA_HPP
#define _CORRIDA_HPP

#include <vector>
#include "obstaculos.hpp"
#include "player.hpp"


class Corrida {
	private:
		std::vector<Obstaculos> obstaculos;

	public:
		Player *player;

		Corrida(int n);
		Corrida();



		void Main();



};


#endif
