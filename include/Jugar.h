#ifndef JUGAR_H
#define JUGAR_H

#include "View.h"
#include "View.h"
#include "BattleshipGameEngine.h"
#include "Battleship.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include <allegro.h>

#include <ctime>
#include <cstdio>

class Jugar : public View
{
    public:
        static Jugar* getInstance(BattleshipGameEngine* gameEngine);

        void run();

    private:
        Jugar(BattleshipGameEngine* gameEngine);
        virtual ~Jugar();


        void loadBitmaps();
        void loadSounds();
        void listenEvents();

        //int opcion;
        bool end;

        SAMPLE* music;
        SAMPLE* blockSound;

        BITMAP* bufer;
        BITMAP* cursor;

        BITMAP* background;
        BITMAP* backgroundWithHoverOp1;
        BITMAP* backgroundWithHoverOp2;
        BITMAP* backgroundWithHoverOp3;

        BattleshipGameEngine* gameEngine;
        Battleship* battleship;
        static Jugar* instance; //!< Member variable "instance"
};

#endif // JUGAR_H
