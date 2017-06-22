#pragma once

#include"Figura.h"

class enemigo_final:public Figura
{
private:
	char* imagen;
public:
	int indice;
	enemigo_final(void);
	~enemigo_final(void);

	void SET_imagen(char *nuevo);

	void mostrar(Graphics^gr);
	void mover();

};

enemigo_final::enemigo_final(void)
{
	indice = 0;
	x = 250;
	y = 250;
	dx = 6;
	dy = 6;
	width = 60;
	high = 60;
	imagen = new char[100];
}



enemigo_final::~enemigo_final(void)
{
	delete imagen;
}

void enemigo_final::SET_imagen(char *nuevo){
	strcpy(imagen, nuevo);
	Bitmap^bm = gcnew Bitmap(gcnew String(nuevo));

	widthI = bm->Width/6;
	highI = bm->Height;

	delete bm;
}

void enemigo_final::mostrar(Graphics^gr){
	mover();
	Bitmap^bm = gcnew Bitmap(gcnew String(imagen));
	Rectangle origen = Rectangle(widthI*indice,0,widthI,highI);
	Rectangle fin = Rectangle(x,y,50,50);
	gr->DrawImage(bm, fin, origen, GraphicsUnit::Pixel);
	indice++;
	if (indice == 6)
		indice = 0;
}
void enemigo_final::mover(){
	if (x + dx < 40 || x + dx < 562)
		dx *= -1;
	x += dx;
	if (y + dy < 40 || y + dy < 416)
		dy *= -1;
	y += dy;
}