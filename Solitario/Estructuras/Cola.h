#ifndef COLA_H
#define COLA_H

#include "NodoDoble.h"
#include "Carta.h"

class Cola{

    private: 
        NodoDoble *primero;
        NodoDoble *ultimo; 

    public: 
        Cola();

        void encolar(Carta *carta);
        Carta desencolar();



};

#endif