#ifndef SOUNDGRAPHIC_H
#define SOUNDGRAPHIC_H

//#include "BatallaNaval.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include <allegro.h>

#include <ctime>
#include <cstdio>

class SoundGraphic{
    private:
    BITMAP *bufer;
    BITMAP *cursor;


    int opcion;
    SAMPLE *Block;
    SAMPLE *MenuS;
    BITMAP *fondo ;
    BITMAP *fondo1 ;
    BITMAP *fondo2 ;
    BITMAP *fondo3;
    BITMAP *fondo4 ;
    BITMAP *fondo5 ;
    BITMAP *fondo6 ;
    BITMAP *fondo7 ;
//    BatallaNaval *batleship;

	public:
    enum Vistas{INICIO,JUGAR,ACERCA,MANUAL,FIN,ERROR};

    enum VistasM{CAPITULO1,CAPITULO2,CAPITULO3,CAPITULO4};
    Vistas Vista;
    VistasM Manual;
    bool salida;

	SoundGraphic(int viewportW,int viewportH,int soundVolume, int musicVolume){

        //install_allegro (SYSTEM_AUTODETECT, &errno, atexit);
        allegro_init();

        //configurando intefaces graficas
        int depth = desktop_color_depth();
        if (depth == 0)
        {
            depth=32;
        }
        set_color_depth(depth);
        set_gfx_mode(GFX_AUTODETECT_WINDOWED, viewportW, viewportH, 0, 0);

        //configurando sonido
        if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
            allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
        }
        set_volume(soundVolume, musicVolume);

        set_window_title ("¡Reglas de Allegro!");

        //configurando entradas y salidas
        install_mouse();
        install_keyboard();

        bufer = create_bitmap(640,640);
        cursor = load_bitmap("img/cursor.bmp",NULL);

        batleship=new BatallaNaval();
        Block=load_sample("sound/block.wav");
        bufer = create_bitmap(640,640);
        MenuS=load_sample("sound/menu.wav");
        cursor = load_bitmap("img/cursor.bmp",NULL);

        Vista=INICIO;
        Manual=CAPITULO1;
        play_sample(MenuS , 255, 127, 1000, 1);
    }

