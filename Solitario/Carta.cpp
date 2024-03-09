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
    string carta;
    if(numero == 1){
        carta = "A";
    }else if(numero != 1 && numero < 10){
        carta = to_string( numero );
    }else{
        switch (numero)
        {
        case 11:
            carta = "J";
            break;
        case 12: 
            carta = "A";
            break;
        default:
            carta = "K";
            break;
        }
    }
    return( carta + " " + simbolo );
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

string Carta::obtenerSimbolo(){
    return simbolo; 
}

void Carta::colocarBocaArriba(){
    bocaArriba = true; 
}