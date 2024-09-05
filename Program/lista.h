/*
 * lista.h
 *
 *  Created on: 21/11/2022
 *      Author: Pedro
 */

#ifndef LISTA_H_
#define LISTA_H_

#include "atividades.h"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Lista
{
private:
	vector<Atividade> ListA;
	vector<Atividade>::iterator it;

	bool SortCritCheck(Atividade,Atividade,int);
public:

	Lista();
	~Lista();

	void AddAtiv();
	void CombineAtiv();
	void SortList(int);
	void ShowList();

	bool EmptyCheck(){return ListA.empty();};
};

#endif /* LISTA_H_ */
