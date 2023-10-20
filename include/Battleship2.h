#include <iostream>
#include <cstdlib>
#include <cstdio>

#include <string>

enum VistasJ{SELECCION, JUGARCPU, MULTIPLAYER};
VistasJ ModoDJuego;

class Battleship {
private:
	enum Modos { MANUAL,AUTOMATICO };

	struct barco {
		int tamano[3];
		int direccion;
		int coordenadas[2];
	};
	struct casilla {
		int barco;
		int atacado;
	};

	int opcion;
	int error = 0;
	int repetir = 1;
	int limites[2];
	int victorias;
	int derrotas;
	int puntuacion;
	casilla tableroJ[10][10];
	casilla tableroCPU[10][10];
	barco flotaJ[10];
	barco flotaCPU[10];

    BITMAP *buffer = create_bitmap(800,530);

   BITMAP *fondo ;
    BITMAP *fondo1 ;
    BITMAP *fondo2 ;
    BITMAP *fondo3;
    BITMAP *fondo4 ;
    BITMAP *fondo5 ;

    BITMAP *cursor = load_bitmap("img/cursor.bmp",NULL);

public:
	Battleship() {

		puntuacion = derrotas = victorias = 0;
	}

//	void inicio(){
//        fondo = load_bitmap("img/iniciomenu.bmp",NULL);
//        fondo1 = load_bitmap("img/inicioindividual.bmp",NULL);
//        fondo2 = load_bitmap("img/iniciodosjugadores.bmp",NULL);
//        fondo3= load_bitmap("img/inicioregresar.bmp",NULL);
//        bool salida=false;
//
//        while(!salida){
//            if((mouse_x>=160&&mouse_x<=312)&&(mouse_y>=348&&mouse_y<=380)){
//                blit(fondo1,buffer,0,0,0,0,800,530);
//                if(mouse_b & 1){
//                    ModoDJuego=JUGARCPU;
//                    salida=true;
//                }
//            }else if((mouse_x>=146&&mouse_x<=333)&&(mouse_y>=386&&mouse_y<=412)){
//                blit(fondo2,buffer,0,0,0,0,800,530);
//                if(mouse_b & 1){
//                    ModoDJuego=MULTIPLAYER;
//                    salida=true;
//                }
//            }
//            else if((mouse_x>=170&&mouse_x<=294)&&(mouse_y>=413&&mouse_y<=445)){
//                blit(fondo3,buffer,0,0,0,0,800,530);
//                if(mouse_b & 1){
//                    salida=true;
//
//                    return;
//                }
//            }
//            else{
//                blit(fondo,buffer,0,0,0,0,800,530);
//            }
//            masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
//            blit(buffer,screen,0,0,0,0,800,530);
//        }
//    }

