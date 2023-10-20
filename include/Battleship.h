#ifndef BATTLESHIP_H
#define BATTLESHIP_H


#include <iostream>
#include <cstdlib>
#include <cstdio>

#include <string>
#include <math.h>

#include <allegro.h>
#include "inicia.h"

#define maxfil 11
#define maxcolm 11
enum Juego { SOLITARIO,MULTIJUGADOR,CARGAR};

enum Dir{NULA,HORIZONTAL,VERTICAL};

enum Modos { MANUAL,AUTOMATICO };

enum  ShipType{ AIRCRAFT_CARRIER,BATTLESHIP,FRIGATE,SUBMARINE,MINING_SHIP};

enum State{NORMAL,EXPLOSION,MISSED_SHOT};

struct Coor{

    int x;
    int y;

};

class Ship {

    public:
        std::string name;
		int size[3];

		int life;

		ShipType type;

		Dir dir;
		Coor coor;

		Ship(const std::string &name,int size,ShipType shipType){

            this->name=name;

            this->type=shipType;

            //size establece los valores de tamaño dependiendo del tipo de barco y la direccion
            //size[0] es el valor horizontal
            //size[1] es el valor vertical
            //size[2] es el valor mas grande entre ambos
                this->size[0]=-1;
                this->size[1]=-1;
                this->size[2]=size;

                this->life=size;

                dir=NULA;

            coor.x=-1;
            coor.y=-1;
		}

		void updateDir(Dir dir){

            this->dir=dir;

            if(this->dir==HORIZONTAL){
                this->size[0]=this->size[2];
                this->size[1]=1;
            }else{
                this->size[0]=1;
                this->size[1]=this->size[2];
            }

		}

		void shot(){

        if(life>=0)
            life=life-1;
		}

		friend std::ostream& operator<< (std::ostream& os, const Ship& ship) {

            os<<"Nombre del barco"<<ship.name<<"\n"
            <<"id Tipo de barco"<<std::to_string(ship.type)<<"\n"
            <<"Tamaño del barco"<<std::to_string(ship.size[2])+"\n";

            return os;

		}

		static Ship* generateShip(ShipType type){

            Ship* ship;

            if(type==AIRCRAFT_CARRIER){

                ship=new Ship("Porta Aviones",5,type);

            }else if(type==BATTLESHIP){

                ship=new Ship("Acorazado", 4,type);

            }else if(type==FRIGATE){

                ship=new Ship("Fragata",3,type);

            }else if(type==SUBMARINE){

                ship=new Ship("Submarino",3,type);

            }else if(type==MINING_SHIP){

                ship=new Ship("Barco Minero",2,type);

            }

            return ship;
        }

        static bool thereATypeShipIn(ShipType type,Ship* fleet[5]){

            for(int i=0;i<5;i++){

                if(fleet[i] && fleet[i]->type==type)
                    return true;
            }

            return false;
        }


};

struct Hole {
    State state;
    Ship* ship;
};

