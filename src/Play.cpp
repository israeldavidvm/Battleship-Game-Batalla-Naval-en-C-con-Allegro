#include "../include/Play.h"
#include "../include/View.h"
#include "../include/MainMenu.h"
#include "../include/Manual.h"
#include "../include/About.h"

#include "../include/BattleshipGameEngine.h"

#include <allegro.h>


Play* Play::instance=NULL;

void Play::run(){

    end=false;
    gameEngine->playSound(music , 255, 1000, 1);

    while(!end){
        listenEvents();
    }

    gameEngine->stopSound(music);

}

Play* Play::getInstance(BattleshipGameEngine* gameEngine){

    if(instance==NULL){
        instance=new Play(gameEngine);
    }
    return instance;
}

Play::Play(BattleshipGameEngine* gameEngine)
{

    this->gameEngine=gameEngine;

    loadBitmaps();

    loadSounds();

}

Play::~Play()
{


}


void Play::listenEvents(){

    if((mouse_x>=118&&mouse_x<=360)&&(mouse_y>=252&&mouse_y<=279)){

        gameEngine->changeBackground(backgroundWithHoverOp1);

        if(mouse_b & 1){
            //Vista=JUGAR;
            gameEngine->playSound(blockSound);
            //salir=true;
        }
    }else if((mouse_x>=118&&mouse_x<=360)&&(mouse_y>=280&&mouse_y<=305)){
        gameEngine->changeBackground(backgroundWithHoverOp2);

        if(mouse_b & 1){
            //Vista=JUGAR;
            gameEngine->playSound(blockSound);
            //batleship->jugar2(CARGAR);
            //salir=true;
        }
    }
    else if((mouse_x>=118&&mouse_x<=360)&&(mouse_y>=306&&mouse_y<=333)){
        gameEngine->changeBackground(backgroundWithHoverOp3);

        if(mouse_b & 1){
            gameEngine->playSound(blockSound);
            gameEngine->changeView(About::getInstance(gameEngine));
            end=true;
        }
    }
    else if((mouse_x>=118&&mouse_x<=360)&&(mouse_y>=334&&mouse_y<=360)){
        gameEngine->changeBackground(backgroundWithHoverOp4);

        if(mouse_b & 1){
            gameEngine->playSound(blockSound);
            gameEngine->changeView(Manual::getInstance(gameEngine));
            end=true;
        }
    }
    else if((mouse_x>=118&&mouse_x<=360)&&(mouse_y>=360&&mouse_y<=420)){
        gameEngine->changeBackground(backgroundWithHoverOp5);

        if(mouse_b & 1){
            gameEngine->playSound(blockSound);
            end=true;
            gameEngine->end();
        }
    }
    else{
        gameEngine->changeBackground(background);
    }
}

void Play::loadBitmaps(){

    background = load_bitmap("img/normal.bmp",NULL);

    backgroundWithHoverOp1 = load_bitmap("img/iniciar.bmp",NULL);
    backgroundWithHoverOp2 = load_bitmap("img/cargarjuego.bmp",NULL);
    backgroundWithHoverOp3= load_bitmap("img/acercadeljuego.bmp",NULL);
    backgroundWithHoverOp4 = load_bitmap("img/ayuda.bmp",NULL);
    backgroundWithHoverOp5 = load_bitmap("img/salir.bmp",NULL);

}

void Play::loadSounds(){

    blockSound=load_sample("sound/block.wav");

    music=load_sample("sound/menu.wav");

}

