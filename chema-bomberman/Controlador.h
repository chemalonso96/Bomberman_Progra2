#pragma once

#include"Upecino.h"
#include"arrprofesormaligno.h"
#include"ProfesorMaligno.h"
#include"Escenas.h"
#include"Items.h"
#include"Arritems.h"
#include"Bomba.h"
#include"Arrbomba.h"
#include"arrbloque.h"
#include"tili.h"
#include"arrbloque_indestructible.h"
#include"enemigo_final.h"

public enum botones{ enter,i,r,c,s,v,f12,f,d1,d2,d3,d4,d5,espacio,esc,ninguno,g,h,j,k,l};

class Controlador
{
private:

	
	arrbomba* obj_arrbombas;
	arrbloque* obj_arrbloque;
	Escenas* obj_escenas;
	Items* obj_items;
	tili *obj_tili;
	bloque_indestructible* obj_BI;
	//reconocer los botones
	botones acciones_tecla;
	//Atributos del ArrItems

	
	bool inicio_del_juego = false;
	bool ok_mover = true;
	bool nivel_completado;
	int tiempo;
	int puntaje;
	int vida;

	int personaje = 1;


public:
	Direction tecla_presionada;
	enemigo_final*obj_enemigofinal;
	int tiempoNivel;
	arrbloque_indestructible* obj_arrBI;
	arrprofesormaligno* obj_arrprofesormaligno;
	Items** arreglo_items;
	Bombas* obj_bombas;
	Bloques* obj_bloques;
	int *cant_items;
	int id_escenas = 0;

	Upecino* obj_upecino;
	Controlador(void);
	~Controlador(void);

	
	void mover_personaje(Direction tecla_presionada);
	void mostrar_upecino_1(Graphics^gr);
	void mostrar_upecino_2(Graphics^gr);
	void mostrar_upecino_3(Graphics^gr);
	void mostrar_upecino_4(Graphics^gr);
	void mostrar_upecino_5(Graphics^gr);
	

	void accionar(Graphics^gr, botones acciones_tecla);
	void mostrar_intro(Graphics^gr);
	void mostrar_instrucciones(Graphics^gr);
	void mostrar_ranking(Graphics^gr);
	void mostrar_enemigo1(Graphics^gr);

	void mostrar_mapa1(Graphics^gr);
	void mostrar_mapa2(Graphics^gr);
	void mostrar_mapa3(Graphics^gr);
	void mostrar_mapa4(Graphics^gr);
	void mostrar_mapa5(Graphics^gr);
	void mostrar_tili(Graphics^gr);
	
	void mostrar_pausa(Graphics^gr);
	void mostrar_puntuacion(Graphics^gr);
	void mostrar_eleccion(Graphics^gr);

	void destruir_upecino(int nivel);
	void verificar_calision_bloque(int nivel);


};

Controlador::Controlador(void)
{
	obj_bloques = new Bloques();
	obj_upecino = new Upecino(40, 40);
	obj_arrbombas = new arrbomba();
	obj_arrbloque = new arrbloque();
	obj_escenas = new Escenas();
	obj_items = new Items();
	obj_tili = new tili();
	obj_arrBI = new arrbloque_indestructible();
	tiempoNivel = 0;
	obj_bombas = new Bombas(obj_upecino->GET_x(),obj_upecino->GET_y());
	nivel_completado = false;
	tiempo = 0;
}

Controlador::~Controlador(void){}


