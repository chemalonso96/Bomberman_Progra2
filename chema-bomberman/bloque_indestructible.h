#pragma once 
#include"Figura_II.h"

class bloque_indestructible:public Figura_II
{
public:
	bloque_indestructible(void);
	bloque_indestructible(int px,int py);
	~bloque_indestructible(void);
	
	void mostrar_cuadro(Graphics^gr);
};

bloque_indestructible::bloque_indestructible(void){}

bloque_indestructible::bloque_indestructible(int px, int py)
{
	x = px;
	y = py;
	width = 40;
	high = 40;
}

bloque_indestructible::~bloque_indestructible(void){}

void bloque_indestructible::mostrar_cuadro(Graphics^gr){
	gr->DrawRectangle(gcnew Pen(Color::Black), x, y, width, high);
}
