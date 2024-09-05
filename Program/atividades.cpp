/*
 * atividade.cpp
 *
 *  Created on: 21/11/2022
 *      Author: Pedro
 */


#include "atividades.h"

Atividade::Atividade()
{
	string buffer;

	cout << "Título da Atividade: ";
	getline(cin,titulo);
	cout << "Descrição da Atividade: ";
	getline(cin,descricao);


	for(int i=0;i==0;i=checkURL())
	{
		cout << "Url do Vídeo: ";
		getline(cin,url);
	}

	for(int i=0;i==0;i=checkCrits(sistema))
	{
		cout << "Critério de Sistema(0 a 100%): ";
		getline(cin,buffer);
		sistema=stoi(buffer);
	}

	for(int i=0;i==0;i=checkCrits(narrativa))
	{
		cout << "Critério de Narrativa(0 a 100%): ";
		getline(cin,buffer);
		narrativa=stoi(buffer);
	}

	for(int i=0;i==0;i=checkCrits(challenge))
	{
		cout << "Critério de Agência(0 a 100%): ";
		getline(cin,buffer);
		challenge=stoi(buffer);
	}

	convertCrits();

}

Atividade::Atividade(int i){}

Atividade::~Atividade(){}

void Atividade::ShowAtiv()
{
	cout << "Título: " << getTit() << endl
		 << "Descrição: " << getDesc() << endl
		 << "Url: " << getUrl() << endl
		 << "[" << getCritSis() << "; " << getCritNar() << "; " << getCritChal() << "]" << endl;
}

Atividade Atividade::operator+(const Atividade& At)
{
	Atividade Aux(0);

	Aux.setSis(sistema >= At.sistema ? sistema : At.sistema);
	Aux.setNar(narrativa >= At.narrativa ? narrativa : At.narrativa);
	Aux.setChal(challenge >= At.challenge ? challenge : At.challenge);
	Aux.setTit(titulo+" com "+At.titulo);
	Aux.setDesc(descricao+" e "+At.descricao);
	Aux.setUrl(url+" e "+At.url);

	return Aux;
}

int Atividade::checkURL()
{
	string s1="http://",s2="https://";
	int i;

	if((i=url.compare(0,7,s1)))
		if((i=url.compare(0,8,s2)))
			cout << "Url inválido. Deve começar com \"http://\" ou \"https://\".\nInsira novamente..." << endl;

	return !i;
}

int Atividade::checkCrits(float n)
{
	int i=(n < 0 || n > 100);

	if(i!=0)
		cout << "Valor Inválido. Inserir valor entre 1 e 100." << endl;

	return !i;
}

void Atividade::convertCrits()
{
	sistema=float(int(sistema))/100;
	narrativa=float(int(narrativa))/100;
	challenge=float(int(challenge))/100;
}
