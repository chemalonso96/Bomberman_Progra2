#pragma once 

#include"Figura_II.h"
#include"Bomba.h"
#include"Arrbloque.h"

class arrbomba:public Figura_II
{
public:
	Bombas** arreglo_bomba;
	int cant_bombas;

	arrbomba(void);
	~arrbomba(void);

	arrbloque* obj_arrbloques;

	void colocar_bomba(int x, int y);
	void mostrar_bomba(Graphics^gr);
	void eliminar_bomba();
	void explotar_bombas(Graphics^gr);
};

arrbomba::arrbomba(void)
{
	cant_bombas = 0;
	arreglo_bomba = NULL;
}

arrbomba::~arrbomba(void){}




void arrbomba::colocar_bomba(int x, int y){
	Bombas** auxiliar = new Bombas*[cant_bombas + 1];
	if (auxiliar != NULL){
		for (int i = 0; i < cant_bombas; i++)
			auxiliar[i] = arreglo_bomba[i];
		auxiliar[cant_bombas] = new Bombas(x, y); 
		cant_bombas++;
		if (arreglo_bomba != NULL)
			delete arreglo_bomba;
		arreglo_bomba = auxiliar;
	}
}

void arrbomba::eliminar_bomba(){
	Bombas** auxiliar = new Bombas*[cant_bombas + 1];
	if (auxiliar != NULL){
		for (int i = 0; i < cant_bombas; i++)
			auxiliar[i] = arreglo_bomba[i+1];
		cant_bombas--;
		if (arreglo_bomba != NULL)
			delete arreglo_bomba;
		arreglo_bomba = auxiliar;
	}
}

void arrbomba::mostrar_bomba(Graphics^gr){
	for (int i = 0; i < cant_bombas; i++){
		arreglo_bomba[i]->SET_imagen("explo2.png");
		arreglo_bomba[i]->mostrar(gr);
	}
}

void arrbomba::explotar_bombas(Graphics^gr){
	for (int i = 0; i < cant_bombas; i++){
		if (arreglo_bomba[i]->visualizacion == true){
			if (arreglo_bomba[i]->tiempo % 20 == 0)
				arreglo_bomba[i]->indice = arreglo_bomba[i]->indice + 1;

			arreglo_bomba[i]->tiempo = arreglo_bomba[i]->tiempo - 10;
			
			if (arreglo_bomba[i]->tiempo == 0){
				
				obj_arrbloques->destruir_bloques(arreglo_bomba[i]->GET_x(), arreglo_bomba[i]->GET_y(), 1);
				arreglo_bomba[i]->visualizacion = false;
				eliminar_bomba();
			}
		}
	}
}