#ifndef BATTLESHIP_GAME_ENGINE_H
#define BATTLESHIP_GAME_ENGINE_H

#include "SmallSpecialTypes.h"
#include "MainMenu.h"
#include "View.h"
#include <allegro.h>
#include <string>

class BattleshipGameEngine
{
    public:
        BattleshipGameEngine(unsigned int viewportW,unsigned int viewportH,unsigned int soundVolume, unsigned int musicVolume);

        virtual ~BattleshipGameEngine();

        void run();
        bool mouseInsideCoords(Coor xYLowerLimit,Coor xYUpperLimit);
        void loadBufferOnScreen(BITMAP* buffer=NULL);

        void strCopiOToF(char* cadenaOrig,char* cadenaDest,int o,int f);
        //void escribirText();
        void setTexto(const std::string& texto1);
        void setTexto(const std::string& texto1, const std::string& texto2);
        void BsetTexto(const std::string& texto1, const std::string& texto2, const std::string& texto3, const std::string& texto4);

        void writeTextCenterCenter(const std::string& text);

        void activateCoutdown();
        void changeView(View* view);
        void changeBackground(BITMAP* background);
        void playSound(SAMPLE* sound,unsigned int vol=255,unsigned int freq=1000, unsigned int loop=0);
        void stopSound(SAMPLE* sound);
        void end();

        BITMAP *buffer;

    protected:

    private:

        unsigned int viewportW;
        unsigned int viewportH;

        bool endGame;

        BITMAP *cursor;
        SAMPLE *Block;
        SAMPLE *MenuS;

    //    BatallaNaval *batleship;

        View* view;
};

#endif //
