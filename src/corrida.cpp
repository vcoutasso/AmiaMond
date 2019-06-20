#include "corrida.hpp"

Corrida::Corrida(int n) {
	//players = new Nave[n]; 
}

Corrida::Corrida() {

}

void Corrida::criaObstaculo() {
	ObstaculoEstatico ob;
	obstaculosEstaticos.push_back(ob);
}
