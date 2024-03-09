#ifndef SOLITARIO_H
#define SOLITARIO_H

// 4 Pilas
// 2 Colas 
// 7 Listas 

// C C    |    P P P P
//       L L L L L L L

#include "Pila.h"
#include "Cola.h"
#include "ListaDoble.h"
#include "NodoDoble.h"
#include "Nodo.h"

#include "Carta.h"

#include <string>

class Solitario{
    private: 

        ListaDoble* listaCartas; 

        Cola* colaA; 
        Cola* colaB; 

        void iniciarCartas();
        void iniciarColas();

        std::string obtenerSigno(int s);
        bool obtenerColor(int s);


        Pila* pila[4];


        ListaDoble* lista[7];

        public: 
            Solitario();

};

#endif