void Controlador::destruir_upecino(int nivel){
	int min = 0;
	int max = 0;
	if (nivel == 1)
	{
		min = 0;
		max = 5;
	}
	if (nivel == 2){
		min = 5;
		max = 15;
	}
	if (nivel == 3){
		min = 15;
		max = 24;
	}
	if (nivel == 4){
		min = 24;
		max = 42;
	}

	for (int i = min; i < max; i++){
		if (obj_upecino->colision_EyU(obj_upecino, obj_arrprofesormaligno->arreglo_profesormaligno[i])){
			obj_upecino->vida--;
			obj_upecino->SET_x(40);
			obj_upecino->SET_y(40);
			/*if (obj_upecino->vida == 0){
				MessageBox::Show("PERDISTE JOVEN INTENTELO NUEVAMENTE  - USTED HA FINALIZADO CON UN TIEMPO DE " +
					tiempoNivel.ToString() + "   SEGUNDOS   " +
					obj_upecino->vida.ToString() + "   VIDAS   " +
					obj_upecino->puntaje.ToString() + "    PUNTOS    " +
					obj_upecino->N_bombas.ToString() + "    BOMBAS   ");
			}*/

		}
	}
}
//colision bloque destructible y upecino
void Controlador::verificar_calision_bloque(int nivel){
	int min = 0;
	int max = 0;
	if (nivel == 1)
	{
		min = 1;
		max = 21;
	}
	if (nivel == 2){
		min = 21;
		max = 41;
	}
	if (nivel == 3){
		min = 41;
		max = 61;
	}
	if (nivel == 4){
		min = 61;
		max = 81;
	}
	for (int i = min; i < max; i++){
		if(obj_upecino->colision_PyU(obj_upecino, obj_arrbloque->arreglo_bloques[i])){
			if (tecla_presionada == Direction::abajo || tecla_presionada == Direction::arriba){
				obj_upecino->SET_x(obj_bloques->GET_x());
			}
			if (tecla_presionada == Direction::derecha || tecla_presionada == Direction::izquierda){
				obj_upecino->SET_y(obj_bloques->GET_y());
			}
		}

	}
}
//====================================================PERSONAJE===========================================
void Controlador::mostrar_enemigo1(Graphics^gr){
	obj_enemigofinal->SET_imagen("itachi.png");
	obj_enemigofinal->mostrar(gr);
}

void Controlador::mostrar_upecino_1(Graphics^gr){
	obj_upecino->SET_imagen("Resources\\img\\sprites\\personaje\\naruto.png");
	obj_upecino->mostrar_Upecino(gr);
}
void Controlador::mostrar_upecino_2(Graphics^gr){
	obj_upecino->SET_imagen("Resources\\img\\sprites\\personaje\\goku.png");
	obj_upecino->mostrar_Upecino(gr);
}
void Controlador::mostrar_upecino_3(Graphics^gr){
	obj_upecino->SET_imagen("Resources\\img\\sprites\\personaje\\bomberman.png");
	obj_upecino->mostrar_Upecino(gr);
}
void Controlador::mostrar_upecino_4(Graphics^gr){
	obj_upecino->SET_imagen("Resources\\img\\sprites\\personaje\\sonic.png");//cambiar
	obj_upecino->mostrar_Upecino(gr);
}
void Controlador::mostrar_upecino_5(Graphics^gr){
	obj_upecino->SET_imagen("Resources\\img\\sprites\\personaje\\ash.png");//cambiar
	obj_upecino->mostrar_Upecino(gr);
}
//====================================================MAPAS===============================================
void Controlador::mostrar_mapa1(Graphics^gr){
	obj_escenas->SET_imagen("Resources\\img\\escenarios\\mapa1.jpg");
	obj_escenas->mostrar(gr);}
void Controlador::mostrar_mapa2(Graphics^gr){
	obj_escenas->SET_imagen("Resources\\img\\escenarios\\mapa2.jpg");	
	obj_escenas->mostrar(gr); }
void Controlador::mostrar_mapa3(Graphics^gr){	
	obj_escenas->SET_imagen("Resources\\img\\escenarios\\mapa3.jpg");
	obj_escenas->mostrar(gr);}
void Controlador::mostrar_mapa4(Graphics^gr){	
	obj_escenas->SET_imagen("Resources\\img\\escenarios\\mapa4.jpg");
	obj_escenas->mostrar(gr);}
