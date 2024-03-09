#include "Cola.h"
#include <string>

Cola::Cola(){
    primero = nullptr;
    ultimo = nullptr; 
    longitud = 0; 
}


void Cola::encolar(Carta *carta){
    NodoDoble *nuevo = new NodoDoble(carta);

    if(ultimo == nullptr){
        primero = nuevo;
    }else{
        ultimo->siguiente = nuevo; 
    }
    longitud++;
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
    longitud--;
    return aDesencolar; 
}

std::string Cola::verSuperior(){
    if(primero != nullptr){
        Carta *aVer = primero->carta;
        return aVer->getCarta();     
    }

    return "NLL";
}

int Cola::verLongitud(){
    return longitud; 
}