//	void run(){
//		switch(Vista){
//				case INICIO:
//                Manual=CAPITULO1;
//				inicio();
//    			break;
//
//				case JUGAR:
//                Manual=CAPITULO1;
//
//				jugar();
//				break;
//				case ACERCA:
//                Manual=CAPITULO1;
//                acerca();
//                break;
//				case MANUAL:
//				manual();
//				break;
//				case FIN:
//				return;
//				break;
//				}
//			}
//    void destroy(){
//        destroy_bitmap(fondo);
//		destroy_bitmap(fondo1);
//		destroy_bitmap(fondo2);
//		destroy_bitmap(fondo3);
//		destroy_bitmap(fondo4);
//		destroy_bitmap(fondo5);
//
//			}
//
//	void inicio(){
//        fondo = load_bitmap("img/normal.bmp",NULL);
//        fondo1 = load_bitmap("img/iniciar.bmp",NULL);
//        fondo2 = load_bitmap("img/cargarjuego.bmp",NULL);
//        fondo3= load_bitmap("img/acercadeljuego.bmp",NULL);
//        fondo4 = load_bitmap("img/ayuda.bmp",NULL);
//        fondo5 = load_bitmap("img/salir.bmp",NULL);
//        salida=false;
//
//        while(!salida){
//            clear_bitmap(bufer);
//            if((mouse_x>=118&&mouse_x<=360)&&(mouse_y>=252&&mouse_y<=279)){
//                blit(fondo1,bufer,0,0,0,0,640,640);
//                if(mouse_b & 1){
//                    Vista=JUGAR;
//                    play_sample(Block , 255, 127, 1000, 0);
//                    salida=true;
//                }
//            }else if((mouse_x>=118&&mouse_x<=360)&&(mouse_y>=280&&mouse_y<=305)){
//                blit(fondo2,bufer,0,0,0,0,640,640);
//                if(mouse_b & 1){
//                    Vista=JUGAR;
//                    play_sample(Block , 255, 127, 1000, 0);
//                    batleship->jugar2(CARGAR);
//                    salida=true;
//                }
//            }
//            else if((mouse_x>=118&&mouse_x<=360)&&(mouse_y>=306&&mouse_y<=333)){
//                blit(fondo3,bufer,0,0,0,0,640,640);
//                if(mouse_b & 1){
//                    Vista=ACERCA;
//                    play_sample(Block , 255, 127, 1000, 0);
//                    salida=true;
//                }
//            }
//            else if((mouse_x>=118&&mouse_x<=360)&&(mouse_y>=334&&mouse_y<=360)){
//                blit(fondo4,bufer,0,0,0,0,640,640);
//                if(mouse_b & 1){
//                    Vista=MANUAL;
//                    play_sample(Block , 255, 127, 1000, 0);
//                    salida=true;
//                }
//            }
//            else if((mouse_x>=118&&mouse_x<=360)&&(mouse_y>=360&&mouse_y<=420)){
//                blit(fondo5,bufer,0,0,0,0,640,640);
//                if(mouse_b & 1){
//                    Vista=FIN;
//                    play_sample(Block , 255, 127, 1000, 0);
//                    salida=true;
//                }
//            }
//            else{
//                blit(fondo,bufer,0,0,0,0,640,640);
//            }
//            masked_blit(cursor,bufer,0,0,mouse_x,mouse_y,13,22);
//           blit(bufer,screen,0,0,0,(SCREEN_H/2)-245,640,640);
//        }
//        run();
//    }
//
  void jugar(){

    fondo = load_bitmap("img/iniciomenu.bmp",NULL);
    fondo1 = load_bitmap("img/inicioindividual.bmp",NULL);
    fondo2 = load_bitmap("img/iniciodosjugadores.bmp",NULL);
    fondo3= load_bitmap("img/inicioregresar.bmp",NULL);
    salida=false;

    while(!salida){
        clear_bitmap(bufer);
        if((mouse_x>=160&&mouse_x<=312)&&(mouse_y>=280&&mouse_y<=305)){
            blit(fondo1,bufer,0,0,0,0,640,640);
            if(mouse_b & 1){
            std::cout<<"QUESILLO";
//                play_sample(Block , 255, 127, 1000, 0);
//                batleship->jugar2();
//                salida=true;
            }
        }else if((mouse_x>=146&&mouse_x<=333)&&(mouse_y>=308&&mouse_y<=332)){
            blit(fondo2,bufer,0,0,0,0,640,640);
            if(mouse_b & 1){
                play_sample(Block , 255, 127, 1000, 0);
                batleship->jugar2(MULTIJUGADOR);
                salida=true;
            }
        }
        else if((mouse_x>=170&&mouse_x<=294)&&(mouse_y>=333&&mouse_y<=357)){
            blit(fondo3,bufer,0,0,0,0,640,640);
            if(mouse_b & 1){
                Vista=INICIO;
                play_sample(Block , 255, 127, 1000, 0);
                salida=true;
            }
        }
        else{
            blit(fondo,bufer,0,0,0,0,640,640);
        }
        masked_blit(cursor,bufer,0,0,mouse_x,mouse_y,13,22);
        blit(bufer,screen,0,0,0,(SCREEN_H/2)-245,640,640);
    }

    run();
				}
  void manual(){

    switch(Manual){
        case CAPITULO1:
        fondo = load_bitmap("img/ayuda1.bmp",NULL);
        fondo1 = load_bitmap("img/ayuda2.bmp",NULL);
        break;
        case CAPITULO2:
        fondo = load_bitmap("img/ayuda3.bmp",NULL);
        fondo1 = load_bitmap("img/ayuda4.bmp",NULL);
        break;
        case CAPITULO3:
        fondo = load_bitmap("img/ayuda5.bmp",NULL);
        fondo1 = load_bitmap("img/ayuda6.bmp",NULL);
        break;
        case CAPITULO4:
        fondo = load_bitmap("img/ayuda7.bmp",NULL);
        fondo1 = load_bitmap("img/ayuda8.bmp",NULL);
        break;

    }
        salida=false;
        while(!salida){
        clear_bitmap(bufer);

        if((mouse_x>=550&&mouse_x<=619)&&(mouse_y>=385&&mouse_y<=425)){
            blit(fondo1,bufer,0,0,0,0,640,640);
            if(mouse_b & 1){
                play_sample(Block , 255, 127, 1000, 0);
                switch(Manual){
                    case CAPITULO1:
                        Manual=CAPITULO2;
                        salida=true;
                        break;

                    case CAPITULO2:
                        Manual=CAPITULO3;
                        salida=true;
                        break;

                    case CAPITULO3:
                        Manual=CAPITULO4;
                        salida=true;
                        break;

                    case CAPITULO4:
                        Vista=INICIO;
                        salida=true;
                        break;

                }
            rest(250);
            }
        }
        else{
            blit(fondo,bufer,0,0,0,0,640,640);
        }
        masked_blit(cursor,bufer,0,0,mouse_x,mouse_y,13,22);
        blit(bufer,screen,0,0,0,(SCREEN_H/2)-245,640,640);
        }
    run();
				}
 void acerca(){
    fondo = load_bitmap("img/acercadeljuego1.bmp",NULL);
    fondo1 = load_bitmap("img/acercadeljuego2.bmp",NULL);
    salida=false;

    while(!salida){
        clear_bitmap(bufer);
        if((mouse_x>=550&&mouse_x<=619)&&(mouse_y>=385&&mouse_y<=425)){
            blit(fondo1,bufer,0,0,0,0,640,640);
            if(mouse_b & 1){
                Vista=INICIO;
                play_sample(Block , 255, 127, 1000, 0);
                salida=true;
            }
        }
        else{
            blit(fondo,bufer,0,0,0,0,640,640);
        }
        masked_blit(cursor,bufer,0,0,mouse_x,mouse_y,13,22);
        blit(bufer,screen,0,0,0,(SCREEN_H/2)-245,640,640);
    }

    run();
				}
	};

#endif
