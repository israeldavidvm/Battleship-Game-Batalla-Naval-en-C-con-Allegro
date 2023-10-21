#ifndef MAINMENU_H
#define MAINMENU_H

#include "View.h"
#include "BattleshipGameEngine.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

#include <allegro.h>

#include <ctime>
#include <cstdio>
//declaracion adelantada para resolver la depedencia circular
class BattleshipGameEngine;

class MainMenu : public View
{
    public:

        static MainMenu* getInstance(BattleshipGameEngine* gameEngine);

        void run();

    protected:

    private:

        //MainMenu();
        MainMenu(BattleshipGameEngine* gameEngine);
        virtual ~MainMenu();


        void loadBitmaps();
        void loadSounds();
        void listenEvents();

        //int opcion;
        bool end;

        SAMPLE* music;
        SAMPLE* blockSound;

        BITMAP* buffer;
        BITMAP* cursor;

        BITMAP* background;
        BITMAP* backgroundWithHoverOp1;
        BITMAP* backgroundWithHoverOp2;
        BITMAP* backgroundWithHoverOp3;
        BITMAP* backgroundWithHoverOp4;
        BITMAP* backgroundWithHoverOp5;

        BattleshipGameEngine* gameEngine;
        static MainMenu* instance; //!< Member variable "instance"

};

#endif // MAINMENU_H
