#pragma once

#include"Figura_II.h"

#define n_frames 4

class Bombas :public Figura
{
private:

	char* imagen;
	
	int widthI;
	int highI;
	bool eliminar;

public:
	int indice;
	int tiempo;
	bool visualizacion;

	Bombas (void);
	Bombas(int Px, int Py);//dar las cordenadas 
	~Bombas (void);

	void SET_eliminar(bool nuevo);

	bool GET_eliminar();

	void SET_imagen(char* New);
	void mostrar(Graphics^gr);
};

Bombas ::Bombas (void){}
Bombas::Bombas(int Px,int Py)
{
	double xx = Px*1.0 / 40.0;
	double yy = Py*1.0 / 40.0;
	x = (xx + 0.5);
	
	x *= 40;
	
	y = (yy + 0.5);
	y *= 40;

	width = 120;
	high = 120;
	imagen = new char[100];
	tiempo = 70;
	indice = 0;
	visualizacion = true;
}
Bombas ::~Bombas (void)
{
	delete imagen;
}

void Bombas::SET_eliminar(bool nuevo){
	eliminar = nuevo;
}

bool Bombas::GET_eliminar(){
	return eliminar;
}

void Bombas::SET_imagen(char* New){
	strcpy(imagen, New);
	Bitmap^bm = gcnew Bitmap(gcnew String(New));
	widthI = 239;
	highI = 230;
	delete bm;
}
void Bombas::mostrar(Graphics^gr){
	Bitmap^bm = gcnew Bitmap(gcnew String(imagen));
	Rectangle origen = Rectangle(indice*widthI,0,widthI,highI);
	Rectangle fin = Rectangle(x-40,y-40,120,120);
	bm->MakeTransparent();
	gr->DrawImage(bm, fin, origen, GraphicsUnit::Pixel);
}