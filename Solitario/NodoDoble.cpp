#include "NodoDoble.h"
#include "Carta.h"

NodoDoble::NodoDoble(Carta *cart){
    carta = cart; 
    anterior = nullptr; 
    siguiente = nullptr; 
}

