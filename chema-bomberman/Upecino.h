#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include"Figura.h"
#include"Bomba.h"
#include"arrprofesormaligno.h"
#include"arrbloque_indestructible.h"
#include"Arrbloque.h"

class Upecino :public Figura
{
private:
	int column;
	int row;
	char* imagen;

public:
	int vida;
	int puntaje;
	int N_bombas;

	arrbloque_indestructible* obj_arrBI;
	arrbloque* obj_arrbloque;
	Upecino(void);
	Upecino(int Px, int Py);
	~Upecino(void);

	void SET_imagen(char* New);
	void mover_Upecino(Direction tecla_presionada);
	void mostrar_Upecino(Graphics^gr);
	bool colision_PyU(Upecino* obj_upecino, Bloques* obj_bloques);
	void verificar_colision(Bloques* obj_bloques);

	bool colision_EyU(Upecino* obj_upecino,ProfesorMaligno* obj_profesormaligno);
};


Upecino::Upecino(void){} 

Upecino::Upecino(int Px, int Py)
{
	x = Px;
	y = Py;
	width = high = 40;
	dx = dy = 0;
	column = row = 0;
	vida = 3;
	puntaje = 0;
	N_bombas = 0;
	imagen = new char[100];
	obj_arrBI = new arrbloque_indestructible();
	obj_arrbloque = new arrbloque();

}

Upecino::~Upecino(void)
{
	delete imagen;
}

void Upecino::SET_imagen(char* New)
{
	strcpy(imagen, New);
	Bitmap^bm = gcnew Bitmap(gcnew String(New));
	widthI = bm->Width / 4;
	highI = bm->Height / 4;
	delete bm;
}

void Upecino::mostrar_Upecino(Graphics^gr)
{
	Bitmap^bm = gcnew Bitmap(gcnew String(imagen));
	Rectangle origen = Rectangle(column*widthI, row*highI, widthI, highI);
	Rectangle fin = Rectangle(x, y, width, high);
	gr->DrawImage(bm, fin, origen, GraphicsUnit::Pixel);
}

void Upecino::mover_Upecino(Direction tecla_presionada)
{
	if (tecla_presionada == Direction::abajo){
		row = 0;
		dx = 0;
		dy = 10;
	}
	if (tecla_presionada == Direction::izquierda){
		row = 1;
		dx = -10;
		dy = 0;
	}
	if (tecla_presionada == Direction::arriba){
		row = 2;
		dx = 0;
		dy = -10;
	}
	if (tecla_presionada == Direction::derecha){
		row = 3;
		dx = 10;
		dy = 0;
	}

	if (column == 3)column = 0;
	column++;


	//no se salga del mapa 
	if (!(x + dx < 40 || x + dx>535))
		//el movil avance
		x += dx;
	//no se salga del mapa 
	if (!(y + dy < 40 || y + dy>376))
		//el movil avance
		y += dy;

	//colision bloques indestructible

	bloque_indestructible* obj_BI=NULL;

	for (int i = 0; i < obj_arrBI->cant_BI; i++){
		obj_BI = obj_arrBI->arreglo[i];
		if (obtenerrectangulo().IntersectsWith(obj_BI->obtenerrectangulo())){
			if (tecla_presionada == izquierda || tecla_presionada == derecha)
				x -= dx;
			if (tecla_presionada == arriba || tecla_presionada == abajo)
				y -= dy;
		}
	}
}

bool Upecino::colision_EyU(Upecino* obj_upecino, ProfesorMaligno* obj_profesormaligno){

	if (!obj_profesormaligno->visible)
		return false;

	if (obj_upecino->obtenerrectangulo().IntersectsWith(obj_profesormaligno->obtenerrectangulo())){
		return true;
	}
	else
		return false;
}

bool Upecino::colision_PyU(Upecino* obj_upecino, Bloques* obj_bloques){
	if (obj_upecino->obtenerrectangulo().IntersectsWith(obj_bloques->obtenerrectangulo()))
		return true;
	else
		return false;
}

