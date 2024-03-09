#include "Nodo.h"
#include "Carta.h"

Nodo::Nodo(Carta* cart){
    carta = cart;
    siguiente = nullptr; 
}