void Controlador::mostrar_mapa5(Graphics^gr){
	obj_escenas->SET_imagen("Resources\\img\\escenarios\\mapa5.jpg");
	obj_escenas->mostrar(gr);
}
void Controlador::mostrar_tili(Graphics^gr){
	obj_tili->mostrar_tili(gr);
}
//====================================================INICIO==============================================
void Controlador::mostrar_intro(Graphics^gr){
	obj_escenas->SET_imagen("Resources\\img\\escenarios\\intro.jpg");
	obj_escenas->mostrar(gr);
}
void Controlador::mostrar_puntuacion(Graphics^gr){
	obj_escenas->SET_imagen("puntuacion.jpg"); 
	obj_escenas->mostrar(gr); }
void Controlador::mostrar_instrucciones(Graphics^gr){	
	obj_escenas->SET_imagen("Resources\\img\\escenarios\\bomberman.jpg");
	obj_escenas->mostrar(gr);}
void Controlador::mostrar_ranking(Graphics^gr){
	obj_escenas->SET_imagen("Resources\\img\\escenarios\\introduccion.jpg");
	obj_escenas->mostrar(gr);}
void Controlador::mostrar_pausa(Graphics^gr){	
	obj_escenas->SET_imagen("Resources\\img\\escenarios\\pause.jpg");	
	obj_escenas->mostrar(gr);}
void Controlador::mostrar_eleccion(Graphics^gr){
	obj_escenas->SET_imagen("Resources\\img\\escenarios\\elegir.png");
	obj_escenas->mostrar(gr);}


void Controlador::mover_personaje(Direction tecla_presionada){
	if (tecla_presionada == Direction::abajo)
		obj_upecino->mover_Upecino(Direction::abajo);
	if (tecla_presionada == Direction::izquierda)
		obj_upecino->mover_Upecino(Direction::izquierda);
	if (tecla_presionada == Direction::arriba)
		obj_upecino->mover_Upecino(Direction::arriba);
	if (tecla_presionada == Direction::derecha)
		obj_upecino->mover_Upecino(Direction::derecha);
}



