#ifndef COLA_H
#define COLA_H

#include "NodoDoble.h"
#include "Carta.h"

#include <string>
class Cola{

    private: 
        NodoDoble *primero;
        NodoDoble *ultimo; 
        int longitud; 

    public: 
        Cola();

        void encolar(Carta *carta);
        Carta* desencolar();
        std::string verSuperior();

        int verLongitud(); 

};

#endif