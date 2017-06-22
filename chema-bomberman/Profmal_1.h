#pragma once 
#include"ProfesorMaligno.h"
#include"Figura.h"
class Profmal_1:public ProfesorMaligno
{
private:
	ProfesorMaligno* obj_profesormaligno;
public:
	Profmal_1(void);
	~Profmal_1(void);

	void enemigo1(Graphics^gr);

};

Profmal_1::Profmal_1(void){
	obj_profesormaligno = new ProfesorMaligno();
}
Profmal_1::~Profmal_1(void){}

void Profmal_1::enemigo1(Graphics^gr){
	obj_profesormaligno->SET_imagen("Resources\\img\\sprites\\personaje\\enemigo3.png");
	obj_profesormaligno->mostrar_enemigo(gr);
}