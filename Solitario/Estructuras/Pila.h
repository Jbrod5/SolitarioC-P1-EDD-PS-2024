#ifndef PILA_H
#define PILA_H

#include "Nodo.h"
#include "Carta.h"

class Pila{

    private:
        Nodo* cima; 
        int longitud; 

    public: 
        Pila();

        void apilar(Carta* carta);
        Carta* desapilar();
        int obtenerLongitud(); 
    
};

#endif