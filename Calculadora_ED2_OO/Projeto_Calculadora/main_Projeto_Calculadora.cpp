//Prof. Irineu - ED
//Front-end

#include <iostream>
#include "Calculadora.h"
#include <locale> //habilitar padrões de caracter de teclado Ptb
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void menu(){
	cout << "Escolha opção:\n";
	cout << "1- Soma" << endl;
	cout << "2- Subtração" << endl;
	cout << "3- Multiplicação" << endl;
	cout << "4- Divisão" << endl;
	cout << "Qq outra para sair.\n";
	cout << "Opção: ";
}

float ler_numero(int i){
	cout << "Informe N" << i <<": ";
	float tmp;
	cin >> tmp;
	return tmp;
}

void mostra_resultado(float res){
	cout << "Resultado: " << res << endl;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	//criar condições de calcular operações aritméticas entre n1 e n2...
	int op(1);
	float n1, n2;
	do{
		//1- apresentar menu de opções p escolha de operações: 1-soma,2-subtração,3-multiplicação,4-divisão
		menu();
		cin >> op;
		
		//2- ler opção e chamar a função desejada na bib calculadora - passar n1 e n2... back-end
		float tmp;
		switch(op){
			case 1: //soma
				n1 = ler_numero(1);
				n2 = ler_numero(2);
				tmp = soma(n1, n2);
				mostra_resultado(tmp);
				break;
			case 2: //subtracao
				n1 = ler_numero(1);
				n2 = ler_numero(2);
				mostra_resultado(subtracao(n1, n2));
				break;
			case 3: //multiplicaçao
				n1 = ler_numero(1);
				n2 = ler_numero(2);
				mostra_resultado(multiplicacao(n1, n2));
				break;
			case 4: //divisao
				n1 = ler_numero(1);
				n2 = ler_numero(2);
				mostra_resultado(divisao(n1, n2));
				break;	
			default: cout << "Opção inválida e fim de programa!\n";				
		}
	
	}while(op>=1 && op<=4);
	
	cout << "Fim de programa!\n";
	system("pause");
	return 0;
}
