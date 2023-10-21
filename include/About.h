#ifndef ABOUT_H
#define ABOUT_H


#include "../include/MainMenu.h"
#include "../include/BattleshipGameEngine.h"
#include <allegro.h>

class About : public View
{
    public:
        static About* getInstance(BattleshipGameEngine* gameEngine);

        void run();

    private:
        About(BattleshipGameEngine* gameEngine);
        virtual ~About();


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
        BITMAP* backgroundWithHover;

        BattleshipGameEngine* gameEngine;
        static About* instance; //!< Member variable "instance"
};

#endif // ABOUT_H