	void jugarCpu() {
		inicializar();
	}
	void reseteo(casilla tablero[10][10]) {
		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				tablero[x][y].barco = 0;
				tablero[x][y].atacado = 0;
			}
		}
	}
	void mostrarTablero(casilla tablero[10][10],const char nombre[10]) {
		std::cout << "[----------"<<nombre<<"----------]" << std::endl;
		for (int x = 0; x < 10; x++) {
			std::cout << "[";
			for (int y = 0; y < 10; y++) {
				std::cout<<" "<<tablero[x][y].barco<<" ";
			}
			std::cout << "]"<< std::endl;
		}
		std::cout << "[----------" << nombre << "----------]" << std::endl;
	}
	void colocarBarcos(Modos Modo,barco flota[10], casilla tablero[10][10], const char nombre[10]) {
		reseteo(tablero);
		mostrarTablero(tablero,nombre);
		for (int i = 0; i <= 9; i++) {
			do {
				error = 0;
			switch (Modo)
			{
			case MANUAL:
				std::cout << "Ingresa una de las siguientes opciones\n";
				std::cout << "1 Para Un buque minero que ocupa 2 cuadrados del tablero.\n";
				std::cout << "2 Para Un submarino que ocupa 3 cuadrados del tablero.\n";
				std::cout << "3 Para Una fragata que ocupa 3 cuadrados del tablero.\n";
				std::cout << "4 Para Un acorazado, que ocupa 4 cuadrados del tablero.\n";
				std::cout << "5 Un portaaviones, que ocupa 5 cuadrados del tablero.\n";
				std::cin >> opcion;
				break;
			case AUTOMATICO:
				opcion=(rand()%5)+1;
				break;
			}

			switch (opcion) {
			case 1:
				flota[i].tamano[2] = 2;
				break;

			case 2:
				flota[i].tamano[2] = 3;
				break;

			case 3:
				flota[i].tamano[2] = 3;
				break;

			case 4:
				flota[i].tamano[2] = 4;
				break;

			case 5:
				flota[i].tamano[2] = 5;
				break;

			default:
				error = 1;
			}
			} while (error);
			do {
				error = 0;
				switch (Modo)
				{
				case MANUAL:
					std::cout << "Ingresa una de las siguientes opciones\n";
					std::cout << "1 para colocar el barco horizontalmente.\n";
					std::cout << "2 para colocar el barco verticalmente.\n";

					std::cin >> opcion;
					break;
				case AUTOMATICO:
					opcion = (rand() % 2) + 1;
					break;
				}

				switch (opcion) {
				case 1:
					flota[i].direccion = 1;
					flota[i].tamano[0] = flota[i].tamano[2];
					flota[i].tamano[1] = 1;

					break;
				case 2:
					flota[i].direccion = 2;
					flota[i].tamano[0] = 1;
					flota[i].tamano[1] = flota[i].tamano[2];

					break;
				default:
					error = 1;
				}
			} while (error);
			limites[0] = 9 - (flota[i].tamano[0] - 1);
			limites[1] = 9 - (flota[i].tamano[1] - 1);
			do {
				error = 0;
				do {
					switch (Modo)
					{
					case MANUAL:
						std::cout << "Ingresa la coordenada en x\n";
						std::cin >> opcion;
						break;
					case AUTOMATICO:
						opcion = (rand() % (limites[0]+1));
						break;
					}
				} while (opcion > limites[0]);
				flota[i].coordenadas[0] = opcion;
				do {
					switch (Modo)
					{
					case MANUAL:
						std::cout << "Ingresa la coordenada en y\n";
						std::cin >> opcion;
						break;
					case AUTOMATICO:
						opcion = (rand() % (limites[1] + 1));
						break;
					}
				} while (opcion > limites[1]);
				flota[i].coordenadas[1] = opcion;
				escanear(flota[i], tablero);
				if (!error)
				{
					colocarBarco(flota[i], tablero);
					mostrarTablero(tablero,nombre);
				}
			} while (error);
		}
	}
	void inicializar() {
		colocarBarcos(AUTOMATICO,flotaJ,tableroJ,"israelD");
		colocarBarcos(AUTOMATICO, flotaCPU, tableroCPU,"compu");
		do{
			disparar(AUTOMATICO, tableroCPU, "CPU");
			termino(tableroCPU);
			if (!repetir)
			{
				std::cout<<"El jugador"<<repetir<<" ah ganado pero si la pc acierta en su ultimo ataque puede empatar";
				disparar(AUTOMATICO, tableroJ, "israelD");
				termino(tableroJ);
				if (repetir)
				{
					std::cout << "Ha habido un empate";
				}
				else
				{
					std::cout << "El jugador" << repetir << "ah ganado";
					break;
				}
			}
			disparar(AUTOMATICO, tableroJ, "israelD");
			termino(tableroJ);
			if (!repetir)
			{
				std::cout << "El jugador" << repetir << " ah ganado pero si la pc acierta en su ultimo ataque puede empatar";
				disparar(AUTOMATICO, tableroCPU, "CPU");
				termino(tableroCPU);
				if (repetir)
				{
					std::cout << "Ha habido un empate";
				}
				else
				{
					std::cout << "El jugador"<<repetir<<"ah ganado";
					break;
				}
			}
		} while (repetir);


	}
	void escanear(barco flota, casilla tablero[10][10]) {
		for (int y = flota.coordenadas[0]; y <= flota.coordenadas[0] + (flota.tamano[0] - 1); y++) {
			for (int x = flota.coordenadas[1]; x <= flota.coordenadas[1] + (flota.tamano[1] - 1); x++) {
				if (tablero[x][y].barco != 0) {
					std::cout << "La posicion esta ocupada\n";
					error = 1;
				}
			}
		}
	}
	void colocarBarco(barco flota,casilla tablero[10][10]) {
		for (int y = flota.coordenadas[0]; y <= flota.coordenadas[0] + (flota.tamano[0] - 1); y++) {
			for (int x = flota.coordenadas[1]; x <= flota.coordenadas[1] + (flota.tamano[1] - 1); x++) {
					tablero[x][y].barco = flota.tamano[2];
			}
		}
	}
	void termino(casilla tablero[10][10]) {
		repetir = 0;
		for (int y = 0; y <=9; y++) {
			for (int x = 0; x <= 9; x++) {
				if (tablero[x][y].barco != 0) {
					if (!tablero[x][y].atacado) {
						repetir = 1;
					}
				}
			}
		}
	}
	void disparar(Modos Modo,casilla tablero[10][10],const char nombre[10]) {
		int x, y;
		switch (Modo)
		{
		case Battleship::MANUAL:
			do {
				std::cout << "Elige una coordenada en x para disparar";
				std::cin >> x;
			} while (x > 9);
			do {
				std::cout << "Elige una coordenada en y para disparar";
				std::cin >> y;
			} while (y > 9);
			break;
		case Battleship::AUTOMATICO:
			x=rand()%10;
			y=rand()%10;
			break;
		}
				tablero[y][x].atacado=1;
				tablero[y][x].barco =00;
				mostrarTablero(tablero,nombre);
	}
};
#pragma once
