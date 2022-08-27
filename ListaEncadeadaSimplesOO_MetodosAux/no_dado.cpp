//no_dado.cpp
//Monta a estrutura de um nó de dado

#include "no_dado.h"

//construtor
no_dado::no_dado(){
	this->prox = 0; 
}

no_dado::no_dado(int i, no_dado* l){
	this->info = i;
	this->prox = l;
}
