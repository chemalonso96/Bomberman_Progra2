#pragma once
#include"Figura_II.h"
class Escenas:public Figura_II
{
protected:
	char* imagen;
public:
	Escenas(void);
	~Escenas(void);

	void SET_imagen(char* New);
	void mostrar(Graphics^gr);

};

Escenas::Escenas(void)
{
	x = y = width = high = 0;
	imagen = new char[100];
}

Escenas::~Escenas(void)
{
	delete imagen;
}

void Escenas::SET_imagen(char* New){
	strcpy(imagen, New);
	Bitmap^bm = gcnew Bitmap(gcnew String(New));
	width = bm->Width;
	high = bm->Height;
	delete bm;
}

void Escenas::mostrar(Graphics^gr){
	Bitmap^bm = gcnew Bitmap(gcnew String(imagen));

	Rectangle origen = Rectangle(0, 0, width, high);
	Rectangle fin = Rectangle(x,y,width,high);

	gr->DrawImage(bm, fin, origen, GraphicsUnit::Pixel);
}