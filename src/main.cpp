#include <allegro.h>
#include "../include/BattleshipGameEngine.h"

int main ()
{

    BattleshipGameEngine juego(640,640,255,255);

    juego.run();

    return 0;
}
END_OF_MAIN ()


