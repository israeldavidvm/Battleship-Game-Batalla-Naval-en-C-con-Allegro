#include "../include/MainMenu.h"
#include "../include/Game.h"
#include "../include/Manual.h"
#include "../include/About.h"

#include "../include/BattleshipGameEngine.h"

#include <allegro.h>

MainMenu* MainMenu::instance=NULL;

void MainMenu::run(){

    end=false;

    gameEngine->playSound(music , 255, 1000, 1);

    while(!end){
        listenEvents();
    }

    gameEngine->stopSound(music);

}

MainMenu* MainMenu::getInstance(BattleshipGameEngine* gameEngine){

    if(instance==NULL){
        instance=new MainMenu(gameEngine);
    }
    return instance;
}

MainMenu::MainMenu(BattleshipGameEngine* gameEngine)
{

    this->gameEngine=gameEngine;

    loadBitmaps();

    loadSounds();

}

MainMenu::~MainMenu()
{


}


void MainMenu::listenEvents(){

    if(gameEngine->mouseInsideCoords({118,252},{360,279})){

        gameEngine->changeBackground(backgroundWithHoverOp1);

        if(mouse_b & 1){
            gameEngine->playSound(blockSound);
            gameEngine->changeView(Game::getInstance(gameEngine));
            end=true;
        }
    }else if(gameEngine->mouseInsideCoords({118,280},{360,305})){
        gameEngine->changeBackground(backgroundWithHoverOp2);

        if(mouse_b & 1){
            //Load
            //gameEngine->playSound(blockSound);
            //end=true;
        }
    }
    else if(gameEngine->mouseInsideCoords({118,306},{360,333})){
        gameEngine->changeBackground(backgroundWithHoverOp3);

        if(mouse_b & 1){
            gameEngine->playSound(blockSound);
            gameEngine->changeView(About::getInstance(gameEngine));
            end=true;
        }
    }
    else if(gameEngine->mouseInsideCoords({118,334},{360,360})){
        gameEngine->changeBackground(backgroundWithHoverOp4);

        if(mouse_b & 1){
            gameEngine->playSound(blockSound);
            gameEngine->changeView(Manual::getInstance(gameEngine));
            end=true;
        }
    }
    else if(gameEngine->mouseInsideCoords({118,360},{360,420})){
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

void MainMenu::loadBitmaps(){

    background = load_bitmap("img/normal.bmp",NULL);

    backgroundWithHoverOp1 = load_bitmap("img/iniciar.bmp",NULL);
    backgroundWithHoverOp2 = load_bitmap("img/cargarjuego.bmp",NULL);
    backgroundWithHoverOp3= load_bitmap("img/acercadeljuego.bmp",NULL);
    backgroundWithHoverOp4 = load_bitmap("img/ayuda.bmp",NULL);
    backgroundWithHoverOp5 = load_bitmap("img/salir.bmp",NULL);

}

void MainMenu::loadSounds(){

    blockSound=load_sample("sound/block.wav");

    music=load_sample("sound/menu.wav");

}
