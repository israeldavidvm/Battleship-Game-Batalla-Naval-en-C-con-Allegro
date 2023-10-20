#include "../include/Jugar.h"
#include "../include/Battleship.h"


Jugar* Jugar::instance=NULL;


void Jugar::run(){

    end=false;

    gameEngine->playSound(music , 255, 1000, 1);

    while(!end){
        listenEvents();
    }

    gameEngine->stopSound(music);


}

Jugar* Jugar::getInstance(BattleshipGameEngine* gameEngine){

    if(instance==NULL){
        instance=new Jugar(gameEngine);
    }
    return instance;
}

Jugar::Jugar(BattleshipGameEngine* gameEngine)
{

    this->gameEngine=gameEngine;

    battleship=new Battleship();

    loadBitmaps();

    loadSounds();

}

Jugar::~Jugar()
{
    //dtor
}


void Jugar::listenEvents(){

    while(!end){

        if((mouse_x>=160&&mouse_x<=312)&&(mouse_y>=280&&mouse_y<=305)){
            gameEngine->changeBackground(backgroundWithHoverOp1);
            if(mouse_b & 1){
                gameEngine->playSound(blockSound);
                battleship->playAlone();
                gameEngine->changeView(MainMenu::getInstance(gameEngine));
                end=true;
            }
        }else if((mouse_x>=146&&mouse_x<=333)&&(mouse_y>=308&&mouse_y<=332)){
            gameEngine->changeBackground(backgroundWithHoverOp2);
            if(mouse_b & 1){
                gameEngine->playSound(blockSound);
                battleship->playMultiplayer();
                gameEngine->changeView(MainMenu::getInstance(gameEngine));
                end=true;
            }
        }
        else if((mouse_x>=170&&mouse_x<=294)&&(mouse_y>=333&&mouse_y<=357)){
            gameEngine->changeBackground(backgroundWithHoverOp3);
            if(mouse_b & 1){
                gameEngine->playSound(blockSound);
                gameEngine->changeView(MainMenu::getInstance(gameEngine));
                end=true;
            }
        }
        else{
            gameEngine->changeBackground(background);
        }

    }

}

void Jugar::loadBitmaps(){

    background= load_bitmap("img/iniciomenu.bmp",NULL);
    backgroundWithHoverOp1 = load_bitmap("img/inicioindividual.bmp",NULL);
    backgroundWithHoverOp2 = load_bitmap("img/iniciodosjugadores.bmp",NULL);
    backgroundWithHoverOp3= load_bitmap("img/inicioregresar.bmp",NULL);

}

void Jugar::loadSounds(){

    blockSound=load_sample("sound/block.wav");

    music=load_sample("sound/menu.wav");

}

