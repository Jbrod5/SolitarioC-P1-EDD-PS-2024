#include "Cola.h"
#include <string>
#include <iostream>
using namespace std; 


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

Carta* Cola::obtenerCartaADesencolar(){
    if(primero == nullptr){
        
        Carta *aDesencolar = primero->carta; 
        return aDesencolar;         
    }else{
        cout<<"Se quiere desencolar de una cola vacia!!"<<endl;
        return; 
    }

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