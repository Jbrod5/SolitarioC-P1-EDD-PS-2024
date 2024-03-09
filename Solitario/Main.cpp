#include "Solitario.h"
#include <iostream>
#include <string>

using namespace std;

int main(){

    Solitario* solitario = new Solitario();
    int opcion = 0; 

    cout <<"Jorge Bravo   -   202131782"<<endl; 
    cout <<" - - - - Solitario - - - - "<<endl; 
    while(opcion != 3){
        solitario->imprimirTablero(); 
        cout<<"Accion: 1 -> Pasar carta de cola | 2 -> Mover carta | 3 -> Salir"<<endl; 
        cin>>opcion; 
        switch (opcion)
        {
        case 1:
            solitario->pasarCartaCola();
            break;
        case 2: 
            solitario->moverCarta(); 
            break;
        default:
            cout<<"Opcion no reconocida"<<endl; 
            break;
        }   
    }

    return 0; 
}