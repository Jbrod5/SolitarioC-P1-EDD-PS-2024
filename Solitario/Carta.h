#ifndef CARTA_H
#define CARTA_H

class Carta{

    private: 
        int numero; 
        std::string simbolo; 
        bool bocaArriba; 
        bool rojo; 

    public: 
        Carta(int num, std::string simbolo, bool ro);
        string  getCarta();
        int     getValor();

        bool esRojo();
        bool estaBocaArriba();
        void voltear();
        string obtenerSimbolo(); 
        void colocarBocaArriba();

};

#endif