#pragma once 

#include"bloque_indestructible.h"

class arrbloque_indestructible
{
public:

	bloque_indestructible** arreglo;
	int cant_BI;

	arrbloque_indestructible(void);
	~arrbloque_indestructible(void);

};

arrbloque_indestructible::arrbloque_indestructible(void)
{
	cant_BI = 24;
	arreglo = new bloque_indestructible*[24];
	arreglo[0] = new bloque_indestructible(80,80);
	arreglo[1] = new bloque_indestructible(80,160);
	arreglo[2] = new bloque_indestructible(80,240);
	arreglo[3] = new bloque_indestructible(80,320);
	arreglo[4] = new bloque_indestructible(160,80);
	arreglo[5] = new bloque_indestructible(160,160);
	arreglo[6] = new bloque_indestructible(160,240);
	arreglo[7] = new bloque_indestructible(160,320);
	arreglo[8] = new bloque_indestructible(240,80);
	arreglo[9] = new bloque_indestructible(240,160);
	arreglo[10] = new bloque_indestructible(240,320);
	arreglo[11] = new bloque_indestructible(320,80);
	arreglo[12] = new bloque_indestructible(320,160);
	arreglo[13] = new bloque_indestructible(320,240);
	arreglo[14] = new bloque_indestructible(320,320);
	arreglo[15] = new bloque_indestructible(400,80);
	arreglo[16] = new bloque_indestructible(400,160);
	arreglo[17] = new bloque_indestructible(400,240);
	arreglo[18] = new bloque_indestructible(400,320);
	arreglo[19] = new bloque_indestructible(480,80);
	arreglo[20] = new bloque_indestructible(480,160);
	arreglo[21] = new bloque_indestructible(480,240);
	arreglo[22] = new bloque_indestructible(480,320);
	arreglo[23] = new bloque_indestructible(240,240);

}

arrbloque_indestructible::~arrbloque_indestructible(void)
{
}
