#include "ListaDuplamenteEncadeada_InsOrd.h"
//Traz todas as bibliotecas importadas no Lista.h

using namespace std;

void menu(){
	cout << "===================MENU==================" << endl;
	cout << "Escolha opção:\n";
	cout << "1- Insere ordenado" << endl;
	cout << "2- Insere fim" << endl;
	cout << "3- Retira" << endl;
	cout << "4- Retira início" << endl;
	cout << "5- Retira fim" << endl;
	cout << "6- Imprime" << endl;
	cout << "7- Imprime início" << endl;
	cout << "8- Imprime fim" << endl;
	cout << "9- Busca" << endl;
	cout << "10- Tamanho" << endl;
	cout << "11- Libera" << endl;
	cout << "12- Vazia?" << endl;
	cout << "Outra para sair.\n";
	cout << "Opção: ";
	
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	//Instanciando objeto l conforme a classe Lista
	Lista l;
	int op, i;
	
	cout << "PROGRAMA LISTA DUPLAMENTE ENCADEADA COM INSERÇÃO ORDENADA\n";
	
		do{
		menu();
		cin >> op;
		
		cout << "===========================================" << endl;
		
		switch(op){
			case 1:
				cout << "Digite o número que deseja inserir: " << endl;
				cin >> i;
				l.insere_ord(i);
				break;
				
			case 2:
				cout << "Digite o número que deseja inserir: " << endl;
				cin >> i;
				l.insere_fim(i);
				break;
				
			case 3:
				cout << "Digite o número que deseja retirar: " << endl;
				cin >> i;
				l.retira(i);
				break;
				
			case 4:
				l.retira_inicio();
				break;
			
			case 5:
				l.retira_fim();
				break;
			
			case 6:
				l.imprime();
				break;
				
			case 7:
				l.imprime_inicio();
				break;
			
			case 8:
				l.imprime_fim();
				break;
				
			case 9:
				cout << "Digite o número que deseja buscar: " << endl;
				cin >> i;
				l.busca(i);
				break;
			
			case 10:
				l.tamanho();
				break;
			
			case 11:
				l.libera();
				break;
				
			case 12:
				l.vazia();
				break;
			
			default: cout << "Opção inválida e fim de programa!\n";
		}
	}while(op>=1 && op<=12);
	
	cout << "Fim de programa!\n";
	system("pause");
	
	return 0;
}
