#include "../include/BattleshipGameEngine.h"

#include "../include/MainMenu.h"

#include <string>

BattleshipGameEngine::BattleshipGameEngine(unsigned int viewportW,unsigned int viewportH, unsigned int soundVolume, unsigned int musicVolume)
{

    this->viewportW=viewportW;
    this->viewportH=viewportH;

    //install_allegro (SYSTEM_AUTODETECT, &errno, atexit);
    allegro_init();

    set_window_title ("BattleshipGame by:israeldavidvm");

    //configurando intefaces graficas
    int depth = desktop_color_depth();
    if (depth == 0)
    {
        depth=32;
    }
    set_color_depth(depth);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, viewportW, viewportH, 0, 0);

    //configurando sonido
    if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL) != 0) {
        allegro_message("Error: inicializando sistema de sonido\n%s\n", allegro_error);
    }
    set_volume(soundVolume, musicVolume);

    install_timer();

    //configurando entradas y salidas
    install_mouse();
    install_keyboard();

    buffer = create_bitmap(viewportW,viewportH);
    cursor = load_bitmap("img/cursor.bmp",NULL);

    view=MainMenu::getInstance(this);
}

BattleshipGameEngine::~BattleshipGameEngine()
{
    //dtor
}

void BattleshipGameEngine::run(){
    endGame=false;

    while(!endGame){
        view->run();
    }
}

void BattleshipGameEngine::changeView(View* view){
    this->view=view;
}

void BattleshipGameEngine::loadBufferOnScreen(BITMAP* buffer)
{
    if(!buffer){
        buffer=this->buffer;
    }
    blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
}

void BattleshipGameEngine::strCopiOToF(char* cadenaOrig,char* cadenaDest,int o,int f){

    for(int a=0,i=o;i<=f;a++,i++){
            cadenaDest[a]=cadenaOrig[i];
    }

}

    //void escribirText(){
    //
    //    if(SCREEN_W>=text_length(font,texto)){
    //
    //        textout(buffer, font,texto,(SCREEN_W-text_length(font,texto))-text_height(font),text_height(font),makecol(255,255,255));
    //
    //    }else{
    //
    //        //itoa((int)(SCREEN_W/8),texto2,10);
    //
    //        for(int l=0;l<ceil(text_length(font,texto)/80);l++){
    //
    //        strCopiOToF(texto,texto2,(int)(l*SCREEN_W/8)/2,(int)((l+1)*SCREEN_W/8)/2);
    //        textout(buffer, font,texto2,(SCREEN_W-text_length(font,texto2))-text_height(font),(l+1)*text_height(font)+l*10,makecol(255,255,255));
    //
    //        }
    //
    //    }
    //
    ////Cada letra mide 8x8 bits
    //
    //}

//void BattleshipGameEngine::setTexto(const std::string& texto1) {
//        texto = texto1;
//}
//
//void BattleshipGameEngine::setTexto(const std::string& texto1, const std::string& texto2) {
//        texto = texto1 + texto2;
//}
//
//void BattleshipGameEngine::setTexto(const std::string& texto1, const std::string& texto2, const std::string& texto3, const std::string& texto4) {
//        texto = texto1 + texto2 + texto3 + texto4;
//
//}

void BattleshipGameEngine::writeTextCenterCenter(const std::string& text){

        clear(buffer);
        textout(
            buffer,
            font,
            text.c_str(),
            (SCREEN_W-text_length(font,text.c_str()))/2,
            (SCREEN_H-text_height(font))/2,
            makecol(255,255,255)
        );
        //Cada letra mide 8x8 bits
        loadBufferOnScreen();

        rest(1000);

}

void BattleshipGameEngine::activateCoutdown(){

        int time=1000;

        writeTextCenterCenter("3");
        rest(time);
        writeTextCenterCenter("2");
        rest(time);
        writeTextCenterCenter("1");
        rest(time);

}

void BattleshipGameEngine::changeBackground(BITMAP* background){
    clear_bitmap(buffer);
    blit(background,buffer,0,0,0,0,640,640);
    masked_blit(cursor,buffer,0,0,mouse_x,mouse_y,13,22);
    blit(buffer,screen,0,0,0,(SCREEN_H/2)-245,640,640);
}

bool BattleshipGameEngine::mouseInsideCoords(Coor xYLowerLimit,Coor xYUpperLimit){

    if(
        (mouse_x>=xYLowerLimit.x && mouse_x<=xYUpperLimit.x) \
        && \
        (mouse_y>=xYLowerLimit.y && mouse_y<=xYUpperLimit.y))
    {
        return true;
    }

        return false;
}

void BattleshipGameEngine::playSound(SAMPLE* sound,unsigned int vol,unsigned int freq, unsigned int loop){
    play_sample (sound, vol, 127, 1000, loop);
}

void BattleshipGameEngine::stopSound(SAMPLE* sound){
    stop_sample(sound);
}

void BattleshipGameEngine::end(){
    endGame=TRUE;
}
