#include <iostream>
#include<fstream>
#include <cstdlib>
#include <string>

#include <allegro.h>
#include "inicia.h"


#include <ctime>
#include "interfazGrafica.h"


int main ()
{
    inicia_allegro(640,640);
    inicia_audio(150,150);
    install_mouse();
    install_keyboard();

    InterfazGrafica Intefaz;

    Intefaz.run();

    return 0;
    }

END_OF_MAIN ()


