#pragma once 
#include"Figura_II.h"
#include<vcclr.h>

public enum tipos{B1,B2,B3,B4};

class Bloques :public Figura_II
{
private:

	char* imagen;
	bool eliminar;
	tipos tipo;

public:

	bool visible;
	
	Bloques(void);
	~Bloques(void);
	Bloques(int px,int py,tipos ptipo);

	void SET_eliminar(bool nuevo);
	bool GET_eliminar();

	void SET_imagen(char* New);
	void mostrar(Graphics^gr);
};

Bloques::Bloques(void){}

Bloques::Bloques(int px,int py,tipos ptipo)
{
	visible = true;
	high = 40;
	width = 40;
	imagen = new char[100];
	eliminar = false;
	x = px;
	y = py;
	tipo = ptipo;	
}

Bloques::~Bloques(void)
{
	delete imagen;
}

void Bloques::SET_eliminar(bool nuevo){
	eliminar = nuevo;
}

bool Bloques::GET_eliminar(){
	return eliminar;
}

void Bloques::SET_imagen(char* New){
	strcpy(imagen, New);
	Bitmap ^bm = gcnew Bitmap(gcnew String(New));
	width =40;
	high =40;
	delete bm;
}

void Bloques::mostrar(Graphics^gr){
	if(visible)
	{
		if (tipo == tipos::B1)SET_imagen("Resources\\img\\escenarios\\bloque1.jpg");
		if (tipo == tipos::B2)SET_imagen("Resources\\img\\escenarios\\bloque-1.png");
		if (tipo == tipos::B3)SET_imagen("Resources\\img\\escenarios\\bloque-4.png");
		if (tipo == tipos::B4)SET_imagen("Resources\\img\\escenarios\\bloque2.jpg");

        Bitmap^bm = gcnew Bitmap(gcnew String(imagen));
		Rectangle origen = Rectangle(0, 0, width, high);
		Rectangle fin = Rectangle(x, y, width, high);
		gr->DrawImage(bm, fin, origen, GraphicsUnit::Pixel);
	}

}