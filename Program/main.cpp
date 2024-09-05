/*
 * main.cpp
 *
 *  Created on: 21/11/2022
 *      Author: Pedro
 */





#include "lista.h"
#include "atividades.h"


using namespace std;

void Bem_Vindo()
{
	cout << "Bem-Vindo ao explorador de Atividades Imersivas!" << endl
		 << "Para interagir com o programa selecione o número apresentado em cada opção para selecioná-la!" << endl;
}


void Menu()
{
	cout << "\nAdicionar Nova Atividade - 1" << endl
		 << "Mostrar Lista - 2" << endl
		 << "Sair - 3" << endl
		 << "Insira opção: ";
}

int Input()
{
	string buffer;
	getline(cin,buffer);

	if(buffer.size()>1)
		return 0;
	else
		return int(buffer[0])-48;
}


int main()
{

	Lista L;
	int input;

	Bem_Vindo();

	for(int i=0;i==0;)
	{
		Menu();
		switch(Input())
		{
		case 1:
			cout << "\nAdicionar nova atividade." << endl
				 << "Criar nova atividade - 1" << endl
				 << "Combinar atividades - 2" << endl
				 << "Opção: ";

			input=Input();

			if(input==1)
				L.AddAtiv();
			else if(input==2)
				L.CombineAtiv();
			else
				cout << "Opção Inválida." << endl;
			break;

		case 2:
			cout << "\nMostrar lista." << endl;

			if(L.EmptyCheck())
			{
				cout << "\nErro. Lista Vazia\n" << endl;
				break;
			}

			cout << "Ordenard por:" << endl
				 << "Grau de imersão pelo sistema - 1" << endl
				 << "Grau de imersão pela narrativa - 2" << endl
				 << "Grau de imersão pela agência - 3" << endl
				 << "Opção: ";

			input=Input();

			if(input>=1 && input<=3)
			{
				cout << "A ordenar pela opção " << input << "\n" << endl;
				L.SortList(input);
				L.ShowList();
			}
			else
				cout << "Opção Inválida." << endl;
		break;

		case 3:
			cout << "\nSair." << endl
				 << "A terminar programa..." << endl;

			return 0;

		default:
			cout << "\nOpção Inválida. Escolha novamente, inserindo a opção desejada." << endl;
		}
	}

	return 0;
}