class Battleship{
public:
SAMPLE *Block=load_sample("sound/block.wav");
SAMPLE *DisparoS=load_sample("sound/disparo.wav");
SAMPLE *ExplosionS=load_sample("sound/explosionS.wav");
BITMAP *fondo;
BITMAP *buffer;
BITMAP *cursor;
BITMAP *anuncio;

Hole logicalGrid1[10][10];
Hole logicalGrid2[10][10];

BITMAP *graphicGrid1;
BITMAP *graphicGrid2;
Coor originT1;
Coor originT2;

Ship* fleet1[5];
Ship* fleet2[5];

bool hideFleet1=false;
bool hideFleet2=false;

BITMAP *oceano;
BITMAP *explosion;
BITMAP *fallo;

BITMAP *barcobmp;

BITMAP *miningShip;
BITMAP *submarine;
BITMAP *frigate;
BITMAP *battleship;
BITMAP *aircrafCarrier;

BITMAP *disparoF;
BITMAP *menu;

std::string texto;

std::string texto2;

Dir dir=HORIZONTAL;
Modos Modo;

int cont=0;
bool end=false;

int contj1=0;
int contj2=0;

Coor holePointerCoor;


bool mouseInsideCoords(Coor xYLowerLimit,Coor xYUpperLimit){

    if(
        (mouse_x>=xYLowerLimit.x && mouse_x<=xYUpperLimit.x) \
        && \
        (mouse_y>=xYLowerLimit.y && mouse_y<=xYUpperLimit.y))
    {
        return true;
    }

    return false;
}

Coor getCoorHole(Coor oriCoor,int holeSize=30){

    Coor coor;
    coor.x=getXCoorHole(oriCoor.x,holeSize);
    coor.y=getYCoorHole(oriCoor.y,holeSize);

    return coor;

}

int getXCoorHole(int oriXCoor,int holeSize=30){

    return (mouse_x-(oriXCoor))/holeSize;

}

int getYCoorHole(int oriYCoor, int holeSize=30){

    return (mouse_y-(oriYCoor))/holeSize;

}

void resetLogicalGrid(Hole logicalGrid[10][10]) {
    for (int x = 0; x < 10; x++) {
        for (int y = 0; y < 10; y++) {
            logicalGrid[x][y].state=NORMAL;
            logicalGrid[x][y].ship=NULL;
        }
    }
}

void reset(){

    resetLogicalGrid(logicalGrid1);
    resetLogicalGrid(logicalGrid2);

}

//    int guarda_partida() {
//
//	std::ofstream archivo;
//	archivo.open("BatallaNaval2.dat", std::ios::binary);
//
//	if (!archivo) {
//            return 0 ;
//	}
//    for(int i=0;i<5;i++){
//    archivo.write( reinterpret_cast<const char *>(&fleetJ[i]),sizeof(fleetJ[i]));
////    archivo<<fleetJ[i]->name<<" "<<fleetJ[i]->size[0]<<" "<<fleetJ[i]->size[1]<<" "<<fleetJ[i]->size[2]<<" ";
//    }
//	archivo.close();
//
//	setTexto("El archivo se ha guardado");
//    escribirTextCenterCenter();
//    loadBufferOnScreen();
//
//	return 1;
//}

//int carga_partida() {
//
//	std::ifstream archivo;
//	archivo.open("BatallaNaval2.dat", std::ios::binary);
//
//	if (archivo.fail()) {
//		return 0;
//	}
//    for(int i=0;i<5;i++){
//    archivo.read((char *)&(this->fleetJ[i]), sizeof(Ship));
//    std::cout<<this->fleetJ[i]->name;
//    }
//    archivo.close();
//
//    setTexto("El archivo se ha Cargado");
//    escribirTextCenterCenter();
//    loadBufferOnScreen();
//    rest(500);
//
//    return 1;
//
//}

void loadBufferOnScreen(){
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}

void strCopiOToF(char* cadenaOrig,char* cadenaDest,int o,int f){

    for(int a=0,i=o;i<=f;a++,i++){
        cadenaDest[a]=cadenaOrig[i];
    }

}

//void escribirText(){
//
//    if(SCREEN_W>=text_length(font,texto)){
//
//        textout(buffer, font,texto,(SCREEN_W-text_length(font,texto))-text_height(font),text_height(font),makecol(255,255,255));
//
//    }else{
//
//        //itoa((int)(SCREEN_W/8),texto2,10);
//
//        for(int l=0;l<ceil(text_length(font,texto)/80);l++){
//
//        strCopiOToF(texto,texto2,(int)(l*SCREEN_W/8)/2,(int)((l+1)*SCREEN_W/8)/2);
//        textout(buffer, font,texto2,(SCREEN_W-text_length(font,texto2))-text_height(font),(l+1)*text_height(font)+l*10,makecol(255,255,255));
//
//        }
//
//    }
//
////Cada letra mide 8x8 bits
//
//}

void escribirTextCenterCenter(){

    textout(
        buffer,
        font,
        texto.c_str(),
        (SCREEN_W-text_length(font,texto.c_str()))/2,
        (SCREEN_H-text_height(font))/2,
        makecol(255,255,255)
    );
    //Cada letra mide 8x8 bits

    rest(20000);

    loadBufferOnScreen();

}

void setTexto(const std::string& texto1) {
    texto = texto1;
}

void setTexto(const std::string& texto1, const std::string& texto2) {
    texto = texto1 + texto2;
}

void setTexto(const std::string& texto1, const std::string& texto2, const std::string& texto3, const std::string& texto4) {
    texto = texto1 + texto2 + texto3 + texto4;

}

void writeTextCenterCenter(const std::string& text){

    clear(buffer);
    textout(
        buffer,
        font,
        text.c_str(),
        (SCREEN_W-text_length(font,text.c_str()))/2,
        (SCREEN_H-text_height(font))/2,
        makecol(255,255,255)
    );
    //Cada letra mide 8x8 bits
    loadBufferOnScreen();

    rest(1000);

}

BITMAP* getBitmapForShip(Ship* ship){

    BITMAP* bitmapShip;

    if(ship->type==AIRCRAFT_CARRIER){

        bitmapShip=aircrafCarrier;
        //bitmapExplosion=load_bitmap("img/elfragata.bmp",NULL);

    }else if(ship->type==BATTLESHIP){

        bitmapShip=battleship;
        //fleet[cont].mapaDBits2=load_bitmap("img/elsubmarino.bmp",NULL);


    }else if(ship->type==FRIGATE){

        bitmapShip=frigate;
        //fleet[cont].mapaDBits2=load_bitmap("img/elsubmarino.bmp",NULL);

    }else if(ship->type==SUBMARINE){

        bitmapShip=submarine;
        //fleet[cont].mapaDBits2=load_bitmap("img/elsubmarino.bmp",NULL);

    }else if(ship->type==MINING_SHIP){

        bitmapShip=miningShip;
        //fleet[cont].mapaDBits2=load_bitmap("img/elsubmarino.bmp",NULL);

    }

    return bitmapShip;

}

void drawOcean(Hole logicalGrid[10][10],BITMAP* graphicGrid,Coor origin){
    for(int fila=0;fila<maxfil-1;fila++){
        for(int columna=0;columna<maxcolm-1;columna++){

            draw_sprite(graphicGrid,oceano,columna*30,fila*30);

            if(logicalGrid[fila][columna].state==EXPLOSION){

                draw_sprite(graphicGrid,explosion,columna*30,fila*30);

            }else if(logicalGrid[fila][columna].state==MISSED_SHOT){
                draw_sprite(graphicGrid,fallo,columna*30,fila*30);
            }
        }
    }
   blit(graphicGrid,buffer,0,0,origin.x,origin.y,300,300);
}

void drawShip(Ship* ship,BITMAP *graphicGrid){

    if(ship->dir==HORIZONTAL){

        draw_sprite(graphicGrid,getBitmapForShip(ship),ship->coor.x*30,ship->coor.y*30);

    }else if(ship->dir==VERTICAL){
        //Recuerda que la rotacion se hace desde el centro
        rotate_sprite(graphicGrid,getBitmapForShip(ship),
            (ship->coor.x*30-(30*ship->size[1]/2)+15),
            (ship->coor.y*30+(30*ship->size[1]/2)-15),
            itofix(64)
        );
    }

}


void drawShips(Ship* fleet[5],BITMAP* graphicGrid,Coor originT){
    for(int i=0;i<5;i++){
        if(fleet[i]){
            drawShip(fleet[i],graphicGrid);
        }
    }
   blit(graphicGrid,buffer,0,0,originT.x,originT.y,300,300);
}

void drawSelecMenu(){
    draw_sprite(menu,miningShip,0,0);
    draw_sprite(menu,submarine,210,0);
    draw_sprite(menu,frigate,105,30);
    draw_sprite(menu,battleship,90,60);
    draw_sprite(menu,aircrafCarrier,75,90);
    blit(menu,buffer,0,0,0,(SCREEN_H-120),300,120);
}

void drawPauseMenu(){

    clear(buffer);
    setTexto("-----------Pausa-----------");
    textout(buffer,font,"Presiona [Esc] para salir",(SCREEN_W-text_length(font,"Presiona [Esc] para salir"))/2,(SCREEN_H)/2+2*text_height(font),makecol(255,255,255));
    textout(buffer,font,"Presiona [<-]o[->] para cambiar la direccion del barco",(SCREEN_W-text_length(font,"Presiona [<-]o[->] para cambiar la direccion del barco"))/2,(SCREEN_H/2+4*text_height(font)),makecol(255,255,255));
    textout(buffer,font,"Presiona [Espacio] para poner pause",(SCREEN_W-text_length(font,"Presiona [Espacio] para poner pause"))/2,(SCREEN_H/2+6*text_height(font)),makecol(255,255,255));
    textout(buffer,font,"Haz click izquierdo para selecionar colocar o disparar",(SCREEN_W-text_length(font,"Haz click izquierdo para selecionar colocar o disparar"))/2,(SCREEN_H)/2+8*text_height(font),makecol(255,255,255));
    textout(buffer,font,"Presiona [Enter] para quitar el pause",(SCREEN_W-text_length(font,"Presiona [Enter] para quitar el pause"))/2,(SCREEN_H/2+10*text_height(font)),makecol(255,255,255));

    loadBufferOnScreen();

}

void dibujarAnuncio(BITMAP *mapaDbits){
    draw_sprite(screen,mapaDbits,SCREEN_W/2-150,SCREEN_H/2-54);
    rest(1500);
}


void drawPointer(){
    masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
}

void drawView(){

        blit(fondo,buffer,0,0,0,0,640,640);

        drawSelecMenu();
        drawOcean(logicalGrid1,graphicGrid1,originT1);
        drawOcean(logicalGrid2,graphicGrid2,originT2);

        if(!hideFleet1){
            drawShips(fleet1,graphicGrid1,originT1);
        }
        if(!hideFleet2){
            drawShips(fleet2,graphicGrid2,originT2);
        }

        drawPointer();
        loadBufferOnScreen();

}

void loadPauseMenu(){

    if(key[KEY_SPACE]||key[KEY_P]){
        while(!key[KEY_ENTER]){
            if(key[KEY_ESC]){
                exit(0);
            }

            drawPauseMenu();
        }

    }

}

void loadBitmaps(){
    anuncio=load_bitmap("img/Averia.bmp",NULL);
    fondo = load_bitmap("img/fondo.bmp",NULL);
    cursor = load_bitmap("img/cursor.bmp",NULL);
    oceano=load_bitmap("img/tableroJ.bmp",NULL);
    menu=load_bitmap("img/tablero.bmp",NULL);
    explosion=load_bitmap("img/hundido.bmp",NULL);
    fallo=load_bitmap("img/fallo.bmp",NULL);

    miningShip=load_bitmap("img/buqueT.bmp",NULL);
    submarine=load_bitmap("img/submarinoT.bmp",NULL);
    frigate=load_bitmap("img/fragataT.bmp",NULL);
    battleship=load_bitmap("img/acorazadoT.bmp",NULL);
    aircrafCarrier=load_bitmap("img/portaT.bmp",NULL);

}

void loadGraphic(){

    buffer = create_bitmap(SCREEN_W,SCREEN_H);
    graphicGrid1 = create_bitmap(300,300);
    graphicGrid2 = create_bitmap(300,300);

    loadBitmaps();

}

void activateCoutdown(){

    int time=1000;

    writeTextCenterCenter("3");
    rest(time);
    writeTextCenterCenter("2");
    rest(time);
    writeTextCenterCenter("1");
    rest(time);

}

bool allShipsAreDestroyed(Ship* fleet[5]) {

		for (int i = 0; i <5; i++) {
			if(fleet[i]->life!=0){
                return false;

			}
		}

        return true;

	}

void keepSelectedShipWithinLimits(Ship* ship){

    if(holePointerCoor.x<0)
        {holePointerCoor.x=0;}

    if(holePointerCoor.y<0)
        {holePointerCoor.y=0;}

    if(holePointerCoor.x+(ship->size[0]-1)>9)
        {
            holePointerCoor.x=9-(ship->size[0]-1);
        }

    if(holePointerCoor.y+(ship->size[1]-1)>9)
        {
            holePointerCoor.y=9-(ship->size[1]-1);
        }


}

bool coorShipIsOccupied(Ship* ship, Hole logicalGrid[10][10]){

    for (int column = ship->coor.x; column <= ship->coor.x + (ship->size[0] - 1); column++) {
        for (int row = ship->coor.y; row <= ship->coor.y + (ship->size[1] - 1); row++) {

            if (logicalGrid[row][column].ship!=NULL) {
                return true;
            }

        }
    }
    return false;

}

void markShipOnGrid(Ship* ship,Hole logicalGrid[10][10]){

    //marca las posiciones del tablero con el barco correspondiente
    for(int fila=0;fila<ship->size[1];fila++){
        for(int columna=0;columna<ship->size[0];columna++){

            logicalGrid[holePointerCoor.y+fila][holePointerCoor.x+columna].ship=ship;

        }
    }


}

void putShip(Ship* fleet[5],Hole logicalGrid[10][10],BITMAP *graphicGrid,Coor origin){

        if(key[KEY_RIGHT]){
            if(holePointerCoor.x+1<=(9-fleet[cont]->size[0]+1)){
                dir=HORIZONTAL;
            }
        }
        if(key[KEY_LEFT]){
            if(holePointerCoor.y+1<=(9-fleet[cont]->size[1]+1)){
                dir=VERTICAL;
            }
        }

        fleet[cont]->updateDir(dir);
        fleet[cont]->coor=holePointerCoor;

        keepSelectedShipWithinLimits(fleet[cont]);

        fleet[cont]->coor=holePointerCoor;

        bool occupied=coorShipIsOccupied(fleet[cont],logicalGrid);

        if(
            (mouse_b & 1)&&
            is_inside_bitmap ( graphicGrid, (mouse_x-origin.x), (mouse_y-origin.y), 1)
            ||(Modo==AUTOMATICO)
        ){

            if(occupied){
                play_sample(Block , 255, 127, 1000, 0);
                writeTextCenterCenter("Esta ocupada la posicion");
            }
            else{

                markShipOnGrid(fleet[cont],logicalGrid);
                cont++;
            }

        }else{
            if(mouse_b  & 1){
                writeTextCenterCenter("Este no es tu tablero");
                rest(500);
            }
        }

}

void selectShip(Ship* fleet[5]){

    //writeTextCenterCenter("Te toca seleccinar un barco escogue \
    uno de los que se encuentran en el tablero de madera haciendo\
    click sobre el ,puedes cambiar la direccion del barco con las \
    flechas direccionales, tambien recuerda que al presionar la tecla\
     [espacio] puedes entrar en modo pausa, si quieres salir entra en \
     el modo pausa y presiona la tecla [Esc]");

    if(is_inside_bitmap (menu, mouse_x, mouse_y-(SCREEN_H-120), 1) && (mouse_b&1)){

        if(
            mouseInsideCoords({0,SCREEN_H-120},{60,SCREEN_H-90})
            && !Ship::thereATypeShipIn(MINING_SHIP,fleet)
        ){

            fleet[cont]=Ship::generateShip(MINING_SHIP);

        }else if(
            mouseInsideCoords({210,SCREEN_H-120},{300,SCREEN_H-90})
            && !Ship::thereATypeShipIn(SUBMARINE,fleet)
        ){
                fleet[cont]=Ship::generateShip(SUBMARINE);

        }else if(
            mouseInsideCoords({105,SCREEN_H-90},{195,SCREEN_H-60})
            && !Ship::thereATypeShipIn(FRIGATE,fleet)
        ){
                fleet[cont]=Ship::generateShip(FRIGATE);

        }else if(
            mouseInsideCoords({90,SCREEN_H-60},{210,SCREEN_H-30})
            && !Ship::thereATypeShipIn(BATTLESHIP,fleet)
        ){

            fleet[cont]=Ship::generateShip(BATTLESHIP);

        }else if(
            mouseInsideCoords({75,SCREEN_H-30},{225,SCREEN_H})
            && !Ship::thereATypeShipIn(AIRCRAFT_CARRIER,fleet)
        ){
                fleet[cont]=Ship::generateShip(AIRCRAFT_CARRIER);
        }

    rest(500);

    }else{
        if(mouse_b  & 1){
            play_sample(Block , 255, 127, 1000, 0);
        }
    }


//    if(fleet[cont]->name!=""){
//        setTexto("Haz seleccionado ",fleet[cont]->name);
//    }
}

int selectShipAutomatic(Ship* fleet[5]){

    switch(cont){
    case 0:
        fleet[cont]=Ship::generateShip(MINING_SHIP);
    return 1;
    break;
    case 1:
        fleet[cont]=Ship::generateShip(SUBMARINE);
    return 1;
    break;
    case 2:
        fleet[cont]=Ship::generateShip(FRIGATE);
    return 1;
    break;
    case 3:
        fleet[cont]=Ship::generateShip(BATTLESHIP);
    return 1;
    break;
    case 4:
        fleet[cont]=Ship::generateShip(AIRCRAFT_CARRIER);
    return 1;
    break;
    }

return 0;
}

void putShipAutomatic(Ship* fleet[5],Hole logicalGrid[10][10]){

        if(rand()%2==0){
            dir=HORIZONTAL;
        }else{
            dir=VERTICAL;
        }

        fleet[cont]->updateDir(dir);
        fleet[cont]->coor=holePointerCoor;

        keepSelectedShipWithinLimits(fleet[cont]);

        fleet[cont]->coor=holePointerCoor;

        if(!coorShipIsOccupied(fleet[cont],logicalGrid)){
            markShipOnGrid(fleet[cont],logicalGrid);
            cont++;
        }
}

void prepararTablero(Hole logicalGrid[10][10],BITMAP *graphicGrid,Ship* fleet[10],Coor originT,Modos Modo ,const std::string &name){

    writeTextCenterCenter("Le toca Colocar sus piesas en el tablero a "+name);

    //activateCoutdown();

    cont=0;
    bool termino=false;

    while(!termino){


        switch(Modo){
            case MANUAL:

                loadPauseMenu();
//
//               if(key[KEY_F1]){
//                    //guarda_partida();
//               }
//
                holePointerCoor=getCoorHole(originT);

                selectShip(fleet);

                if(fleet[cont] && fleet[cont]->size[2]>0){

                    putShip(fleet,logicalGrid,graphicGrid,originT);

                }

                //escribirText();

                break;

            case AUTOMATICO:

                holePointerCoor.x=rand()%9;
                holePointerCoor.y=rand()%9;
                selectShipAutomatic(fleet);

                if(fleet[cont]->size[2]>0){
                    putShipAutomatic(fleet,logicalGrid);
                }

                break;
        }

        drawView();

        if(cont==5){
            termino=true;
        }

    }

}

void disparar(Modos Modo,Hole tablero1[10][10],Hole tablero2[10][10],BITMAP *graphicGrid1,BITMAP *graphicGrid2,Ship* fleet1[5],Ship* fleet2[5],Coor originT1,Coor originT2) {

        bool termino=false;

		switch (Modo)
		{
		case MANUAL:
			while(!termino){

                loadPauseMenu();

                if(key[KEY_F1]){
                    //guarda_partida();
                }

                holePointerCoor=getCoorHole(originT2);

                if(mouse_b  & 1 && is_inside_bitmap(graphicGrid2, mouse_x-(originT2.x), mouse_y-(originT2.y), 1)){

                    if(!tablero2[holePointerCoor.y][holePointerCoor.x].state!=NORMAL){

                            play_sample(DisparoS , 255, 127, 1000, 0);

                            Ship* ship=tablero2[holePointerCoor.y][holePointerCoor.x].ship;

                            if(ship!=NULL){

                                ship->shot();
                                writeTextCenterCenter("Le disparastes al "+ship->name);

                                if(ship->life==0){

                                    writeTextCenterCenter("Haz destruido al "+ship->name);
                                    play_sample(ExplosionS , 255, 127, 1000, 0);

                                }

                                tablero2[holePointerCoor.y][holePointerCoor.x].state=EXPLOSION;

                            }else{

                                tablero2[holePointerCoor.y][holePointerCoor.x].state=MISSED_SHOT;

                            }

                        termino=true;

                        }

                }else{
                    play_sample(Block , 255, 127, 1000, 0);
                    setTexto("Ya le habias disparado a esta posicion");
                }

                drawView();

                }
			break;

		case AUTOMATICO:

        while(!termino){

            holePointerCoor.x=rand()%10;
            holePointerCoor.y=rand()%10;

            if(!tablero2[holePointerCoor.y][holePointerCoor.x].state!=NORMAL){

                play_sample(DisparoS , 255, 127, 1000, 0);

                Ship* ship=tablero2[holePointerCoor.y][holePointerCoor.x].ship;

                if(ship!=NULL){

                    ship->shot();
                    writeTextCenterCenter("Le disparastes al "+ship->name);

                    if(ship->life==0){

                        writeTextCenterCenter("Haz destruido al "+ship->name);
                        play_sample(ExplosionS , 255, 127, 1000, 0);

                    }

                    tablero2[holePointerCoor.y][holePointerCoor.x].state=EXPLOSION;

                }else{

                    tablero2[holePointerCoor.y][holePointerCoor.x].state=MISSED_SHOT;

                }

                    termino=true;

            }

        }

        break;

        }

}

void combate(Modos Modo1,Modos Modo2,Hole tablero1[10][10],Hole tablero2[10][10],const std::string &name1,const std::string &name2) {
    contj1=0;
    contj2=0;

		do{

            writeTextCenterCenter("Le toca disparar al "+name1);
//            hideFleet1=false;
//            hideFleet2=true;

			disparar(Modo1, tablero1,tablero2,graphicGrid1,graphicGrid2,fleet1,fleet2,
			{0,0},{SCREEN_W-300,SCREEN_H-300});
            contj1++;

            end=allShipsAreDestroyed(fleet2);

			if (end)
			{
				writeTextCenterCenter("Le toca disparar al jugador "+name2);
//                hideFleet2=false;
//                hideFleet1=true;

				disparar(Modo2, tablero2,tablero1, graphicGrid2,graphicGrid1,fleet2,fleet1,{SCREEN_W-300,SCREEN_H-300},{0,0});
				contj2++;

				end=allShipsAreDestroyed(fleet1);

                if (end)
                    {

                        writeTextCenterCenter("Ha habido un empate");

                        writeTextCenterCenter(name1+" realizo "+std::to_string(contj1)+" intentos");
                        rest(3000);

                        writeTextCenterCenter(name2+" realizo "+std::to_string(contj2)+" intentos");
                        rest(3000);

                        break;
                    }
                    else
                    {

                        writeTextCenterCenter("Felicidades ganastes: "+name1);

                        rest(3000);

                        writeTextCenterCenter(name1+" realizo "+std::to_string(contj1)+" intentos");
                        rest(3000);

                        writeTextCenterCenter(name2+" realizo "+std::to_string(contj2)+" intentos");
                        rest(3000);

                        end=true;

                    }
			}else{

            writeTextCenterCenter("Le toca disparar al "+name2);
//            hideFleet2=false;
//            hideFleet1=true;

			disparar(Modo2, tablero2,tablero1, graphicGrid2,graphicGrid1,fleet2,fleet1,{SCREEN_W-300,SCREEN_H-300},{0,0});
            contj2++;

            end=allShipsAreDestroyed(fleet1);

			if (end){

                    writeTextCenterCenter("Felicidades ganastes: "+name2);
                    rest(3000);

                    writeTextCenterCenter(name1+" realizo "+std::to_string(contj1)+" intentos");
                    rest(3000);

                    writeTextCenterCenter(name2+" realizo "+std::to_string(contj2)+" intentos");
                    rest(3000);

					break;

				}

            }

		} while (!end);

}

bool wantToStartTheGame(){

    while(true){

            clear(buffer);
            textout(buffer,font,"¿Quieres comenzar de primero?",(SCREEN_W-text_length(font,"Quieres comenzar de primero"))/2,(SCREEN_H)/2+2*text_height(font),makecol(255,255,255));
            textout(buffer,font,"Presiona [s] para Si",(SCREEN_W-text_length(font,"Presiona [s] para Si"))/2,(SCREEN_H/2+4*text_height(font)),makecol(255,255,255));
            textout(buffer,font,"Presiona [n] para No",(SCREEN_W-text_length(font,"Presiona [n] para No"))/2,(SCREEN_H/2+6*text_height(font)),makecol(255,255,255));
            //textout(buffer,font,"Haz click izquierdo para selecionar colocar o disparar",(SCREEN_W-text_length(font,"Haz click izquierdo para selecionar colocar o disparar"))/2,(SCREEN_H)/2+8*text_height(font),makecol(255,255,255));
            loadBufferOnScreen();

            if(key[KEY_S]){

                return true;

            }else if(key[KEY_N]){

                return false;

            }

    }


}

void playAlone ()
{
    srand(time(NULL));

    loadGraphic();

    reset();

    writeTextCenterCenter("Bienvenido al modo Solitario de battalla naval");

    originT1={0,0};
    originT2={SCREEN_W-300,SCREEN_H-300};

    if(wantToStartTheGame()){

        hideFleet1=false;
        hideFleet2=true;


        prepararTablero(logicalGrid1,graphicGrid1,fleet1,originT1,MANUAL,"Jugador 1");
        prepararTablero(logicalGrid2,graphicGrid2,fleet2,originT2,AUTOMATICO,"Cpu");

        combate(MANUAL,AUTOMATICO,logicalGrid1,logicalGrid2,"Jugador1","Cpu");

    }else{

        hideFleet1=true;
        hideFleet2=false;


        prepararTablero(logicalGrid1,graphicGrid1,fleet1,originT1,AUTOMATICO,"Cpu");
        prepararTablero(logicalGrid2,graphicGrid2,fleet2,originT2,MANUAL,"Jugador 1");

        combate(AUTOMATICO,MANUAL,logicalGrid1,logicalGrid2,"Cpu","Jugador 1");

    }


}

void playMultiplayer(){

    srand(time(NULL));

    loadGraphic();

    reset();

    writeTextCenterCenter("Bienvenido al modo Multiplayer de battalla naval");

    originT1={0,0};
    originT2={SCREEN_W-300,SCREEN_H-300};

    hideFleet1=false;
    hideFleet2=true;

    prepararTablero(logicalGrid1,graphicGrid1,fleet1,originT1,MANUAL,"Jugador 1");

    hideFleet1=true;
    hideFleet2=false;

    prepararTablero(logicalGrid2,graphicGrid2,fleet2,originT2,MANUAL,"Jugador 2");

    hideFleet1=true;
    hideFleet2=true;

    combate(MANUAL,MANUAL,logicalGrid1,logicalGrid2,"Jugador 1","Jugador 2");

}

void load(){

//
//            case CARGAR:
//            setTexto("Este modo solo esta disponible en la version premiun de batleship");
//            //escribirTextCenterCenter();
//            loadBufferOnScreen();
//            //carga_partida();
//            rest(1000);

}

};

#endif

