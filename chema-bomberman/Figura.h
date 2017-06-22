#pragma once 

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace System;
using namespace System::Drawing;

public enum Direction{ arriba, abajo, izquierda, derecha };

class Figura
{
protected:

	int x;
	int y;
	int dx;
	int dy;
	int width;
	int high;
	int widthI;
	int	highI;

public:

	Rectangle obtenerrectangulo();
	Figura(void);
	~Figura(void);
	//MODIFICAR
	void SET_x(int New);
	void SET_y(int New);
	void SET_dx(int New);
	void SET_dy(int New);
	//OBTENER
	int GET_x();
	int GET_y();
	int GET_dx();
	int GET_dy();
	int GET_width();
	int GET_high();
	//OTROS
	virtual void mostrar(Graphics^gr);
	virtual void mover(Direction tecla_presionada);
};

Figura::Figura(void){}
Figura::~Figura(void){}

Rectangle Figura::obtenerrectangulo(){
	return Rectangle(x, y, width, high);
}


//MODIFICAR
void Figura::SET_x(int New){ x = New; }
void Figura::SET_y(int New){ y = New; }
void Figura::SET_dx(int New){ dx = New; }
void Figura::SET_dy(int New){ dy = New; }
//OBTENER
int Figura::GET_x(){ return x; }
int Figura::GET_y(){ return y; }
int Figura::GET_dx(){ return dx; }
int Figura::GET_dy(){ return dy; }
int Figura::GET_width(){ return width; }
int Figura::GET_high(){ return high; }
//OTROS
void Figura::mostrar(Graphics^gr){}
void Figura::mover(Direction tecla_presionada){}