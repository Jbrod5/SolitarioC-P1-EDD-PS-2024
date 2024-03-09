#ifndef CARTA_H
#define CARTA_H

#include <string>
using namespace std;

class Carta{

    private: 
        int numero; 
        string simbolo; 
        bool bocaArriba; 
        bool rojo; 

    public: 
        Carta(int num, string simbolo, bool ro);
        string  getCarta();
        int     getValor();

        bool esRojo();
        bool estaBocaArriba();
        void voltear();
        string obtenerSimbolo(); 
        void colocarBocaArriba();

};

#endif