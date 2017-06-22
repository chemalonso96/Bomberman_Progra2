#pragma once 
#include"Figura_II.h"

public enum tipoItems{I1,I2,I3,I4,I5,I6,I7};

class Items :public Figura_II
{
private:
	char* imagen;
	bool eliminar;


public:
	tipoItems tipo;
	bool visible;

	Items(void);
	Items(int px,int py,tipoItems tipo);
	~Items(void);

	void SET_eliminar(bool nuevo);
	bool GET_eliminar();

	void SET_imagen(char* New);
	void mostrar(Graphics^gr);
};

Items::Items(int px, int py, tipoItems ptipo)
{
	visible = true;
	eliminar = false;
	x = px;
	y = py;
	tipo = ptipo;
	high = 40;
	width = 40;
	imagen = new char[100];
}

Items::Items(void){}
Items::~Items(void)
{
	delete imagen;
}

void Items::SET_eliminar(bool nuevo){ 
	eliminar = nuevo; 
}
bool Items::GET_eliminar(){ 
	return eliminar;
}

void Items::SET_imagen(char* New){
	strcpy(imagen, New);
	Bitmap ^bm = gcnew Bitmap(gcnew String(New));
	width = 40;
	high = 40;
	delete bm;
}
void Items::mostrar(Graphics^gr){
	if (visible){
		if (tipo == tipoItems::I1)SET_imagen("Resources\\img\\sprites\\personaje\\vida.jpg");
		if (tipo == tipoItems::I2)SET_imagen("Resources\\img\\sprites\\personaje\\bomba.jpg");
		if (tipo == tipoItems::I3)SET_imagen("Resources\\img\\sprites\\personaje\\moneda.png");
		if (tipo == tipoItems::I4)SET_imagen("Resources\\img\\sprites\\personaje\\moneda2.png");
		if (tipo == tipoItems::I5)SET_imagen("Resources\\img\\sprites\\personaje\\moneda3.png");
		if (tipo == tipoItems::I6)SET_imagen("Resources\\img\\sprites\\personaje\\moneda4.png");
		if (tipo == tipoItems::I7)SET_imagen("Resources\\img\\sprites\\personaje\\moneda5.png");
		Bitmap^bm = gcnew Bitmap(gcnew String(imagen));
		Rectangle origen = Rectangle(0, 0, width, high);
		Rectangle fin = Rectangle(x, y, width, high);
		gr->DrawImage(bm, fin, origen, GraphicsUnit::Pixel);
	}
}