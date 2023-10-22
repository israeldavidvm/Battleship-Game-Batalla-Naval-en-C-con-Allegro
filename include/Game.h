#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstdlib>
#include <cstdio>

#include <string>
#include <math.h>

#include <allegro.h>

#include "View.h"

#include "SmallSpecialTypes.h"
#include "Ship.h"

//#define maxfil 11
//#define maxcolm 11

//declaracion adelantada para resolver la depedencia circular
class BattleshipGameEngine;
class Game : public View
{
    public:

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

    std::string texto;
    std::string texto2;

    Dir dir=HORIZONTAL;

    int cont=0;
    bool end=false;

    int contj1=0;
    int contj2=0;

    Coor holePointerCoor;

    BITMAP* background;
    BITMAP* backgroundWithHoverOp1;
    BITMAP* backgroundWithHoverOp2;
    BITMAP* backgroundWithHoverOp3;

    BITMAP *fondo;
    BITMAP *buffer;
    BITMAP *cursor;
    BITMAP *anuncio;

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

    SAMPLE* music;
    SAMPLE *blockSound;
    SAMPLE *shotSound;
    SAMPLE *explosionSound;

    BattleshipGameEngine* gameEngine;
    static Game* instance; //!< Member variable "instance"

    void resetLogicalGrid(Hole logicalGrid[10][10]);
    void resetFleet(Ship* fleet[5]);
    void reset();
    bool allShipsAreDestroyed(Ship* fleet[5]);
    bool coorShipIsOccupied(Ship* ship, Hole logicalGrid[10][10]);

    //int guarda_partida();
    //int carga_partida();


    BITMAP* getBitmapForShip(Ship* ship);

    void drawOcean(Hole logicalGrid[10][10],BITMAP* graphicGrid,Coor origin);
    void drawShip(Ship* ship,BITMAP *graphicGrid);
    void drawShips(Ship* fleet[5],BITMAP* graphicGrid,Coor originT);

    void drawSelecMenu();
    void drawPauseMenu();
    void dibujarAnuncio(BITMAP *mapaDbits);

    void drawPointer();
    void drawView();

    void loadPauseMenu();
    void loadBitmaps();
    void loadGraphic();

    void markShipOnGrid(Ship* ship,Hole logicalGrid[10][10]);

    Coor getCoorHole(Coor oriCoor,int holeSize=30);
    int getXCoorHole(int oriXCoor,int holeSize=30);
    int getYCoorHole(int oriYCoor, int holeSize=30);

    void keepSelectedShipWithinLimits(Ship* ship);

    void putShip(Ship* fleet[5],Hole logicalGrid[10][10],BITMAP *graphicGrid,Coor origin);
    void selectShip(Ship* fleet[5]);
    int selectShipAutomatic(Ship* fleet[5]);
    void putShipAutomatic(Ship* fleet[5],Hole logicalGrid[10][10]);

    void prepararTablero(Hole logicalGrid[10][10],BITMAP *graphicGrid,Ship* fleet[10],Coor originT,Modos Modo ,const std::string &name);

    void disparar(Modos Modo,Hole tablero1[10][10],Hole tablero2[10][10],BITMAP *graphicGrid1,BITMAP *graphicGrid2,Ship* fleet1[5],Ship* fleet2[5],Coor originT1,Coor originT2);
    void combate(Modos Modo1,Modos Modo2,Hole tablero1[10][10],Hole tablero2[10][10],const std::string &name1,const std::string &name2);

    bool wantToStartTheGame();

    void playAlone ();
    void playMultiplayer();

    void load();
    void run();

    static Game* getInstance(BattleshipGameEngine* gameEngine);

    Game(BattleshipGameEngine* gameEngine);
    ~Game();

    void listenEvents();
    void loadSounds();


};

#endif

