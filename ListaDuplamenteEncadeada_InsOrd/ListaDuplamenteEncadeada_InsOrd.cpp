//Desenvolver métodos de classe
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
	this->libera(); //ideia é liberar free toda memória alocada
	this->qtd = 0;
}

void Lista::insere_ord(int i){
	
 	//criando o novo objeto da classe no_dado
 	no_dado* novo = new no_dado(i, NULL, NULL);
 	no_dado* p;
 	
 	if (!this->isEmpty(this->cabeca)){ //Se não estiver vazia
		//1. Se o novo nó for menor do que o nó cabeça
		if(this->cabeca->info >= novo->info){ //Inserindo o novo no início da lista
			novo->prox = this->cabeca;
			novo->prox->ant = novo;
			this->cabeca = novo; //Atualiza a cabeça da lista
		}else{ //2. Se o novo nó for maior do que o cabeça
			p = this->cabeca;
			while(p->prox!=NULL && p->prox->info < novo->info){ 
			//Percorre a lista até que o novo só seja menor do que o próximo nó
			//Com essa condicional, achamos o nó que será anterior ao novo
				p=p->prox;
			}
			
				novo->prox = p->prox;
				p->prox = novo;
				novo->ant = p;
				
			if(p->prox != NULL){//Se o novo não for o ultimo nó atualizamos o ->ant nó de dado posterior ao novo
				novo->prox->ant = novo;
			}
			
		}
	}else{ //Se estiver vazia 
		this->cabeca = novo;
	}  	
	  
	//incrementa o contador de nó-dado 
  	this->qtd++; 
  	
  	printf("Elemento adicionado!\n");
}

void Lista::imprime(){
	if (!this->isEmpty(this->cabeca)){ //Se não estiver vazia
		no_dado* p; //variável auxiliar para percorrer a lista
		printf("Info = ");
		for (p = this->cabeca; p != NULL; p = p->prox)
			printf("%d - ", p->info);
		printf("\n");
	} else printf("Lista está vazia!\n");
}

void Lista::vazia(){
	if (!this->isEmpty(this->cabeca))
		printf("Lista não está vazia!\n");
	else
		printf("Lista está vazia!\n");
}

void Lista::libera(){
	no_dado* p = this->cabeca;
	no_dado* t = p->prox;
	 while (p != NULL) {
	 	t = p->prox; // guarda referência para o próximo elemento
		free(p); /* libera a memória apontada por p */
		this->qtd--; //decrementa contador de qtd
	 	p = t; /* faz p apontar para o próximo */
	 }
	 this->cabeca = 0; //inicializa lista vazia
	 
	 printf("Lista liberada!\n");
}

void Lista::tamanho(){
	printf("Quantidade de elementos: %d\n", this->qtd);
}

//tratamento métodos privados
bool Lista::isEmpty(no_dado* l){
	return l==NULL;
}

void Lista::busca(int i){
	if (!this->isEmpty(this->cabeca)){ //Se não estiver vazia
		no_dado* p; //variável auxiliar para percorrer a lista
		bool achou = false;
		for (p = this->cabeca; p != NULL; p = p->prox){
			if(p->info == i){
				achou = true;
			}
		}
		
		if(achou == true){
				printf("Elemento encontrado!\n");
			}else{
				printf("Elemento não encontrado...\n");
			}
			
	} else printf("Lista está vazia!\n");
}

void Lista::insere_fim(int i){
	
	if(this->isEmpty(this->cabeca)){
		no_dado* novo = new no_dado(i, this->cabeca, NULL); //criando o novo objeto da classe no_dado
		this->cabeca = novo; //aponta o incio da lista para o novo nó
		this->qtd++;
		printf("Elemento adicionado!\n");
	}else{
		no_dado* novo = new no_dado(i, this->cabeca, NULL); //criando o novo objeto da classe no_dado
 		no_dado* p; //variável auxiliar para percorrer a lista
		
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
	
	//Acha o último nó de dado	
	while(p->prox!=NULL){
		ant=p;
		p=p->prox;
	}
	
	//Se só tiver 1 nó de dado
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
		
		printf("Primeiro nó dado: %d\n", p->info);
	}
	else{
		printf("Lista vazia.\n");
	}
}

void Lista::imprime_fim(){
	
	if(!this->isEmpty(this->cabeca)){
		no_dado* p=this->cabeca;
		
		for(p=this->cabeca;p->prox!=NULL;p=p->prox);
		
		printf("Último nó dado: %d\n", p->info);
	}
	else{
		printf("Lista vazia.\n");
	}
}

void Lista::retira(int i){
	
	no_dado* ant = NULL;
	no_dado* p = this->cabeca;
		
	if(!this->isEmpty(this->cabeca)){	
	
		//Andar enquanto não chegar ao fim da fila ou achar o elemento
		while (p != NULL && p->info != i){
			ant = p;
			p = p->prox;
		}
		
		//Se não encontrar o elemento
		if (p == NULL){
		
		cout << "Elemento não encontrado.\n" << endl;
		}
	
		//Encontrou o elemento
		//Se estiver no primeiro nó dado
		if (ant == NULL){
			this->cabeca = p->prox;
			this->qtd--;
			printf("Elemento removido.\n");
		}
		//Se não estiver no primeiro nó
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


