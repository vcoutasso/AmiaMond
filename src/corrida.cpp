#include "corrida.hpp"
#include <cstdlib> 

Corrida::Corrida(int n) {
	//players = new Nave[n]; 
}

Corrida::Corrida() {

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
