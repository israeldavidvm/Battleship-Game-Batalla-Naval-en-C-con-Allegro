#ifndef BATTLESHIP_GAME_ENGINE_H
#define BATTLESHIP_GAME_ENGINE_H

#include "MainMenu.h"
#include "View.h"
#include <allegro.h>

class BattleshipGameEngine
{
    public:
        BattleshipGameEngine(unsigned int viewportW,unsigned int viewportH,unsigned int soundVolume, unsigned int musicVolume);

        virtual ~BattleshipGameEngine();

        void run();
        void changeView(View* view);
        void changeBackground(BITMAP* background);
        void playSound(SAMPLE* sound,unsigned int vol=255,unsigned int freq=1000, unsigned int loop=0);
        void stopSound(SAMPLE* sound);
        void end();

    protected:

    private:

        unsigned int viewportW;
        unsigned int viewportH;

        bool endGame;

        BITMAP *bufer;
        BITMAP *cursor;
        SAMPLE *Block;
        SAMPLE *MenuS;

    //    BatallaNaval *batleship;

        View* view;
};

#endif //