void Controlador::accionar(Graphics^gr,botones acciones_tecla){


	if (inicio_del_juego == false){

		mostrar_intro(gr);

		if (acciones_tecla == botones::enter){
			mostrar_eleccion(gr);
		}
		else if (acciones_tecla == botones::i){
			mostrar_instrucciones(gr);
		}
		else if (acciones_tecla == botones::r){
		    mostrar_ranking(gr);
		}
		else if (acciones_tecla == botones::f12){
			mostrar_pausa(gr);
		}
		if (acciones_tecla == botones::esc){
			exit(0);
		}


		if (acciones_tecla == botones::g){
			//bomberman rojo
			personaje = 1;

			// Variables de inicio de juego
			inicio_del_juego = true;
			id_escenas = 1;
			tiempoNivel = 0;
		}

		if (acciones_tecla == botones::h){
			//bomberman blanco
			personaje = 2;

			// Variables de inicio de juego
			inicio_del_juego = true;
			id_escenas = 1;
		}
		if (acciones_tecla == botones::j){
			//bomberman rojo
			personaje = 3;

			// Variables de inicio de juego
			inicio_del_juego = true;
			id_escenas = 1;
		}

		if (acciones_tecla == botones::k){
			//bomberman blanco
			personaje = 4;

			// Variables de inicio de juego
			inicio_del_juego = true;
			id_escenas = 1;
		}
		if (acciones_tecla == botones::l){
			//bomberman blanco
			personaje = 5;

			// Variables de inicio de juego
			inicio_del_juego = true;
			id_escenas = 1;
		}
	}
	else
		if (acciones_tecla == botones::d1){
				id_escenas = 1;
				tiempoNivel = 0;
				
				
		}
	    if (acciones_tecla == botones::d2){

				id_escenas = 2;
				tiempoNivel = 0;
				obj_upecino->SET_x(40);
				obj_upecino->SET_y(40);
	    }
	    if (acciones_tecla == botones::d3){			
				id_escenas = 3;
				tiempoNivel = 0;
				
	    }
	    if (acciones_tecla == botones::d4){
				id_escenas = 4;
				tiempoNivel = 0;
				
	    }
		if (acciones_tecla == botones::d5){
			id_escenas = 5;
			tiempoNivel = 0;
		}
		
		//========================================================================
		// ESCENA -> MAPA GENERAL
		if (id_escenas == 1){

			tiempoNivel ++;
			mostrar_mapa1(gr);
			//persoanje===========
			if (personaje == 1)
			{
				mostrar_upecino_1(gr);
			}
			else if (personaje == 2){
				mostrar_upecino_2(gr);
			}
			else if (personaje == 3){
				mostrar_upecino_3(gr);
			}
			else if (personaje == 4){
				mostrar_upecino_4(gr);
			}
			else if (personaje == 5){
				mostrar_upecino_5(gr);
			}
			//====================
			destruir_upecino(1);
			mostrar_tili(gr);
			if (acciones_tecla == botones::esc){
				exit(0);
			}
		}
		else if (id_escenas == 2){

			tiempoNivel++;
			mostrar_mapa2(gr);
			//persoanje===========
			if (personaje == 1)
			{
				mostrar_upecino_1(gr);
			}
			else if (personaje == 2){
				mostrar_upecino_2(gr);
			}
			else if (personaje == 3){
				mostrar_upecino_3(gr);
			}
			else if (personaje == 4){
				mostrar_upecino_4(gr);
			}
			else if (personaje == 5){
				mostrar_upecino_5(gr);
			}
			verificar_calision_bloque(2);
			destruir_upecino(2);
			if (acciones_tecla == botones::esc){
				exit(0);
			}
			//====================			
		}
		else if (id_escenas == 3){
			tiempoNivel++;
			mostrar_mapa3(gr);
			//persoanje===========
			if (personaje == 1)
			{
				mostrar_upecino_1(gr);
			}
			else if (personaje == 2){
				mostrar_upecino_2(gr);
			}
			else if (personaje == 3){
				mostrar_upecino_3(gr);
			}
			else if (personaje == 4){
				mostrar_upecino_4(gr);
			}
			else if (personaje == 5){
				mostrar_upecino_5(gr);
			}
			verificar_calision_bloque(3);
			destruir_upecino(3);
			if (acciones_tecla == botones::esc){
				exit(0);
			}
			//====================

			
		}
		else if (id_escenas == 4){
			tiempoNivel++;
			mostrar_mapa4(gr);
			//persoanje===========
			if (personaje == 1)
			{
				mostrar_upecino_1(gr);
			}
			else if (personaje == 2){
				mostrar_upecino_2(gr);
			}
			else if (personaje == 3){
				mostrar_upecino_3(gr);
			}
			else if (personaje == 4){
				mostrar_upecino_4(gr);
			}
			else if (personaje == 5){
				mostrar_upecino_5(gr);
			}
			verificar_calision_bloque(4);
			destruir_upecino(4);
			if (acciones_tecla == botones::esc){
				exit(0);
			}
			//====================
		}
		else if (id_escenas == 5){
			tiempoNivel++;
			mostrar_mapa5(gr);
			//persoanje===========
			if (personaje == 1)
			{
				mostrar_upecino_1(gr);
			}
			else if (personaje == 2){
				mostrar_upecino_2(gr);
			}
			else if (personaje == 3){
				mostrar_upecino_3(gr);
			}
			else if (personaje == 4){
				mostrar_upecino_4(gr);
			}
			else if (personaje == 5){
				mostrar_upecino_5(gr);
			}
			destruir_upecino(5);
			mostrar_enemigo1(gr);
		}
	
}