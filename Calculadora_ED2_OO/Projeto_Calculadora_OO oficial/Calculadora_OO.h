//Calculadora_OO.h
//Objetiva prototipar a classe

class Calculadora_OO{
	//declarar atributos
	public:
		float n1; //atributo numero 1
	 	float n2; //atributo numero 1
	
	//declarar cabe�alhos de metodos
	public:
		Calculadora_OO(); //Construtor - polimorfismo
		Calculadora_OO(float nn1, float nn2); //Construtor - polimorfismo
		
		~Calculadora_OO(); //Destrutor - executado ao fim ou t�rmino de uso de objeto de classe, tamb�m sem retorno por padr�o.
		
		float soma();
		float soma(float nn1, float nn2);
		
		float subtracao();
		float subtracao(float nn1, float nn2);
		
		float multiplicacao();
		float multiplicacao(float nn1, float nn2);
		
		float divisao();
		float divisao(float nn1, float nn2);
	
		float raizQuadrada();
		float raizQuadrada(float nn1);
		
		float potencia();
		float potencia(float nn1, float nn2);
}; //toda classe se encerra com ; (padr�o da ling. C++)
