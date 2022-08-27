//no_dado.cpp
//Monta a estrutura de um nó de dado

#include "no_dado.h"

//construtores
no_dado::no_dado(){
	this->prox = 0; 
	this->ant = 0;
}

no_dado::no_dado(int i, no_dado* p, no_dado* a){
	this->info = i;
	this->prox = p;
	this->ant = a;
}
