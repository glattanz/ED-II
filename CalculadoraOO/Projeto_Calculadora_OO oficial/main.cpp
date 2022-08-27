#include <iostream>
#include <locale> //habilitar padr�es de caracter de teclado PTb
#include "Calculadora_OO.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(){
	cout << "===================MENU==================" << endl;
	cout << "Escolha op��o:\n";
	cout << "1- Soma" << endl;
	cout << "2- Subtra��o" << endl;
	cout << "3- Multiplica��o" << endl;
	cout << "4- Divis�o" << endl;
	cout << "5- Raiz quadrada" << endl;
	cout << "6- Pot�ncia" << endl;
	cout << "7- Inserir n�meros" << endl;
	cout << "8- Limpar n�meros" << endl;
	cout << "Outra para sair.\n";
	cout << "Op��o: ";
	
}

float ler_numero(int i){
	
	cout << "Informe N" << i <<": ";
	float tmp;
	cin >> tmp;
	return tmp;
}

void mostra_resultado(float res){
	cout << "===========================================" << endl;
	cout << "Resultado: " << res << endl;
	cout << "===========================================" << endl;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	//teste 2 - teste de menu com usu�rio	
	//criar condi��es de calcular opera��es aritm�ticas entre n1 e n2...
	Calculadora_OO teste; //cria objeto teste usando o construtor polim�rfico sem par�metros
	
	int op(1);
	float n1, n2;
	do{
		//1- apresentar menu de op��es p escolha de opera��es: 1-soma,2-subtra��o,3-multiplica��o,4-divis�o
		menu();
		cin >> op;
		
		cout << "===========================================" << endl;
		
		//2- ler op��o e chamar a fun��o desejada na bib calculadora - passar n1 e n2... back-end
		switch(op){
			case 1: //soma
				if(teste.n1==0){
					n1 = ler_numero(1);
					n2 = ler_numero(2);
				}
				mostra_resultado(teste.soma(n1, n2));
				break;
			case 2: //subtra��o
				if(teste.n1==0){
					n1 = ler_numero(1);
					n2 = ler_numero(2);
				}
				mostra_resultado(teste.subtracao(n1, n2));
				break;
			case 3: //multiplica��o
				if(teste.n1==0){
					n1 = ler_numero(1);
					n2 = ler_numero(2);
				}
				mostra_resultado(teste.multiplicacao(n1, n2));
				break;
			case 4: //divis�o
				if(teste.n1==0){
					n1 = ler_numero(1);
					n2 = ler_numero(2);
				}
				mostra_resultado(teste.divisao(n1, n2));
				break;
			case 5: //raiz quadrada
				if(teste.n1==0){
					n1 = ler_numero(1);
				}
				mostra_resultado(teste.raizQuadrada(n1));
				break;
			case 6: //potencia
				if(teste.n1==0){
					n1 = ler_numero(1);
					n2 = ler_numero(2);
				}
				mostra_resultado(teste.potencia(n1, n2));
				break;
			case 7:
				n1 = ler_numero(1);
				n2 = ler_numero(2);
				break;
			case 8:
				teste.~Calculadora_OO();
				break;
			default: cout << "Op��o inv�lida e fim de programa!\n";	//3- apresentar resultado / melhoria no front-end	
		}
	}while(op>=1 && op<=8);
	
	
	cout << "Fim de programa!\n";
	system("pause");
	return 0;
}
