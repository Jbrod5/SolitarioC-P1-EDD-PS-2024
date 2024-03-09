#include <iostream>
#include "Solitario.h"

#include "Pila.h"
#include "Cola.h"
#include "ListaDoble.h"
#include "NodoDoble.h"
#include "Nodo.h"

#include "Carta.h"

#include<iostream>
#include<string>

#include <cstdlib>
#include <ctime>

using namespace std; 


Solitario::Solitario(){

    listaCartas = new ListaDoble();

    // Instanciar las dos colas del juego
    colaA = new Cola(); 
    colaB = new Cola();

    // Instanciar las cuatro pilas del juego
    for (int pilaC = 0; pilaC < 4; pilaC++){
        pila[pilaC] = new Pila();
    }

    // Instanciar las 7 listas del juego
    for (int listaC = 0; listaC < 7; listaC++){
        lista[listaC] = new listaC();
    }
    
}

/* Genera todas las cartas en orden colocandolas aleatoriamente en la lista */
void Solitario::iniciarCartas(){
    srand(static_cast<unsigned int>(std::time(nullptr)));
    int posicionAleatoria; 
    Carta* nuevaCarta; 

    // 4 signos | 0 = <3 R  | 1 = <> R | 2 = E3 N | 3 = !! N 
    for (int signo = 0; signo < 4; signo++)
    {   // 13 Cartas por signo
        for (int numCarta = 1; numCarta <= 13; numCarta++)
        {
            if(signo == 0 && (numCarta == 1 | numCarta == 2)){
                nuevaCarta = new Carta(numCarta, obtenerSigno(signo), obtenerColor(signo));
                numCarta++;
                this->listaCartas->insertarAlInicio(nuevaCarta);
                nuevaCarta = new Carta(numCarta, obtenerSigno(signo), obtenerColor(signo));
                numCarta++;
                this->listaCartas->insertarAlFinal(nuevaCarta);
            }
            posicionAleatoria = rand() % (listaCartas->obtenerLongitud() + 1);
            nuevaCarta = new Carta(numCarta, obtenerSigno(signo), obtenerColor(signo));
            listaCartas->insertarEnIndice(nuevaCarta, posicionAleatoria);
        }        
    }
    
}

string Solitario::obtenerSigno(int s){
    // 4 signos | 0 = <3 R  | 1 = <> R | 2 = E3 N | 3 = !! N 
    if(s == 0){
        return "<3 R";
    }else if(s == 1){
        return "<> R";
    }else if(s == 2){
        return "E3 N";
    }else{
        return "!! N";
    }
}
bool Solitario::obtenerColor(int s){
    // 4 signos | 0 = <3 R  | 1 = <> R | 2 = E3 N | 3 = !! N 
    if(s == 0 | s == 1){
        return true;
    }else{
        false; 
    }
}