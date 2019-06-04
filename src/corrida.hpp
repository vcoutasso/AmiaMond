#ifndef _CORRIDA_HPP
#define _CORRIDA_HPP

#include "menu.hpp"

class Corrida {
	private:
		Nave *players;
		std::stack<Obstaculos> obstaculos;
	public:
		Corrida(int n);
		Corrida();

		void Main();



};


#endif
