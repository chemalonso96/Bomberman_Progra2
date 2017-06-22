#pragma once 
#include"ProfesorMaligno.h"
#include"Upecino.h"
#include"Arrbomba.h"
#include"Bomba.h"

using namespace System::Windows::Forms;

class arrprofesormaligno
{
public:
	
	ProfesorMaligno** arreglo_profesormaligno;
	int cant_profe;
	int idNivel;

	arrprofesormaligno(void);
	~arrprofesormaligno(void);


	void eliminar();

	void mostrar_enemigos(Graphics^gr,int Nv_mapa);

	
	void desaparecer_emegigo(int x,int y,int Nv_mapa);


};

arrprofesormaligno::arrprofesormaligno(void)
{
	cant_profe = 42;
	arreglo_profesormaligno = new ProfesorMaligno*[42];
	//mapa 1
	//h
	arreglo_profesormaligno[0] = new ProfesorMaligno(120, 40, E1);
	arreglo_profesormaligno[1] = new ProfesorMaligno(200, 360, E1);
	arreglo_profesormaligno[2] = new ProfesorMaligno(320, 200, E1);
	//v
	arreglo_profesormaligno[3] = new ProfesorMaligno(200, 200, E1);
	arreglo_profesormaligno[4] = new ProfesorMaligno(440, 280, E1);

	//mapa 2
	//h
	arreglo_profesormaligno[5] = new ProfesorMaligno(120, 120, E1);
	arreglo_profesormaligno[6] = new ProfesorMaligno(200, 40, E1);
	arreglo_profesormaligno[7] = new ProfesorMaligno(280, 280, E1);
	arreglo_profesormaligno[8] = new ProfesorMaligno(360, 360, E2);
	arreglo_profesormaligno[9] = new ProfesorMaligno(440, 200, E2);
	//v
	arreglo_profesormaligno[10] = new ProfesorMaligno(40, 120, E1);
	arreglo_profesormaligno[11] = new ProfesorMaligno(200, 200, E1);
	arreglo_profesormaligno[12] = new ProfesorMaligno(280, 360, E2);
	arreglo_profesormaligno[13] = new ProfesorMaligno(360, 120, E2);
	arreglo_profesormaligno[14] = new ProfesorMaligno(440, 280, E2);


	//mapa 3
	//h
	arreglo_profesormaligno[15] = new ProfesorMaligno(120, 160, E1);
	arreglo_profesormaligno[16] = new ProfesorMaligno(200, 200, E3);
	arreglo_profesormaligno[17] = new ProfesorMaligno(280, 40, E2);
	arreglo_profesormaligno[18] = new ProfesorMaligno(360, 360, E3);
	arreglo_profesormaligno[19] = new ProfesorMaligno(120, 280, E2);
	arreglo_profesormaligno[15] = new ProfesorMaligno(40, 160, E2);
	arreglo_profesormaligno[16] = new ProfesorMaligno(360, 200, E3);
	//v
	arreglo_profesormaligno[17] = new ProfesorMaligno(120, 40, E1);
	arreglo_profesormaligno[18] = new ProfesorMaligno(120, 200, E2);
	arreglo_profesormaligno[19] = new ProfesorMaligno(200, 280, E2);
	arreglo_profesormaligno[20] = new ProfesorMaligno(280, 160, E2);
	arreglo_profesormaligno[21] = new ProfesorMaligno(360, 200, E3);
	arreglo_profesormaligno[22] = new ProfesorMaligno(200, 40, E3);
	arreglo_profesormaligno[23] = new ProfesorMaligno(120, 280, E3);

	//mapa 4
	//h
	arreglo_profesormaligno[24] = new ProfesorMaligno(120, 120, E2);
	arreglo_profesormaligno[25] = new ProfesorMaligno(120, 200, E2);
	arreglo_profesormaligno[26] = new ProfesorMaligno(200, 200, E4);
	arreglo_profesormaligno[27] = new ProfesorMaligno(440, 280, E4);
	arreglo_profesormaligno[28] = new ProfesorMaligno(240, 40, E4);
	arreglo_profesormaligno[29] = new ProfesorMaligno(200, 200, E4);
	arreglo_profesormaligno[30] = new ProfesorMaligno(440, 280, E4);
	arreglo_profesormaligno[31] = new ProfesorMaligno(240, 120, E3);
	arreglo_profesormaligno[32] = new ProfesorMaligno(320, 200, E3);
	arreglo_profesormaligno[33] = new ProfesorMaligno(120, 40, E3);
	//v
	arreglo_profesormaligno[34] = new ProfesorMaligno(120, 280, E2);
	arreglo_profesormaligno[35] = new ProfesorMaligno(40, 200, E2);
	arreglo_profesormaligno[36] = new ProfesorMaligno(200, 200, E3);
	arreglo_profesormaligno[37] = new ProfesorMaligno(440, 120, E3);
	arreglo_profesormaligno[38] = new ProfesorMaligno(440, 280, E3);
	arreglo_profesormaligno[39] = new ProfesorMaligno(200, 280, E4);
	arreglo_profesormaligno[40] = new ProfesorMaligno(360, 200, E4);
	arreglo_profesormaligno[41] = new ProfesorMaligno(120, 40, E4);
}

