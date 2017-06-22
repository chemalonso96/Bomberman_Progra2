#pragma once 

#include"Bloques.h"
#include"Upecino.h"

class arrbloque
{
public:

	Bloques** arreglo_bloques;
	int *cant_bloques;
	arrbloque(void);
	~arrbloque(void);

	void destruir_bloques(int x, int y, int Nv_mapa);
	void mostrar(Graphics^gr, int Nv_mapa);

};

arrbloque::arrbloque()
{
	cant_bloques = new int;
	*cant_bloques = 60;
	arreglo_bloques = new Bloques*[81];
	arreglo_bloques[1] = new Bloques(120, 120, B1);
	arreglo_bloques[2] = new Bloques(280,120 , B1);
	arreglo_bloques[3] = new Bloques(480, 120, B1);
	arreglo_bloques[4] = new Bloques(40,280,B1);
	arreglo_bloques[5] = new Bloques(120,240,B1);
	arreglo_bloques[6] = new Bloques(240,40,B1);
	arreglo_bloques[7] = new Bloques(360, 240,B1);
	arreglo_bloques[8] = new Bloques(280, 320, B1);
	arreglo_bloques[9] = new Bloques(440, 280, B1);
	arreglo_bloques[10] = new Bloques(520, 280, B1);
	arreglo_bloques[11] = new Bloques(160, 120, B1);
	arreglo_bloques[12] = new Bloques(440, 120, B1);
	arreglo_bloques[13] = new Bloques(520, 80, B1);
	arreglo_bloques[14] = new Bloques(120, 280, B1);
	arreglo_bloques[15] = new Bloques(120, 40, B1);
	arreglo_bloques[16] = new Bloques(400, 40, B1);
	arreglo_bloques[17] = new Bloques(280, 240, B1);
	arreglo_bloques[18] = new Bloques(320, 360, B1);
	arreglo_bloques[19] = new Bloques(480, 360, B1);
	arreglo_bloques[20] = new Bloques(280, 360, B1);

	//mapa 2

	arreglo_bloques[21] = new Bloques(80, 120, B2);
	arreglo_bloques[22] = new Bloques(160, 120, B2);
	arreglo_bloques[23] = new Bloques(160, 40, B2);
	arreglo_bloques[24] = new Bloques(520, 80, B2);
	arreglo_bloques[25] = new Bloques(320, 120, B2);
	arreglo_bloques[26] = new Bloques(40, 280, B2);
	arreglo_bloques[27] = new Bloques(320, 200, B2);
	arreglo_bloques[28] = new Bloques(480, 200, B2);
	arreglo_bloques[29] = new Bloques(440, 360, B2);
	arreglo_bloques[30] = new Bloques(440, 280, B2);
	arreglo_bloques[31] = new Bloques(80, 120, B2);
	arreglo_bloques[32] = new Bloques(120, 40, B2);
	arreglo_bloques[33] = new Bloques(400, 40, B2);
	arreglo_bloques[34] = new Bloques(280, 120, B2);
	arreglo_bloques[35] = new Bloques(40, 360, B2);
	arreglo_bloques[36] = new Bloques(120, 200, B2);
	arreglo_bloques[37] = new Bloques(400, 200, B2);
	arreglo_bloques[38] = new Bloques(480, 280, B2);
	arreglo_bloques[39] = new Bloques(360, 280, B2);
	arreglo_bloques[40] = new Bloques(400, 360, B2);
	
	//mapa 3

	arreglo_bloques[41] = new Bloques(448, 288, B3);
	arreglo_bloques[42] = new Bloques(448, 368, B3);
	arreglo_bloques[43] = new Bloques(448, 128, B3);
	arreglo_bloques[44] = new Bloques(208, 128, B3);
	arreglo_bloques[45] = new Bloques(208, 208, B3);
	arreglo_bloques[46] = new Bloques(408, 208, B3);
	arreglo_bloques[47] = new Bloques(408, 48,B3);
	arreglo_bloques[48] = new Bloques(48, 208, B3);
	arreglo_bloques[49] = new Bloques(288, 368, B3);
	arreglo_bloques[50] = new Bloques(528, 368, B3);
	arreglo_bloques[51] = new Bloques(408, 368, B3);
	arreglo_bloques[52] = new Bloques(368, 328, B3);
	arreglo_bloques[53] = new Bloques(328, 128, B3);
	arreglo_bloques[54] = new Bloques(48, 128, B3);
	arreglo_bloques[55] = new Bloques(248, 208, B3);
	arreglo_bloques[56] = new Bloques(168, 288, B3);
	arreglo_bloques[57] = new Bloques(168, 48, B3);
	arreglo_bloques[58] = new Bloques(48, 248, B3);
	arreglo_bloques[59] = new Bloques(208, 368, B3);
	arreglo_bloques[60] = new Bloques(528, 168, B3);
	//mapa4
	arreglo_bloques[61] = new Bloques(88, 128, B4);
	arreglo_bloques[62] = new Bloques(288, 128, B4);
	arreglo_bloques[63] = new Bloques(490, 128, B4);
	arreglo_bloques[64] = new Bloques(48, 288, B4);
	arreglo_bloques[65] = new Bloques(128, 248, B4);
	arreglo_bloques[66] = new Bloques(248, 48, B4);
	arreglo_bloques[67] = new Bloques(368, 248, B4);
	arreglo_bloques[68] = new Bloques(288, 328, B4);
	arreglo_bloques[69] = new Bloques(448, 289, B4);
	arreglo_bloques[70] = new Bloques(529, 288, B4);
	arreglo_bloques[71] = new Bloques(168, 128, B4);
	arreglo_bloques[72] = new Bloques(450, 128, B4);
	arreglo_bloques[73] = new Bloques(529, 88, B4);
	arreglo_bloques[74] = new Bloques(128, 288, B4);
	arreglo_bloques[75] = new Bloques(128, 48, B4);
	arreglo_bloques[76] = new Bloques(408, 48, B4);
	arreglo_bloques[77] = new Bloques(288, 248, B4);
	arreglo_bloques[78] = new Bloques(328, 369, B4);
	arreglo_bloques[79] = new Bloques(488, 369, B4);
	arreglo_bloques[80] = new Bloques(288, 369, B4);
	

}

