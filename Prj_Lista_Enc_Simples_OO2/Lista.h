//Prototipar a classe
//Lista.h
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include "no_dado.h"

using namespace std;

class Lista{
	//Declarar atributos
	private:
		//Objeto tipo ponteiro da classe no_dado
		no_dado* cabeca;
		int qtd;
	
	//Declarando métodos	
	public:
		//Construtores
		Lista();
		~Lista();
		
		//Outros métodos
		void insere_inicio(int i); 
		void imprime(); 
		void vazia();
		void libera();
		void tamanho(); 
		void insere_fim(int i); 
		void busca(int i); 
		void retira(int i); 
		void retira_inicio(); 
		void retira_fim(); 
		void imprime_inicio(); 
		void imprime_fim(); 
		
	private:
		bool isEmpty(no_dado* l);	
};
