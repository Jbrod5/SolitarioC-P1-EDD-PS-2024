#include <iostream>
#include "Pila.h"
#include "Nodo.h"
#include "Carta.h"

using namespace std;

Pila::Pila(){
    cima = nullptr; 
    longitud = 0; 
}

int Pila::obtenerLongitud(){
    return longitud; 
}

void Pila::apilar(Carta* carta){
    Nodo* nuevo = new Nodo(carta);
    nuevo->siguiente = cima; 
    cima = nuevo; 
    longitud ++;
}

Carta* Pila::desapilar(){
    if(cima == nullptr){
        cout << "Se intento desapilar de una pila vacia!" << endl; 
        return; 
    }else{
        Nodo* temporal = cima;
        cima = cima -> siguiente; 
        Carta* carta = temporal -> carta; 
        longitud--; 
        return carta; 
    }
}