#include "../include/Manual.h"

#include "../include/View.h"
#include "../include/MainMenu.h"
#include "../include/Manual.h"

#include "../include/BattleshipGameEngine.h"

#include <allegro.h>

Manual* Manual::instance=NULL;

void Manual::run(){

    end=false;

    gameEngine->playSound(music , 255, 1000, 1);

    while(!end){
        listenEvents();
    }

    gameEngine->stopSound(music);


}

Manual* Manual::getInstance(BattleshipGameEngine* gameEngine){

    if(instance==NULL){
        instance=new Manual(gameEngine);
    }
    return instance;
}

Manual::Manual(BattleshipGameEngine* gameEngine)
{

    this->gameEngine=gameEngine;

    loadBitmaps();

    loadSounds();

}

Manual::~Manual()
{
    //dtor
}


void Manual::listenEvents(){

    if((mouse_x>=550&&mouse_x<=619)&&(mouse_y>=385&&mouse_y<=425)){
        gameEngine->changeBackground(backgroundWithHover);
        if(mouse_b & 1){
            gameEngine->playSound(blockSound);
            switch(estado){
                case CAPITULO1:
                    estado=CAPITULO2;
                    end=true;
                    break;

                case CAPITULO2:
                    estado=CAPITULO3;
                    end=true;
                    break;

                case CAPITULO3:
                    estado=CAPITULO4;
                    end=true;
                    break;

                case CAPITULO4:
                    estado=CAPITULO1;
                    gameEngine->changeView(MainMenu::getInstance(gameEngine));
                    end=true;
                    break;

            }

            loadBitmaps();
            rest(4000);
        }
    }
    else{
        gameEngine->changeBackground(background);
    }

}

void Manual::loadBitmaps(){

    switch(estado){
        case CAPITULO1:
            background = load_bitmap("img/ayuda1.bmp",NULL);
            backgroundWithHover = load_bitmap("img/ayuda2.bmp",NULL);
        break;
        case CAPITULO2:
            background = load_bitmap("img/ayuda3.bmp",NULL);
            backgroundWithHover = load_bitmap("img/ayuda4.bmp",NULL);
        break;
        case CAPITULO3:
            background = load_bitmap("img/ayuda5.bmp",NULL);
            backgroundWithHover = load_bitmap("img/ayuda6.bmp",NULL);
        break;
        case CAPITULO4:
            background = load_bitmap("img/ayuda7.bmp",NULL);
            backgroundWithHover = load_bitmap("img/ayuda8.bmp",NULL);
        break;

    }

}

void Manual::loadSounds(){

    blockSound=load_sample("sound/block.wav");

    music=load_sample("sound/menu.wav");

}
