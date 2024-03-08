#ifndef NODO_H
#define NODO_H

#include "Carta.h" 

class Nodo{
    public:
        Carta* carta;
        Nodo* siguiente; 

        Nodo(Carta* cart);

};

#endif