#pragma once

#include"Figura.h"

public enum tipo_enemigo{E1,E2,E3,E4,E5};

class ProfesorMaligno:public Figura
{
private:
	char* imagen;
	bool eliminar;
	tipo_enemigo tipo;
public:
	
	bool visible;

	ProfesorMaligno(int px, int py, tipo_enemigo ptipo);
	~ProfesorMaligno(void);
	
	void SET_eliminar(bool nuevo);
	bool GET_eliminar();

	void SET_imagen(char* New);
	void mostrar_enemigo(Graphics^gr);
	void mover_enemigo_vertical();
	void mover_enemigo_horizontal();
	
};

ProfesorMaligno::ProfesorMaligno(int px,int py,tipo_enemigo ptipo){
	x = px;
	y = py;
	tipo = ptipo;
	dx = 8;
	dy = 5;
	width = high = 40;
	imagen = new char[100];
	eliminar = false;
	visible = true;
}
ProfesorMaligno::~ProfesorMaligno(void){
	delete imagen;
}

//ene1
void ProfesorMaligno::SET_eliminar(bool nuevo){
	eliminar = nuevo;
}

bool ProfesorMaligno::GET_eliminar(){
	return eliminar;
}

void ProfesorMaligno::SET_imagen(char* New){
	strcpy(imagen, New);
	Bitmap^bm = gcnew Bitmap(gcnew String(New));
	widthI = bm->Width;
	highI = bm->Height;
	delete bm;
}
void ProfesorMaligno::mostrar_enemigo(Graphics^gr){

	if (tipo == tipo_enemigo::E1)SET_imagen("Resources\\img\\sprites\\personaje\\enemigo1.png");
	if (tipo == tipo_enemigo::E2)SET_imagen("Resources\\img\\sprites\\personaje\\enemigo2.png");
	if (tipo == tipo_enemigo::E3)SET_imagen("Resources\\img\\sprites\\personaje\\enemigo3.png");
	if (tipo == tipo_enemigo::E4)SET_imagen("Resources\\img\\sprites\\personaje\\enemigo4.png");

	Bitmap^bm = gcnew Bitmap(gcnew String(imagen));
	Rectangle origen = Rectangle(0,0,widthI,highI);
	Rectangle fin = Rectangle(x,y,40,40);
	gr->DrawImage(bm, fin, origen, GraphicsUnit::Pixel);
}

void ProfesorMaligno::mover_enemigo_horizontal(){
	if (x + dx < 44 || x + dx + 80 > 602){
		dy = 0;
		dx *= -1;
	}
	x += dx;
}
void ProfesorMaligno::mover_enemigo_vertical(){

	if (y + dy < 44 || y + dy + 80 > 440){
		dx = 0;
		dy *= -1;
	}
	y += dy;
}

