/*
 * Lista.cpp
 *
 *  Created on: 21/11/2022
 *      Author: Pedro
 */



#include "lista.h"

Lista::Lista(){}
Lista::~Lista(){}

void Lista::SortList(int n)
{
	int at1,at2;
	vector<Atividade>::iterator ativ1,ativ2;
	Atividade Aux(0);

	for(ativ1=ListA.begin();ativ1!=ListA.end();ativ1++)
	{
		for(ativ2=(ativ1+1);ativ2!=ListA.end();ativ2++)
		{
			if(SortCritCheck((*ativ1),(*ativ2),n))
			{
				at1=ativ1-ListA.begin();
				at2=ativ2-ListA.begin();

				Aux=ListA[at1];
				ListA[at1]=ListA[at2];
				ListA[at2]=Aux;
			}
		}
	}
}

bool Lista::SortCritCheck(Atividade ativ1,Atividade ativ2,int n)
{
	if(n==1)
		return (ativ1.getCritSis()<ativ2.getCritSis())||
				(ativ1.getCritSis()==ativ2.getCritSis()&&
				(ativ1.getTit()).compare(ativ2.getTit())>0);
	else if(n==2)
		return (ativ1.getCritNar()<ativ2.getCritNar())||
				(ativ1.getCritNar()==ativ2.getCritNar()&&
				(ativ1.getTit()).compare(ativ2.getTit())>0);
	else
		return (ativ1.getCritChal()<ativ2.getCritChal())||
				(ativ1.getCritChal()==ativ2.getCritChal()&&
				(ativ1.getTit()).compare(ativ2.getTit())>0);
}


void Lista::ShowList()
{
	for(it=ListA.begin();it!=ListA.end();++it)

		(*it).ShowAtiv();
}

void Lista::AddAtiv()
{
	int aux=0;
	Atividade Add;

	for(it=ListA.begin();it!=ListA.end();++it)
	{
		if(Add.getTit()==(*it).getTit())
		{
			aux=1;
			cout << "\nErro. Atividade já existente.\n";
			break;
		}
	}
	if(aux!=1)
		ListA.push_back(Add);
}

void Lista::CombineAtiv()
{
	string ativ1;
	string ativ2;
	vector<Atividade>::iterator at1,at2;
	int check;

	cout << "Insira a primeira atividade a combinar: ";
	getline(cin,ativ1);
	cout << "Insira a segunda atividade a combinar: ";
	getline(cin,ativ2);

	if(!ativ1.compare(ativ2))
	{
		cout << "Erro. Atividades iguais." << endl;
		return;
	}

	for(it=ListA.begin();it!=ListA.end();++it)
	{
		if(!(ativ1.compare((*it).getTit())))
		{
			at1=it;
			check++;
		}
		if(!(ativ2.compare((*it).getTit())))
		{
			at2=it;
			check++;
		}
	}

	if(check==2)
	{
		Atividade Aux(0);
		Aux=(*at1)+(*at2);
		ListA.push_back(Aux);
		cout << "Nova atividade " << Aux.getTit() << " cridada com sucesso!" << endl;
	}
	else
		cout << "Erro. Pelo menos uma das atividades inseridas não existe ou está mal escrita." << endl;

}




