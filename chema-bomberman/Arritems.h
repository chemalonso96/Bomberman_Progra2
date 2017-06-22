#pragma once 

#include"Items.h"
#include"Upecino.h"

using namespace System::Windows::Forms;

class arritems
{
public:

	Items** arreglo_items;
	int *cant_items;
	Upecino* obj_upecino;

	arritems(void);
	~arritems(void);

	void eliminar();
	void mostrar(Graphics^gr,int Nv_mapa);
	bool colision_Items_upecino(Items* obj_items, Upecino* obj_upecino);
	void desaparecer_items(int Nv_mapa);


};

arritems::arritems(void)
{
	cant_items = new int;
	*cant_items = 55;
	arreglo_items = new Items*[55];
	arreglo_items[0] = new Items(120, 360, I3);
	arreglo_items[1] = new Items(120, 360, I3);
	arreglo_items[2] = new Items(120, 200, I3);
	arreglo_items[3] = new Items(360, 40, I3);
	arreglo_items[4] = new Items(320, 280, I3);
	arreglo_items[5] = new Items(240, 120, I3);
	arreglo_items[6] = new Items(360, 200, I3);
	arreglo_items[7] = new Items(40, 120, I3);
	arreglo_items[8] = new Items(440, 80, I1);
	arreglo_items[9] = new Items(440, 360, I1);
	arreglo_items[10] = new Items(120, 280, I1);
	arreglo_items[11] = new Items(280, 200, I1);
	arreglo_items[12] = new Items(360, 160, I1);
	arreglo_items[13] = new Items(40, 200, I2);

	//MAPA2 
	arreglo_items[14] = new Items(120, 360, I4);
	arreglo_items[15] = new Items(120, 200, I4);
	arreglo_items[16] = new Items(360, 40, I4);
	arreglo_items[17] = new Items(320, 280, I4);
	arreglo_items[18] = new Items(240, 120, I4);
	arreglo_items[19] = new Items(360, 200, I4);
	arreglo_items[20] = new Items(40, 120, I4);
	arreglo_items[21] = new Items(440, 80, I2);
	arreglo_items[22] = new Items(440, 360, I2);
	arreglo_items[23] = new Items(120, 280, I2);
	arreglo_items[24] = new Items(280, 200, I2);
	arreglo_items[25] = new Items(360, 200, I2);
	arreglo_items[26] = new Items(40, 200, I2);

	//MAPA3
	arreglo_items[27] = new Items(120, 360, I5);
	arreglo_items[28] = new Items(120, 200, I5);
	arreglo_items[29] = new Items(360, 40, I5);
	arreglo_items[30] = new Items(320, 280, I5);
	arreglo_items[31] = new Items(240, 120, I5);
	arreglo_items[32] = new Items(360, 200, I5);
	arreglo_items[33] = new Items(40, 80, I5);
	arreglo_items[34] = new Items(440, 80, I1);
	arreglo_items[35] = new Items(440, 320, I1);
	arreglo_items[36] = new Items(120, 280, I1);
	arreglo_items[37] = new Items(280, 200, I1);
	arreglo_items[38] = new Items(360, 120, I2);
	arreglo_items[39] = new Items(40, 160, I2);
	arreglo_items[40] = new Items(40, 320, I2);

	//MAPA4


	arreglo_items[41] = new Items(400, 200, I6);
	arreglo_items[42] = new Items(80, 200, I6);
	arreglo_items[43] = new Items(440, 40, I6);
	arreglo_items[44] = new Items(200, 240, I6);
	arreglo_items[45] = new Items(200, 120, I6);
	arreglo_items[46] = new Items(400, 280, I6);
	arreglo_items[47] = new Items(80, 120, I2);
	arreglo_items[48] = new Items(440, 320, I2);
	arreglo_items[49] = new Items(40, 160, I2);
	arreglo_items[50] = new Items(520, 40, I2);
	arreglo_items[51] = new Items(280, 240, I2);
	arreglo_items[52] = new Items(160, 120, I1);
	arreglo_items[53] = new Items(360, 240, I1);
	arreglo_items[54] = new Items(80, 120, I1);

}

arritems::~arritems(void)
{
	for (int i = 0; i < *cant_items; i++)
		delete arreglo_items[i];
	delete cant_items;
}


