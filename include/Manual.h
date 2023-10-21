#ifndef MANUAL_H
#define MANUAL_H

#include "View.h"
#include "MainMenu.h"

#include "BattleshipGameEngine.h"

#include <allegro.h>

class Manual : public View
{
    public:

        static Manual* getInstance(BattleshipGameEngine* gameEngine);

        void run();

    protected:

    private:

        enum VistasM{CAPITULO1,CAPITULO2,CAPITULO3,CAPITULO4};
        VistasM estado;

        Manual(BattleshipGameEngine* gameEngine);

        virtual ~Manual();
        void listenEvents();
        void loadBitmaps();
        void loadSounds();

        bool end;

        SAMPLE* music;
        SAMPLE* blockSound;

        BITMAP* buffer;
        BITMAP* cursor;

        BITMAP* background;
        BITMAP* backgroundWithHover;

        BattleshipGameEngine* gameEngine;
        static Manual* instance; //!< Member variable "instance"

};

#endif // MANUAL_H