arrprofesormaligno::~arrprofesormaligno(void)
{
}

void arrprofesormaligno::eliminar(){
	int cantidad = 0;
	for (int i = 0; i < cant_profe; i++)
		cantidad += arreglo_profesormaligno[i]->GET_eliminar() ? 1 : 0;
	ProfesorMaligno** auxiliar = new ProfesorMaligno*[cant_profe -cantidad];
	int h = 0;
	if (auxiliar != NULL){
		for (int i = 0; i < cant_profe; i++)
		{
			if (!arreglo_profesormaligno[i]->GET_eliminar()){
				auxiliar[h] = arreglo_profesormaligno[i];
				h++;
			}
		}
		cant_profe--;
		if (arreglo_profesormaligno != NULL)
			delete arreglo_profesormaligno;
		arreglo_profesormaligno = auxiliar;
	}
}

void arrprofesormaligno::mostrar_enemigos(Graphics^gr, int Nv_mapa){
	if (Nv_mapa == 1){
		for (int i = 0; i < 3; i++){
			if (arreglo_profesormaligno[i]->visible){
				arreglo_profesormaligno[i]->mostrar_enemigo(gr);
				arreglo_profesormaligno[i]->mover_enemigo_horizontal();
			}
		}
		for (int i = 3; i < 5; i++){
			if (arreglo_profesormaligno[i]->visible){
				arreglo_profesormaligno[i]->mostrar_enemigo(gr);
				arreglo_profesormaligno[i]->mover_enemigo_vertical();
			}
		}
	}
	if (Nv_mapa == 2){
		for (int i = 5; i < 10; i++){
			if (arreglo_profesormaligno[i]->visible){
				arreglo_profesormaligno[i]->mostrar_enemigo(gr);
				arreglo_profesormaligno[i]->mover_enemigo_horizontal();
			}
		}
		for (int i = 10; i < 15; i++){
			if (arreglo_profesormaligno[i]->visible){
				arreglo_profesormaligno[i]->mostrar_enemigo(gr);
				arreglo_profesormaligno[i]->mover_enemigo_vertical();
			}
		}
	}
	if (Nv_mapa == 3){
		for (int i =15; i < 17; i++){
			if (arreglo_profesormaligno[i]->visible){
				arreglo_profesormaligno[i]->mostrar_enemigo(gr);
				arreglo_profesormaligno[i]->mover_enemigo_horizontal();
			}
		}
		for (int i = 17; i < 24; i++){
			if (arreglo_profesormaligno[i]->visible){
				arreglo_profesormaligno[i]->mostrar_enemigo(gr);
				arreglo_profesormaligno[i]->mover_enemigo_vertical();
			}
		}
	}
	if (Nv_mapa == 4){
		for (int i = 24; i < 33; i++){
			if (arreglo_profesormaligno[i]->visible){
				arreglo_profesormaligno[i]->mostrar_enemigo(gr);
				arreglo_profesormaligno[i]->mover_enemigo_horizontal();
			}
		}
		for (int i = 33; i < 42; i++){
			if (arreglo_profesormaligno[i]->visible){
				arreglo_profesormaligno[i]->mostrar_enemigo(gr);
				arreglo_profesormaligno[i]->mover_enemigo_vertical();
			}
		}
	}
}