void arritems::mostrar(Graphics^gr, int Nv_mapa){
	if (Nv_mapa == 1){
		for (int i = 0; i < 14; i++){
			if (arreglo_items[i]->visible)
				arreglo_items[i]->mostrar(gr);
		}
	}
	if (Nv_mapa == 2){
		for (int i = 14; i < 27; i++){
			if (arreglo_items[i]->visible)
				arreglo_items[i]->mostrar(gr);
		}
	}
	if (Nv_mapa == 3){
		for (int i = 27; i < 41; i++){
			if (arreglo_items[i]->visible )
				arreglo_items[i]->mostrar(gr);
		}
	}
	if (Nv_mapa == 4){
		for (int i = 41; i < 55; i++){
			if (arreglo_items[i]->visible )
				arreglo_items[i]->mostrar(gr);
		}
	}
}

void arritems::eliminar(){
	int contador = 0;
	for (int i = 0; i < *cant_items; i++)
		if (arreglo_items[i]->GET_eliminar())
			contador++;
	if (contador > 0){
		Items**auxiliar = new Items*[*cant_items - contador];
		if (auxiliar != NULL){
			int j = 0;
			for (int i = 0; i<*cant_items; i++)
			{
				if (!arreglo_items[i]->GET_eliminar())
				{
					auxiliar[j] = arreglo_items[i];
					j++;
				}
			}
			cant_items = cant_items - contador;
			if (arreglo_items != NULL)
				delete[] arreglo_items;
			arreglo_items = auxiliar;
		}
	}
}
//las colisiones
bool arritems::colision_Items_upecino(Items* obj_items, Upecino* obj_upecino){

	if (obj_items->obtenerrectangulo().IntersectsWith(obj_upecino->obtenerrectangulo()))
		return true;
	else
		return false;

}

void arritems::desaparecer_items(int Nv_mapa){

	for (int i = 0; i < *cant_items; i++){
		if (arreglo_items[i]->visible == true){
			if (colision_Items_upecino(arreglo_items[i], obj_upecino)){
				arreglo_items[i]->visible = false;
				if (Nv_mapa == 1){
					if (arreglo_items[i]->tipo == I1){
						obj_upecino->vida = obj_upecino->vida + 1;
						obj_upecino->puntaje = obj_upecino->puntaje + 10;
					}
					else if (arreglo_items[i]->tipo == I2){
						obj_upecino->N_bombas = obj_upecino->N_bombas + 1;
						obj_upecino->puntaje = obj_upecino->puntaje + 10;
					}
					else if (arreglo_items[i]->tipo == I3){
						obj_upecino->puntaje = obj_upecino->puntaje + 20;
					}
				}

				if (Nv_mapa == 2){
					if (arreglo_items[i]->tipo == I1){
						obj_upecino->vida = obj_upecino->vida + 1;
						obj_upecino->puntaje = obj_upecino->puntaje + 10;
					}
					else if (arreglo_items[i]->tipo == I2){
						obj_upecino->N_bombas = obj_upecino->N_bombas + 1;
						obj_upecino->puntaje = obj_upecino->puntaje + 10;
					}
				    else if (arreglo_items[i]->tipo == I4){
					obj_upecino->puntaje = obj_upecino->puntaje + 25;
				}
				}
				if (Nv_mapa == 3){
					if (arreglo_items[i]->tipo == I1){
						obj_upecino->vida = obj_upecino->vida + 1;
						obj_upecino->puntaje = obj_upecino->puntaje + 10;
					}
					else if (arreglo_items[i]->tipo == I2){
						obj_upecino->N_bombas = obj_upecino->N_bombas + 1;
						obj_upecino->puntaje = obj_upecino->puntaje + 10;
					}
				    else if (arreglo_items[i]->tipo == I5){
					obj_upecino->puntaje = obj_upecino->puntaje + 30;
				}
				}
				if (Nv_mapa == 4){
					if (arreglo_items[i]->tipo == I1){
						obj_upecino->vida = obj_upecino->vida + 1;
						obj_upecino->puntaje = obj_upecino->puntaje + 10;
					}
					else if (arreglo_items[i]->tipo == I2){
						obj_upecino->N_bombas = obj_upecino->N_bombas + 1;
						obj_upecino->puntaje = obj_upecino->puntaje + 10;
					}
					else if (arreglo_items[i]->tipo == I6){
						obj_upecino->puntaje = obj_upecino->puntaje + 35;
					}
				}
				eliminar();
			}
		}
	}

}

