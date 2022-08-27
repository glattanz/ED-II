//no_dado.h

class no_dado{
	
	//Atributos
	public:
		int info;
		no_dado* prox; 
		no_dado* ant;
		
	//Métodos
	public:
		//Construtores
		no_dado(); 
		
		no_dado(int i, no_dado* p, no_dado* a);
};
