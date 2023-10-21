#ifndef SHIP_H
#define SHIP_H

#include <string>
#include "SmallSpecialTypes.h"


enum ShipType { AIRCRAFT_CARRIER, BATTLESHIP, FRIGATE, SUBMARINE, MINING_SHIP };

class Ship {
public:
    std::string name;
    //size establece los valores de tamaño dependiendo del tipo de barco y la direccion
    //size[0] es el valor horizontal
    //size[1] es el valor vertical
    //size[2] es el valor mas grande entre ambos
    int size[3];
    int life;

    Dir dir;
    Coor coor;
    ShipType type;

    Ship(const std::string &name, int size, ShipType shipType);
    void updateDir(Dir dir);
    void shot();

    friend std::ostream &operator<<(std::ostream &os, const Ship &ship);
    static Ship *generateShip(ShipType type);
    static bool thereATypeShipIn(ShipType type, Ship *fleet[5]);

};

enum State{NORMAL,EXPLOSION,MISSED_SHOT};
struct Hole {
        State state;
        Ship* ship;
};

#endif // SHIP_H
