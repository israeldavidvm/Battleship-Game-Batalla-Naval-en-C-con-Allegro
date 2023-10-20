#include "../include/View.h"
#include "../include/MainMenu.h"
#include "../include/About.h"

#include "../include/BattleshipGameEngine.h"

#include <allegro.h>

About* About::instance=NULL;

void About::run(){

    end=false;

    gameEngine->playSound(music , 255, 1000, 1);

    while(!end){
        listenEvents();
    }

    gameEngine->stopSound(music);


}

About* About::getInstance(BattleshipGameEngine* gameEngine){

    if(instance==NULL){
        instance=new About(gameEngine);
    }
    return instance;
}

About::About(BattleshipGameEngine* gameEngine)
{

    this->gameEngine=gameEngine;

    loadBitmaps();

    loadSounds();

}

About::~About()
{
    //dtor
}


void About::listenEvents(){

    while(!end){

        if((mouse_x>=550&&mouse_x<=619)&&(mouse_y>=385&&mouse_y<=425)){

            gameEngine->changeBackground(backgroundWithHover);

            if(mouse_b & 1){
                gameEngine->changeView(MainMenu::getInstance(gameEngine));
                gameEngine->playSound(blockSound);

                end=true;
            }
        }
        else{
            gameEngine->changeBackground(background);
        }
    }

}

void About::loadBitmaps(){

    background = load_bitmap("img/acercadeljuego1.bmp",NULL);
    backgroundWithHover = load_bitmap("img/acercadeljuego2.bmp",NULL);

}

void About::loadSounds(){

    blockSound=load_sample("sound/block.wav");

    music=load_sample("sound/menu.wav");

}
