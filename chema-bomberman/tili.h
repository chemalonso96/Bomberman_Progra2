#pragma once 

#include"Figura_II.h"

class tili :public Figura_II
{
public:
	tili(void);
	~tili(void);

	void mostrar_tili(Graphics^gr);
};

tili::tili(void)
{
	x = 607;
	y = 0;
	width = 120;
	high = 457;
}

tili::~tili(void){}

void tili::mostrar_tili(Graphics^gr){
	gr->FillRectangle(gcnew SolidBrush(Color::Red), x, y, width, high);
}