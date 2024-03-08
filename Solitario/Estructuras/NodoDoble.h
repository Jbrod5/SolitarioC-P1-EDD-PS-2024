#ifndef NODO_DOBLE_H
#define NODO_DOBLE_H

#include "Carta.h"



class NodoDoble {
    public:
        Carta *carta; 
        NodoCola *anterior;
        NodoCola *siguiente; 


        NodoDoble(Carta *cart); 
};

#endif