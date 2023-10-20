void reseteo(casilla tablero[10][10]);
void escribir();
void setTexto(char texto1[100]);
void setTexto( char texto1[100], char texto2[100]);

void dibujarOceano(casilla tablero1[10][10],BITMAP *tablero1BTM,int x,int y);
void mostrarTablero(casilla tablero[10][10],const char nombre[10]);

void dibujarBarcos(barcoS flota[5],BITMAP *tableroBTM,int x,int y);
void dibujarMenu();

void dibujarAnuncio(BITMAP *mapaDbits);

void colocacion(barcoS flota[5],casilla tablero[10][10],BITMAP *tablero1BTM,int x1,int y1);

void seleccion(barcoS flota[5]);

int seleccionHidden(barcoS flota[5]);

void colocacionHidden(barcoS flota[5],casilla tablero1[10][10]);

void dibujarBarco(barcoS flota[5],BITMAP *tablero1BTM);

int escanear(barcoS flota, casilla tablero[10][10]);

void dibujarConPuntero(BITMAP *barco);

void dibujarPuntero();
