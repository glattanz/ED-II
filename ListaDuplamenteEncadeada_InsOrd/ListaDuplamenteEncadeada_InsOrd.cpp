//Desenvolver m�todos de classe
//Lista.cpp

#include "ListaDuplamenteEncadeada_InsOrd.h"

//construtor
Lista::Lista(){
	this->cabeca = 0; //inicializa lista vazia
	this->cauda = 0;
	this->qtd = 0;
}

//destrutor
Lista::~Lista(){
	this->libera(); //ideia � liberar free toda mem�ria alocada
	this->qtd = 0;
}

void Lista::insere_ord(int i){
	
 	//criando o novo objeto da classe no_dado
 	no_dado* novo = new no_dado(i, NULL, NULL);
 	no_dado* p;
 	
 	if (!this->isEmpty(this->cabeca)){ //Se n�o estiver vazia
		//1. Se o novo n� for menor do que o n� cabe�a
		if(this->cabeca->info >= novo->info){ //Inserindo o novo no in�cio da lista
			novo->prox = this->cabeca;
			novo->prox->ant = novo;
			this->cabeca = novo; //Atualiza a cabe�a da lista
		}else{ //2. Se o novo n� for maior do que o cabe�a
			p = this->cabeca;
			while(p->prox!=NULL && p->prox->info < novo->info){ 
			//Percorre a lista at� que o novo s� seja menor do que o pr�ximo n�
			//Com essa condicional, achamos o n� que ser� anterior ao novo
				p=p->prox;
			}
			
				novo->prox = p->prox;
				p->prox = novo;
				novo->ant = p;
				
			if(p->prox != NULL){//Se o novo n�o for o ultimo n� atualizamos o ->ant n� de dado posterior ao novo
				novo->prox->ant = novo;
			}
			
		}
	}else{ //Se estiver vazia 
		this->cabeca = novo;
	}  	
	  
	//incrementa o contador de n�-dado 
  	this->qtd++; 
  	
  	printf("Elemento adicionado!\n");
}

void Lista::imprime(){
	if (!this->isEmpty(this->cabeca)){ //Se n�o estiver vazia
		no_dado* p; //vari�vel auxiliar para percorrer a lista
		printf("Info = ");
		for (p = this->cabeca; p != NULL; p = p->prox)
			printf("%d - ", p->info);
		printf("\n");
	} else printf("Lista est� vazia!\n");
}

void Lista::vazia(){
	if (!this->isEmpty(this->cabeca))
		printf("Lista n�o est� vazia!\n");
	else
		printf("Lista est� vazia!\n");
}

void Lista::libera(){
	no_dado* p = this->cabeca;
	no_dado* t = p->prox;
	 while (p != NULL) {
	 	t = p->prox; // guarda refer�ncia para o pr�ximo elemento
		free(p); /* libera a mem�ria apontada por p */
		this->qtd--; //decrementa contador de qtd
	 	p = t; /* faz p apontar para o pr�ximo */
	 }
	 this->cabeca = 0; //inicializa lista vazia
	 
	 printf("Lista liberada!\n");
}

void Lista::tamanho(){
	printf("Quantidade de elementos: %d\n", this->qtd);
}

//tratamento m�todos privados
bool Lista::isEmpty(no_dado* l){
	return l==NULL;
}

void Lista::busca(int i){
	if (!this->isEmpty(this->cabeca)){ //Se n�o estiver vazia
		no_dado* p; //vari�vel auxiliar para percorrer a lista
		bool achou = false;
		for (p = this->cabeca; p != NULL; p = p->prox){
			if(p->info == i){
				achou = true;
			}
		}
		
		if(achou == true){
				printf("Elemento encontrado!\n");
			}else{
				printf("Elemento n�o encontrado...\n");
			}
			
	} else printf("Lista est� vazia!\n");
}

void Lista::insere_fim(int i){
	
	if(this->isEmpty(this->cabeca)){
		no_dado* novo = new no_dado(i, this->cabeca, NULL); //criando o novo objeto da classe no_dado
		this->cabeca = novo; //aponta o incio da lista para o novo n�
		this->qtd++;
		printf("Elemento adicionado!\n");
	}else{
		no_dado* novo = new no_dado(i, this->cabeca, NULL); //criando o novo objeto da classe no_dado
 		no_dado* p; //vari�vel auxiliar para percorrer a lista
		
		for (p = this->cabeca; p->prox != NULL; p = p->prox);
		
		p->prox = novo;	
		novo->prox=NULL;	
		this->qtd++;
		printf("Elemento adicionado!\n");
	}
}

void Lista::retira_inicio(){
	
	if(!this->isEmpty(this->cabeca)){	
		no_dado* p=this->cabeca;
		this->cabeca=p->prox;
		this->qtd--;
		
		printf("Elemento retirado!\n");
		
		free(p);
	}
	else{
		printf("Lista vazia.\n");
	}	
}

void Lista::retira_fim(){
	
	if(!this->isEmpty(this->cabeca)){	
		no_dado* p=this->cabeca;
		no_dado* ant=NULL;
	
	//Acha o �ltimo n� de dado	
	while(p->prox!=NULL){
		ant=p;
		p=p->prox;
	}
	
	//Se s� tiver 1 n� de dado
	if(ant==NULL){
		this->cabeca=p->prox;
	}
	else{
		ant->prox=p->prox;
	}
	
	this->qtd--;
	printf("Elemento retirado!\n");
	free(p);	
	}
	else{
		printf("Lista vazia.\n");
	}	
	
}	

void Lista::imprime_inicio(){
	
	if(!this->isEmpty(this->cabeca)){
		no_dado* p=this->cabeca;
		
		printf("Primeiro n� dado: %d\n", p->info);
	}
	else{
		printf("Lista vazia.\n");
	}
}

void Lista::imprime_fim(){
	
	if(!this->isEmpty(this->cabeca)){
		no_dado* p=this->cabeca;
		
		for(p=this->cabeca;p->prox!=NULL;p=p->prox);
		
		printf("�ltimo n� dado: %d\n", p->info);
	}
	else{
		printf("Lista vazia.\n");
	}
}

void Lista::retira(int i){
	
	no_dado* ant = NULL;
	no_dado* p = this->cabeca;
		
	if(!this->isEmpty(this->cabeca)){	
	
		//Andar enquanto n�o chegar ao fim da fila ou achar o elemento
		while (p != NULL && p->info != i){
			ant = p;
			p = p->prox;
		}
		
		//Se n�o encontrar o elemento
		if (p == NULL){
		
		cout << "Elemento n�o encontrado.\n" << endl;
		}
	
		//Encontrou o elemento
		//Se estiver no primeiro n� dado
		if (ant == NULL){
			this->cabeca = p->prox;
			this->qtd--;
			printf("Elemento removido.\n");
		}
		//Se n�o estiver no primeiro n�
		else{ 
			ant->prox = p->prox;
			this->qtd--;
			printf("Elemento removido.\n");
		}
		
	}else{
		
		printf("Lista vazia.\n");
	}
	
	free(p);
	
}


