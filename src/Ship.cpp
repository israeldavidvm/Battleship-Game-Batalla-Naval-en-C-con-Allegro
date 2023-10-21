#include "Ship.h"

#include <iostream>
// Definición del constructor
Ship::Ship(const std::string &name, int size, ShipType shipType) {
    this->name = name;
    this->type = shipType;
    this->size[0] = -1;
    this->size[1] = -1;
    this->size[2] = size;
    this->life = size;
    dir = NULA;
    coor.x = -1;
    coor.y = -1;
}

// Definición de la función updateDir
void Ship::updateDir(Dir dir) {
    this->dir = dir;
    if (this->dir == HORIZONTAL) {
        this->size[0] = this->size[2];
        this->size[1] = 1;
    } else {
        this->size[0] = 1;
        this->size[1] = this->size[2];
    }
}

// Definición de la función shot
void Ship::shot() {
    if (life >= 0)
        life = life - 1;
}

// Definición de la función friend operator<<
std::ostream &operator<<(std::ostream &os, const Ship &ship) {
    os << "Nombre del barco" << ship.name << "\n"
       << "id Tipo de barco" << std::to_string(ship.type) << "\n"
       << "Tamaño del barco" << std::to_string(ship.size[2]) << "\n";
    return os;
}

// Definición de la función estática generateShip
Ship *Ship::generateShip(ShipType type) {
    Ship *ship;
    if (type == AIRCRAFT_CARRIER) {
        ship = new Ship("Porta Aviones", 5, type);
    } else if (type == BATTLESHIP) {
        ship = new Ship("Acorazado", 4, type);
    } else if (type == FRIGATE) {
        ship = new Ship("Fragata", 3, type);
    } else if (type == SUBMARINE) {
        ship = new Ship("Submarino", 3, type);
    } else if (type == MINING_SHIP) {
        ship = new Ship("Barco Minero", 2, type);
    }
    return ship;
}

// Definición de la función estática thereATypeShipIn
bool Ship::thereATypeShipIn(ShipType type, Ship *fleet[5]) {
    for (int i = 0; i < 5; i++) {
        if (fleet[i] && fleet[i]->type == type)
            return true;
    }
    return false;
}
