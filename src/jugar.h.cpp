//#include <iostream>
//#include <cstdlib>
//#include <cstdio>
//#include <string>
//
//#include <allegro.h>
//#include "inicia.h"
//
//#define maxfil 11
//#define maxcolm 11
//
//BITMAP *fondo;
//BITMAP *buffer;
//BITMAP *cursor;
//BITMAP *anuncio;
//
//BITMAP *tablero1BTM;
//BITMAP *tablero2BTM;
//BITMAP *oceano;
//BITMAP *explosion;
//BITMAP *fallo;
//BITMAP *barcobmp;
//BITMAP *barco;
//
//BITMAP *buqueM;
//BITMAP *submarino;
//BITMAP *fragata;
//BITMAP *acorazado;
//BITMAP *portaA;
//
//BITMAP *disparoF;
//BITMAP *menu;
//
//
//enum direccion{HORIZONTAL,VERTICAL};
//
//enum Modos { MANUAL,AUTOMATICO };
//enum Juego { SOLITARIO,MULTIJUGADOR };
//
//struct barcoS {
//        char nombre[15]="";
//		int tamano[3];
//		direccion dir;
//		int coordenadas[2];
//		BITMAP *mapaDBits;
//		BITMAP *mapaDBits2;
//	};
//barcoS flotaJ[5];
//barcoS flotaCPU[5];
//
//struct casilla {
// //   int *barco;
//    int atacado;
//    char estado[15];
//};
//casilla tableroJ[10][10];
//casilla tableroCPU[10][10];
//
//char texto[200]="";
//
//direccion dir=HORIZONTAL;
//Modos Modo;
//Juego ModoDJ=SOLITARIO;
//
//
//int selec1=0;
//int selec2=0;
//int selec3=0;
//int selec4=0;
//int selec5=0;
//
//int cont=0;
//int repetir;
//
//int px=0;
//int py=0;
//
//void reseteo(casilla tablero[10][10]);
//void escribir();
//void setTexto(char texto1[100]);
//void setTexto( char texto1[100], char texto2[100]);
//
//void dibujarOceano(casilla tablero1[10][10],BITMAP *tablero1BTM,int x,int y);
//void mostrarTablero(casilla tablero[10][10],const char nombre[10]);
//
//void dibujarBarcos(barcoS flota[5],BITMAP *tableroBTM,int x,int y);
//void dibujarMenu();
//
//void dibujarAnuncio(BITMAP *mapaDbits);
//
//void colocacion(barcoS flota[5],casilla tablero[10][10],BITMAP *tablero1BTM,int x1,int y1);
//
//void seleccion(barcoS flota[5]);
//
//int seleccionHidden(barcoS flota[5]);
//
//void colocacionHidden(barcoS flota[5],casilla tablero1[10][10]);
//
//void dibujarBarco(barcoS flota[5],BITMAP *tablero1BTM);
//
//int escanear(barcoS flota, casilla tablero[10][10]);
//
//void dibujarConPuntero(BITMAP *barco);
//
//void dibujarPuntero();
//int jugar2();
//
//void reseteo(casilla tablero[10][10]) {
//    for (int x = 0; x < 10; x++) {
//        for (int y = 0; y < 10; y++) {
//            strcpy(tablero[x][y].estado,"0");
//        }
//    }
//}
//void escribir(){
//textout(buffer, font,texto,0,5,makecol(255,255,255));
//
//}
//void setTexto(char texto1[100]){
//strcpy(texto,"");
//strcpy(texto,texto1);
//}
//void setTexto( char texto1[100], char texto2[100]){
//strcpy(texto,"");
//strcat(texto,texto1);
//strcat(texto,texto2);
//
//}
//
//void dibujarOceano(casilla tablero1[10][10],BITMAP *tablero1BTM,int x,int y){
//    for(int fila=0;fila<maxfil-1;fila++){
//        for(int columna=0;columna<maxcolm-1;columna++){
//
//                draw_sprite(tablero1BTM,oceano,columna*30,fila*30);
//
//            if(strcmp(tablero1[fila][columna].estado,"X")==0){
//                draw_sprite(tablero1BTM,explosion,columna*30,fila*30);
//            }
//            if(strcmp(tablero1[fila][columna].estado,"F")==0){
//                draw_sprite(tablero1BTM,fallo,columna*30,fila*30);
//            }
//        }
//    }
//   blit(tablero1BTM,buffer,0,0,x,y,300,300);
//}
//	void mostrarTablero(casilla tablero[10][10],const char nombre[10]) {
//		std::cout << "[----------"<<nombre<<"----------]" << std::endl;
//		for (int x = 0; x < 10; x++) {
//			std::cout << "[";
//			for (int y = 0; y < 10; y++) {
//				std::cout<<" "<<tablero[x][y].estado<<" ";
//			}
//			std::cout << "]"<< std::endl;
//		}
//		std::cout << "[----------" << nombre << "----------]" << std::endl;
//	}
//void dibujarBarcos(barcoS flota[5],BITMAP *tableroBTM,int x,int y){
//    for(int i=0;i<5;i++){
//        if(flota[i].tamano[0]>0 && flota[i].tamano[1]>0){
//            if(flota[i].dir==HORIZONTAL){
//                draw_sprite(tableroBTM,flota[i].mapaDBits,flota[i].coordenadas[0]*30,flota[i].coordenadas[1]*30);
//            }else{
//                rotate_sprite(tableroBTM,flota[i].mapaDBits,(flota[i].coordenadas[0]*30-(30*flota[i].tamano[1]/2)+15),(flota[i].coordenadas[1]*30+(30*flota[i].tamano[1]/2)-15),itofix(64));
//            }
//        }
//    }
//   blit(tableroBTM,buffer,0,0,x,y,300,300);
//}
//
//void dibujarMenu(){
//draw_sprite(menu,buqueM,0,0);
//draw_sprite(menu,submarino,210,0);
//draw_sprite(menu,fragata,105,30);
//draw_sprite(menu,acorazado,90,60);
//draw_sprite(menu,portaA,75,90);
//blit(menu,buffer,0,0,0,(SCREEN_H-120),300,120);
//
//}
//
//void dibujarAnuncio(BITMAP *mapaDbits){
//draw_sprite(screen,mapaDbits,SCREEN_W/2-150,SCREEN_H/2-54);
//rest(1500);
//
//}
//
//void colocacion(barcoS flota[5],casilla tablero[10][10],BITMAP *tablero1BTM,int x1,int y1){
//
//        if(dir==HORIZONTAL){
//            flota[cont].tamano[0]=flota[cont].tamano[2];
//            flota[cont].tamano[1]=1;
//        }else{
//            flota[cont].tamano[0]=1;
//            flota[cont].tamano[1]=flota[cont].tamano[2];
//        }
//        if(px<0){px=0;}
//        if(py<0){py=0;}
//        if(px>(9-flota[cont].tamano[0]+1)){px=(9-flota[cont].tamano[0]+1);}
//        if(py>(9-flota[cont].tamano[1]+1)){py=(9-flota[cont].tamano[1]+1);}
//
//        if(key[KEY_RIGHT]){
//                    if(px+1<=(9-flota[cont].tamano[0]+1)){
//                    dir=HORIZONTAL;
//                    }
//        }
//        if(key[KEY_LEFT]){
//                if(py+1<=(9-flota[cont].tamano[1]+1)){
//                    dir=VERTICAL;
//                    }
//        }
//        flota[cont].dir=dir;
//        flota[cont].coordenadas[0]=px;
//        flota[cont].coordenadas[1]=py;
//        int ocupado=escanear(flota[cont],tablero);
//        if(ocupado){
//           setTexto("Esta ocupada la posicion");
//        }
//
//
//        if((mouse_b & 1)&&is_inside_bitmap ( tablero1BTM, (mouse_x-x1), (mouse_y-y1), 1)||(Modo==AUTOMATICO)){
//
//            if(!ocupado){
//                if(strcmp(flota[cont].nombre,"Buque Minero")==0){
//                selec1=1;
//                }else if(strcmp(flota[cont].nombre,"Submarino")==0){
//                selec2=1;
//                }else if(strcmp(flota[cont].nombre,"Fragata")==0){
//                selec3=1;
//                }else if(strcmp(flota[cont].nombre,"Acorazado")==0){
//                selec4=1;
//                }else if(strcmp(flota[cont].nombre,"Porta Aviones")==0){
//                selec5=1;
//                }
//
//            for(int fila=0;fila<flota[cont].tamano[1];fila++){
//                for(int columna=0;columna<flota[cont].tamano[0];columna++){
//
//                        strcpy(tablero[py+fila][px+columna].estado,flota[cont].nombre);
//
//                }
//            }
//            cont++;
//            mostrarTablero(tablero,"Israel");
//
//           }
//        }
//std::cout<<"(";
//std::cout<<px;
//std::cout<<",";
//std::cout<<py;
//std::cout<<")";
//}
//
//void seleccion(barcoS flota[5]){
//    setTexto("");
//
//    if(is_inside_bitmap (menu, mouse_x, mouse_y-(SCREEN_H-120), 1)){
//        if((((mouse_x>=0 && mouse_x<=60)&&(mouse_y>=SCREEN_H-120 && mouse_y<= SCREEN_H-90)))&& !selec1){
//            if(mouse_b  & 1){
//
//                strcpy(flota[cont].nombre,"Buque Minero");
//                flota[cont].tamano[2]=2;
//                if(Modo==MANUAL){
//                flota[cont].mapaDBits=buqueM;
//                flota[cont].mapaDBits2=load_bitmap("img/elbuque.bmp",NULL);
//                barco=load_bitmap("img/buqueT.bmp",NULL);
//                }
//                rest(500);
//
//
//            }
//       }else if((((mouse_x>=210&&mouse_x<=300)&&(mouse_y>=(SCREEN_H-120)&&mouse_y<=(SCREEN_H-90))))&& !selec2){
//            if((mouse_b  & 1)){
//
//                strcpy(flota[cont].nombre,"Submarino");
//                flota[cont].tamano[2]=3;
//                if(Modo==MANUAL){
//                flota[cont].mapaDBits=submarino;
//                flota[cont].mapaDBits2=load_bitmap("img/elsubmarino.bmp",NULL);
//                barco=load_bitmap("img/submarinoT.bmp",NULL);
//                }
//                rest(500);
//
//
//            }
//        }
//        else if((((mouse_x>=105&&mouse_x<=195)&&(mouse_y>=(SCREEN_H-90)&&mouse_y<=(SCREEN_H-60))))&& !selec3){
//            if((mouse_b  & 1)){
//
//                strcpy(flota[cont].nombre,"Fragata");
//                flota[cont].tamano[2]=3;
//                if(Modo==MANUAL){
//                flota[cont].mapaDBits=fragata;
//                flota[cont].mapaDBits2=load_bitmap("img/elfragata.bmp",NULL);
//                barco=load_bitmap("img/fragataT.bmp",NULL);
//                }
//                rest(500);
//
//
//            }
//        }
//        else if((((mouse_x>=90&&mouse_x<=210)&&(mouse_y>=SCREEN_H-60&&mouse_y<=SCREEN_H-30)))&& !selec4){
//            if(mouse_b  & 1){
//
//                strcpy(flota[cont].nombre,"Acorazado");
//                flota[cont].tamano[2]=4;
//                if(Modo==MANUAL){
//                flota[cont].mapaDBits=acorazado;
//                flota[cont].mapaDBits2=load_bitmap("img/elacorazado.bmp",NULL);
//                barco=load_bitmap("img/acorazadoT.bmp",NULL);
//                }
//                rest(500);
//
//
//            }
//        }
//        else if((((mouse_x>=75&&mouse_x<=225)&&(mouse_y>=(SCREEN_H-30)&&mouse_y<=(SCREEN_H)))&& !selec5)){
//            if((mouse_b  & 1)){
//
//                strcpy(flota[cont].nombre,"Porta Aviones");
//                flota[cont].tamano[2]=5;
//                if(Modo==MANUAL){
//                flota[cont].mapaDBits=portaA;
//                flota[cont].mapaDBits2=load_bitmap("img/elportaaviones.bmp",NULL);
//                barco=load_bitmap("img/portaT.bmp",NULL);
//
//                }
//                rest(500);
//
//
//            }
//        }
//    }
//if(strcmp(flota[cont].nombre,"")!=0){
//        setTexto("Haz seleccionado ",flota[cont].nombre);
//}
//}
//
//int seleccionHidden(barcoS flota[5]){
//
//    switch(cont){
//    case 0:
//    strcpy(flota[cont].nombre,"Buque Minero");
//    flota[cont].mapaDBits=buqueM;
//    flota[cont].mapaDBits2=load_bitmap("img/elbuque.bmp",NULL);
//    flota[cont].tamano[2]=2;
//    return 1;
//    break;
//    case 1:
//    strcpy(flota[cont].nombre,"Submarino");
//    flota[cont].mapaDBits=submarino;
//    flota[cont].mapaDBits2=load_bitmap("img/elsubmarino.bmp",NULL);
//    flota[cont].tamano[2]=3;
//    return 1;
//    break;
//    case 2:
//    strcpy(flota[cont].nombre,"Fragata");
//    flota[cont].mapaDBits=fragata;
//    flota[cont].mapaDBits2=load_bitmap("img/elfragata.bmp",NULL);
//    flota[cont].tamano[2]=3;
//    return 1;
//    break;
//    case 3:
//    strcpy(flota[cont].nombre,"Acorazado");
//    flota[cont].mapaDBits=acorazado;
//    flota[cont].mapaDBits2=load_bitmap("img/elacorazado.bmp",NULL);
//    flota[cont].tamano[2]=4;
//    return 1;
//    break;
//    case 4:
//    strcpy(flota[cont].nombre,"Porta Aviones");
//    flota[cont].mapaDBits=portaA;
//    flota[cont].mapaDBits2=load_bitmap("img/elportaaviones.bmp",NULL);
//    flota[cont].tamano[2]=5;
//    return 1;
//    break;
//    }
//
//return 0;
//}
//
//void colocacionHidden(barcoS flota[5],casilla tablero1[10][10]){
//    int hv=rand()%2;
//
//  if(hv==0){
//            dir=HORIZONTAL;
//            flota[cont].tamano[0]=flota[cont].tamano[2];
//            flota[cont].tamano[1]=1;
//        }else{
//            dir=VERTICAL;
//            flota[cont].tamano[0]=1;
//            flota[cont].tamano[1]=flota[cont].tamano[2];
//        }
//        if(px<0){px=0;}
//        if(py<0){py=0;}
//
//        if(px>(9-flota[cont].tamano[0]+1)){px=(9-flota[cont].tamano[0]+1);}
//        if(py>(9-flota[cont].tamano[1]+1)){py=(9-flota[cont].tamano[1]+1);}
//
//        flota[cont].dir=dir;
//        flota[cont].coordenadas[0]=px;
//        flota[cont].coordenadas[1]=py;
//        int ocupado=escanear(flota[cont],tablero1);
//        if(ocupado){
//           setTexto("Esta ocupada la posicion");
//        }
//
//           if(!ocupado){
//            for(int fila=0;fila<flota[cont].tamano[1];fila++){
//                for(int columna=0;columna<flota[cont].tamano[0];columna++){
//
//                    strcpy(tablero1[py+fila][px+columna].estado,flota[cont].nombre);
//                }
//            }
//
//            mostrarTablero(tablero1,"Israel");
//            cont++;
//
//        }
//}
//
//
//
//
//void dibujarBarco(barcoS flota[5],BITMAP *tablero1BTM){
//
//    switch(dir){
//        case HORIZONTAL:
//        draw_sprite(tablero1BTM,barco,px*30,py*30);
//        break;
//        case VERTICAL:
//        rotate_sprite(tablero1BTM,barco,(px*30-(30*flota[cont].tamano[1]/2)+15),(py*30+(30*flota[cont].tamano[1]/2)-15), itofix(64));
//        break;
//    }
//}
//
//int escanear(barcoS flota, casilla tablero[10][10]) {
//    int pOcupadas=0;
//    for (int y = flota.coordenadas[0]; y <= flota.coordenadas[0] + (flota.tamano[0] - 1); y++) {
//        for (int x = flota.coordenadas[1]; x <= flota.coordenadas[1] + (flota.tamano[1] - 1); x++) {
//            if (strcmp(tablero[x][y].estado,"0")!=0 && strcmp(tablero[x][y].estado,"X")!=0) {
//                pOcupadas++;
//            }
//        }
//    }
//    return pOcupadas;
//}
//
//void dibujarConPuntero(BITMAP *barco){
//    masked_blit(barco,tablero2BTM,0,0,px*30,py*30,30,30);
//    blit(tablero2BTM,buffer,0,0,SCREEN_W-300,SCREEN_H-300,300,300);
//}
//
//void dibujarPuntero(){
//    masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
//}
//
//void pantalla(){
//    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
//}
//void cargarImagenes(){
//    anuncio=load_bitmap("img/Averia.bmp",NULL);
//    fondo = load_bitmap("img/fondo.bmp",NULL);
//    cursor = load_bitmap("img/cursor.bmp",NULL);
//    oceano=load_bitmap("img/tableroJ.bmp",NULL);
//    menu=load_bitmap("img/tablero.bmp",NULL);
//    explosion=load_bitmap("img/hundido.bmp",NULL);
//    fallo=load_bitmap("img/fallo.bmp",NULL);
//
//    buqueM=load_bitmap("img/buqueT.bmp",NULL);
//    submarino=load_bitmap("img/submarinoT.bmp",NULL);
//    fragata=load_bitmap("img/fragataT.bmp",NULL);
//    acorazado=load_bitmap("img/acorazadoT.bmp",NULL);
//    portaA=load_bitmap("img/portaT.bmp",NULL);
//
//}
//
//void prepararTablero(Modos Mod1,casilla tableroS[10][10],casilla tableroS2[10][10],BITMAP *tablero1,BITMAP *tablero2,barcoS flota[10],barcoS flota2[10],int x1,int y1,int x2,int y2){
//        cont=0;
//        bool termino=false;
//        Modo=Mod1;
//
//        switch(Modo){
//            case MANUAL:
//                while(!termino){
//                    px=(mouse_x-(x1))/30;
//                    py=(mouse_y-(y1))/30;
//                    blit(fondo,buffer,0,0,0,0,640,640);
//
//                    dibujarMenu();
//                    dibujarOceano(tableroS,tablero1,x1,y1);
//                    dibujarOceano(tableroS2,tablero2,x2,y2);
//                    dibujarBarcos(flota,tablero1,x1,y1);
//
//                    seleccion(flota);
//
//
//                    if(flota[cont].tamano[2]>0){
//                        colocacion(flota,tableroS,tablero1,x1,y1);
//                        dibujarBarco(flota,tablero1);
//
//                    }
//                    escribir();
//                    dibujarPuntero();
//                    pantalla();
//                    if(cont==5){
//                        termino=true;
//                    }
//
//                    rest(70);
//                }
//            break;
//            case AUTOMATICO:
//            cont=0;
//                while(!termino){
//                dibujarOceano(tableroS,tablero1BTM,x1,y1);
//                dibujarOceano(tableroS2,tablero2BTM,x2,y2);
//                dibujarBarcos(flota,tablero1BTM,x1,x1);
//                dibujarPuntero();
//                px=rand()%9;
//                py=rand()%9;
//                seleccionHidden(flota);
//                if(flota[cont].tamano[2]>0){
//                        colocacionHidden(flota,tableroS);
//
//                }
//                if(cont==5){
//                        termino=true;
//                    }
//                pantalla();
//                }
//            break;
//
//
//        }
//
//}
//
//void termino(barcoS flota[5]) {
//		repetir = 0;
//		int navesDestruidas=0;
//		for (int i = 0; i <5; i++) {
//			if(flota[i].tamano[2]==0){
//                navesDestruidas++;
//			}
//		}
//		if(navesDestruidas<5){
//            repetir=1;
//		}
//	}
//
//	void disparar(Modos Modo,casilla tablero1[10][10],casilla tablero2[10][10],BITMAP *tablero1BTM,BITMAP *tablero2BTM,barcoS flota1[5],barcoS flota2[5],int x1,int y1,int x2,int y2) {
//		bool termino=false;
//		setTexto("");
//		switch (Modo)
//		{
//		case MANUAL:
//			while(!termino){
//
//                px=((mouse_x-(x2))/30);
//                py=((mouse_y-(y2))/30);
//
//
//                blit(fondo,buffer,0,0,0,0,640,640);
//                dibujarMenu();
//
//                if(mouse_b  & 1 && is_inside_bitmap(tablero2BTM, mouse_x-(x2), mouse_y-(y2), 1)){
//                    if(!tablero2[py][px].atacado){
//                            int acerto=0;
//                            for(int i=0;i<5;i++){
//                                if(strcmp(tablero2[py][px].estado,flota2[i].nombre)==0){
//                                    flota2[i].tamano[2]-=1;
//                                    acerto+=1;
//                                    dibujarAnuncio(anuncio);
//                                    setTexto("Le disparastes al ",tablero2[py][px].estado);
//                                    if(flota2[i].tamano[2]==0){
//                                        setTexto("Has destruido al  ",tablero2[py][px].estado);
//                                        dibujarAnuncio(flota2[i].mapaDBits2);
//                                    }
//                                }
//
//                            }
//
//                            tablero2[py][px].atacado=1;
//                            if(acerto){
//                                 strcpy(tablero2[py][px].estado,"X");
//                            }else{
//                                strcpy(tablero2[py][px].estado,"F");
//                            }
//
//                            mostrarTablero(tablero2,"CPU");
//                            termino=true;
//
//                    }else{
//                    setTexto("Ya le habias disparado a esta posicion");
//                    }
//                }
//
//                    dibujarOceano(tablero1,tablero1BTM,x1,y1);
//                    dibujarOceano(tablero2,tablero2BTM,x2,y2);
//                    dibujarBarcos(flota1,tablero1BTM,x1,y1);
//
//
//                    escribir();
//                dibujarPuntero();
//                pantalla();
//                }
//			break;
//		case AUTOMATICO:
//
//        while(!termino){
//            blit(fondo,buffer,0,0,0,0,640,640);
//            dibujarMenu();
//			px=rand()%10;
//            py=rand()%10;
//                    if(!tablero2[py][px].atacado){
//                            int acerto=0;
//                            for(int i=0;i<5;i++){
//                                if(strcmp(tablero2[py][px].estado,flota2[i].nombre)==0){
//                                    flota2[i].tamano[2]-=1;
//                                    acerto+=1;
//                                    dibujarAnuncio(anuncio);
//                                    setTexto("Le disparastes al ",tablero2[py][px].estado);
//                                    if(flotaCPU[i].tamano[2]==0){
//                                        setTexto("Has destruido al  ",tablero2[py][px].estado);
//                                        dibujarAnuncio(flota2[i].mapaDBits2);
//                                    }
//                                }
//
//                            }
//
//                            tablero2[py][px].atacado=1;
//                            if(acerto){
//                                 strcpy(tablero2[py][px].estado,"X");
//                            }else{
//                                strcpy(tablero2[py][px].estado,"F");
//                            }
//
//                            mostrarTablero(tablero2,"CPU");
//                            termino=true;
//
//
//                    }else{
//                    setTexto("Ya le habias disparado a esta posicion");
//                    }
//
//                    dibujarOceano(tablero1,tablero1BTM,x1,y1);
//                    dibujarOceano(tablero2,tablero2BTM,x2,y2);
//                    dibujarBarcos(flota1,tablero1BTM,x1,y1);
//
//
//                escribir();
//                dibujarPuntero();
//                pantalla();
//            }
//			break;
//
//        }
//}
//
//	void combate(Modos Modo1,Modos Modo2,casilla tablero1[10][10],casilla tablero2[10][10],char nombre1[10],char nombre2[10]) {
//		do{
//			disparar(Modo1, tablero1,tablero2,tablero1BTM,tablero2BTM,flotaJ,flotaCPU,0,0,SCREEN_W-300,SCREEN_H-300);
//            termino(flotaCPU);
//			if (!repetir)
//			{
//				setTexto("Si el jugador",nombre2);
//				disparar(Modo2, tablero2,tablero1, tablero2BTM,tablero1BTM,flotaCPU,flotaJ,SCREEN_W-300,SCREEN_H-300,0,0);
//				termino(flotaJ);
//				if (!repetir)
//				{
//					setTexto("Ha habido un empate");
//					break;
//				}
//				else
//				{
//					setTexto("Felicidades ganastes: ",nombre1);
//					break;
//
//				}
//			}
//			disparar(Modo2, tablero2,tablero1, tablero2BTM,tablero1BTM,flotaCPU,flotaJ,SCREEN_W-300,SCREEN_H-300,0,0);
//            termino(flotaJ);
//			if (!repetir)
//                            {
//				setTexto("Si el jugador",nombre1);
//				disparar(Modo1, tablero1,tablero2,tablero1BTM,tablero2BTM,flotaJ,flotaCPU,SCREEN_W-300,SCREEN_H-300,0,0);
//                termino(flotaCPU);
//				if (!repetir)
//				{
//					setTexto("Ha habido un empate");
//					break;
//				}
//				else
//				{
//					setTexto("Felicidades ganastes: ",nombre2);
//					break;
//
//				}
//			}
//		} while (repetir);
//    escribir();
//    pantalla();
//
//}
//
//int jugar2 ()
//{   srand(time(NULL));
//
//    buffer = create_bitmap(SCREEN_W,SCREEN_H);
//    tablero1BTM = create_bitmap(300,300);
//    tablero2BTM = create_bitmap(300,300);
//
//    cargarImagenes();
//
//    reseteo(tableroJ);
//    reseteo(tableroCPU);
//
//    switch(ModoDJ){
//        case SOLITARIO:
//            prepararTablero(MANUAL,tableroJ,tableroCPU,tablero1BTM,tablero2BTM,flotaJ,flotaCPU,0,0,SCREEN_W-300,SCREEN_H-300);
//
//            selec1=0;
//            selec2=0;
//            selec3=0;
//            selec4=0;
//            selec5=0;
//
//            prepararTablero(AUTOMATICO,tableroCPU,tableroJ,tablero2BTM,tablero1BTM,flotaCPU,flotaJ,SCREEN_W-300,SCREEN_H-300,0,0);
//
//            mostrarTablero(tableroCPU,"CPU");
//
//            combate(MANUAL,AUTOMATICO,tableroJ,tableroCPU,"Israel David","Cpu");
//            break;
//
//        case MULTIJUGADOR:
//             prepararTablero(MANUAL,tableroJ,tableroCPU,tablero1BTM,tablero2BTM,flotaJ,flotaCPU,0,0,SCREEN_W-300,SCREEN_H-300);
//
//            selec1=0;
//            selec2=0;
//            selec3=0;
//            selec4=0;
//            selec5=0;
//
//            prepararTablero(MANUAL,tableroCPU,tableroJ,tablero2BTM,tablero1BTM,flotaCPU,flotaJ,SCREEN_W-300,SCREEN_H-300,0,0);
//
//            mostrarTablero(tableroCPU,"CPU");
//
//            combate(MANUAL,MANUAL,tableroJ,tableroCPU,"Israel David","JUGADOR2");
//
//            break;
//
//
//    }
//
//
//    rest(50000);
//
//return 0;
//
//}
