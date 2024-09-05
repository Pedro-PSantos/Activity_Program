/*
 * actividade.h
 *
 *  Created on: 21/11/2022
 *      Author: Pedro
 */

#ifndef ATIVIDADES_H_
#define ATIVIDADES_H_

#include <iostream>

using namespace std;



class Atividade
{
private:
	string titulo;
	string descricao;
	string url;
	float sistema{},narrativa{},challenge{};

	int checkCrits(float);
	int checkURL();
	void convertCrits();
public:

	Atividade();
	Atividade(int);
	~Atividade();

	string getTit(){return titulo;};
	string getDesc(){return descricao;};
	string getUrl(){return url;};
	float getCritSis(){return sistema;};
	float getCritNar(){return narrativa;};
	float getCritChal(){return challenge;};

	void setTit(string str){titulo=str;};
	void setDesc(string str){descricao=str;};
	void setUrl(string str){url=str;};
	void setSis(float n){sistema=n;};
	void setNar(float n){narrativa=n;};
	void setChal(float n){challenge=n;};

	void ShowAtiv();



	Atividade operator+(const Atividade&);


};








#endif /* ATIVIDADES_H_ */