arrbloque::~arrbloque()
{
	for (int i = 1; i < *cant_bloques; i++)
		delete arreglo_bloques[i];
	delete cant_bloques;
}

void arrbloque::destruir_bloques(int x, int y, int Nv_mapa){
	if (Nv_mapa == 1){
		for (int i = 1; i <= *cant_bloques; i++){
			if (x - 40 == arreglo_bloques[i]->GET_x() && y == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
			if (x + 40 == arreglo_bloques[i]->GET_x() && y == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
			if (x == arreglo_bloques[i]->GET_x() && y - 40 == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
			if (x == arreglo_bloques[i]->GET_x() && y + 40 == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
		}
	}
	if (Nv_mapa == 2){
		for (int i = 21; i <= *cant_bloques; i++){
			if (x - 40 == arreglo_bloques[i]->GET_x() && y == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
			if (x + 40 == arreglo_bloques[i]->GET_x() && y == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
			if (x == arreglo_bloques[i]->GET_x() && y - 40 == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
			if (x == arreglo_bloques[i]->GET_x() && y + 40 == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
		}
	}
	if (Nv_mapa == 3){
		for (int i = 41; i <= *cant_bloques; i++){
			if (x - 40 == arreglo_bloques[i]->GET_x() && y == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
			if (x + 40 == arreglo_bloques[i]->GET_x() && y == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
			if (x == arreglo_bloques[i]->GET_x() && y - 40 == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
			if (x == arreglo_bloques[i]->GET_x() && y + 40 == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
		}
	}
	if (Nv_mapa == 4){
		for (int i = 61; i <= *cant_bloques; i++){
			if (x - 40 == arreglo_bloques[i]->GET_x() && y == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
			if (x + 40 == arreglo_bloques[i]->GET_x() && y == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
			if (x == arreglo_bloques[i]->GET_x() && y - 40 == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
			if (x == arreglo_bloques[i]->GET_x() && y + 40 == arreglo_bloques[i]->GET_y())
				arreglo_bloques[i]->visible = false;
		}
	}

}

void arrbloque::mostrar(Graphics^gr, int Nv_mapa){
	if (Nv_mapa == 1){
		for (int i = 1; i <= 20; i++){
			if (arreglo_bloques[i]->visible){
				arreglo_bloques[i]->mostrar(gr);
			}
		}
	}
	if (Nv_mapa == 2){
		for (int i = 21; i <= 40; i++){
			if (arreglo_bloques[i]->visible){
				arreglo_bloques[i]->mostrar(gr);
			}
		}
	}
	if (Nv_mapa == 3){
		for (int i = 41; i <= 60; i++){
			if (arreglo_bloques[i]->visible){
				arreglo_bloques[i]->mostrar(gr);
			}
		}
	}
	if (Nv_mapa == 4){
		for (int i = 61; i <= 80; i++){
			if (arreglo_bloques[i]->visible){
				arreglo_bloques[i]->mostrar(gr);
			}
		}
	}

}

