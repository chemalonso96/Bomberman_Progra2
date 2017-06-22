#pragma once

#include<string.h>
#include<stdlib.h>

using namespace System;
using namespace System::Drawing;

class Figura_II
{
protected:
	int x;
	int y;
	int width;
	int high;
	int widthI;
	int	highI;
public:

	Rectangle obtenerrectangulo();

	Figura_II(void);
	~Figura_II(void);

	void SET_x(int nuevo);
	void SET_y(int nuevo);

	int GET_x();
	int GET_y();
	int GET_width();
	int GET_high();

	virtual void mostrar(Graphics^gr);
};

Figura_II::Figura_II(void){}
Figura_II::~Figura_II(void){}


Rectangle Figura_II::obtenerrectangulo(){
	return Rectangle(x, y, width, high);
}

void Figura_II::SET_x(int nuevo){ x = nuevo; }
void Figura_II::SET_y(int nuevo){ y = nuevo; }

int Figura_II::GET_x(){ return x; }
int Figura_II::GET_y(){ return y; }
int Figura_II::GET_width(){ return width; }
int Figura_II::GET_high(){ return high; }

void Figura_II::mostrar(Graphics^gr){}