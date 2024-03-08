#ifndef NODO_COLA_H
#define NODO_COLA_H

#include "Carta.h"



class NodoCola {
    public:
        Carta carta; 
        NodoCola *siguiente; 


        NodoCola(Carta cart); 
};

#endif