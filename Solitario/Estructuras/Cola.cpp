#include "Cola.h"

Cola::Cola(){
    primero = nullptr;
    ultimo = nullptr; 
}


void Cola::encolar(Carta *carta){
    NodoDoble *nuevo = new NodoDoble(carta);

    if(ultimo == nullptr){
        primero = nuevo;
    }else{
        ultimo->siguiente = nuevo; 
    }

    ultimo = nuevo; 
}

Carta* Cola::desencolar(){
    if(primero == nullptr){
        
    }

    Carta *aDesencolar = primero->carta; 
    primero = primero->siguiente;

    if(primero == nullptr){
        ultimo = nullptr; 
    }

    return aDesencolar; 
}