#ifndef PLAY_H
#define PLAY_H

#include "../include/MainMenu.h"
#include "../include/BattleshipGameEngine.h"
#include <allegro.h>

class Play
{
       public:

        static Play* getInstance(BattleshipGameEngine* gameEngine);

        void run();

    protected:

    private:

        //MainMenu();
        Play(BattleshipGameEngine* gameEngine);
        virtual ~Play();


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
        BITMAP* backgroundWithHoverOp4;
        BITMAP* backgroundWithHoverOp5;

        BattleshipGameEngine* gameEngine;
        static Play* instance; //!< Member variable "instance"
};

#endif // PLAY_H
