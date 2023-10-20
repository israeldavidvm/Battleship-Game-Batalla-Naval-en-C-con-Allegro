#include "../include/BattleshipGameEngine.h"

#include "../include/MainMenu.h"

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

    bufer = create_bitmap(viewportW,viewportH);
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

void BattleshipGameEngine::changeBackground(BITMAP* background){
    clear_bitmap(bufer);
    blit(background,bufer,0,0,0,0,640,640);
    masked_blit(cursor,bufer,0,0,mouse_x,mouse_y,13,22);
    blit(bufer,screen,0,0,0,(SCREEN_H/2)-245,640,640);
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
