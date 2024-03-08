#include "ListaDoble.h"
#include <iostream>

using namespace std; 



ListaDoble::ListaDoble(){
    primero = nullptr; 
    ultimo = nullptr; 
    longitud = 0; 
}


int ListaDoble::obtenerLongitud(){
    return longitud;
}

void ListaDoble::insertarAlInicio(Carta* carta){
    NodoDoble* nuevoNodo = new NodoDoble(carta);
    if (primero == nullptr) {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        nuevoNodo -> siguiente = primero;
        primero -> anterior = nuevoNodo;
        primero = nuevoNodo;
    }
    longitud++;
}

void ListaDoble::insertarAlFinal(Carta* carta){
    NodoDoble* nuevoNodo = new NodoDoble(carta);
    if (ultimo == nullptr) {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
    } else {
        nuevoNodo -> anterior = ultimo;
        ultimo -> siguiente = nuevoNodo;
        ultimo = nuevoNodo;
    }
    longitud++;
}

void ListaDoble::insertarEnIndice(Carta* carta, int indice){
    if (indice < 0 || indice > longitud) {
        cout << " El indice en donde se intento insertar una carta no es valido. " <<endl; 
        return;
    }

    if (indice == 0) {
        insertarAlInicio(carta);
    } else if (indice == longitud) {
        insertarAlFinal(carta);
    } else {
        NodoDoble* nuevoNodo = new NodoDoble(carta);
        NodoDoble* actual = primero;
        for (int i = 0; i < indice - 1; i++) {
            actual = actual->siguiente;
        }
        nuevoNodo->anterior = actual;
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente->anterior = nuevoNodo;
        actual->siguiente = nuevoNodo;
        longitud++;
    }
}


void ListaDoble::eliminarEnIndice(int indice){
    if (indice < 0 || indice >= longitud) {
        cout << "El índice especificado no es válido." << endl;
        return;
    }

    NodoDoble* actual = primero;
    for (int i = 0; i < indice; i++) {
        actual = actual->siguiente;
    }

    if (actual == primero) {
        primero = actual->siguiente;
    } else {
        actual->anterior->siguiente = actual->siguiente;
    }

    if (actual == ultimo) {
        ultimo = actual->anterior;
    } else {
        actual->siguiente->anterior = actual->anterior;
    }

    delete actual;
    longitud--;
}

Carta* ListaDoble::obtenerEnIndice(int indice){
    if (indice < 0 || indice >= longitud) {
        cout << "El índice especificado no es válido." << endl;
        return nullptr;
    }

    NodoDoble* actual = primero;
    for (int i = 0; i < indice; i++) {
        actual = actual->siguiente;
    }

    return actual-> carta;
}
