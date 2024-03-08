#include "Carta.h"
#include <iostream>
#include <string>

using namespace std; 

Carta::Carta(int num, string sim, bool ro){
    numero = num;
    simbolo = sim; 
    bocaArriba = false; 
    rojo = ro; 

}

int Carta::getValor(){
    return(numero);
}

string Carta::getCarta(){
    return(to_string( numero ) + " " + simbolo );
}

bool Carta::esRojo(){
    return rojo; 
}


bool Carta::estaBocaArriba(){
    return bocaArriba; 
}

void Carta::voltear(){
    bocaArriba = !bocaArriba;
}