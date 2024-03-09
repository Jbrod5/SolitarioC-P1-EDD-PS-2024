#include <iostream>
#include "Pila.h"
#include "Nodo.h"
#include "Carta.h"

#include <string>

using namespace std;

Pila::Pila(string simb){
    cima = nullptr; 
    longitud = 0; 
    simbolo = simb;
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

string Pila::verCima(){
    if(cima != nullptr){
        return "[" + cima->carta->getCarta() + "]";
    }else{
        return "["+simbolo+"]";
    }
}

Carta* Pila::obtenerCima(){
    if(cima != nullptr){
        return cima->carta;
    }else{
        cout<<"Se intento desapilar de una pila vacia!"<<endl;
        return nullptr;
    }
}

bool Pila::apilarCartaJuego(Carta* carta){

    //Apilar si son del mismo simbolo
    bool apilable = carta->esRojo() != cima->carta->esRojo();
    bool apilable = carta->obtenerSimbolo() == cima->carta->obtenerSimbolo(); 

    if(apilable){
        apilar(carta);
    }

    return apilable;
}