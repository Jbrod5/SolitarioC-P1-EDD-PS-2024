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
        pila[pilaC] = new Pila(obtenerSigno(pilaC));
    }

    // Instanciar las 7 listas del juego
    for (int listaC = 0; listaC < 7; listaC++){
        lista[listaC] = new ListaDoble();
    }

    iniciarCartas(); 
    
}

void Solitario::iniciarCartas(){

    /* Genera todas las cartas en orden colocandolas aleatoriamente en la lista */
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

    /* Colocar 24 cartas en la colaA */
    Carta* aEncolar;
    for(int cartasEncoladas = 0; cartasEncoladas < 24; cartasEncoladas++){
        aEncolar = listaCartas->obtenerEnIndice(cartasEncoladas);
        colaA->encolar(aEncolar);
    }

    /* Colocar 28 cartas en las listas ( diagonalmente ) */
    int contadorCartas; 
    int contadorLista = 24;
    Carta* aEnlistar;
    for (int columna = 0; columna < 7; columna++)
    {   contadorCartas = 0; 
        // Colocar la misma cantidad de cartas que el numero de columna
        while (contadorCartas <= columna){
            aEnlistar = listaCartas->obtenerEnIndice(contadorLista);
            contadorLista ++;
            if(columna == contadorCartas){
                aEnlistar->voltear();
            }
            lista[columna]->insertarAlFinal(aEnlistar);
            contadorCartas++;
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
        return false; 
    }
}

/* METODOS DE JUEGO */

/*Pasa una carta de la colaA a colaB, si se acaban las cartas en A se regresan a ella */
void Solitario::pasarCartaCola(){
    if(colaA->verLongitud() > 0){
        colaB->encolar(  colaA->desencolar()  );
    }else{
        colaA = colaB;
        colaB = new Cola();
    }
}


void Solitario::moverCarta(){

    Carta* carta;
    bool insertado = false;  

    int origen = 0;
    int destino = 0;
    ListaDoble* listaDestino = nullptr; 
    ListaDoble* listaOrigen = nullptr;

    Pila* pilaOrigen = nullptr; 
    Pila* pilaDestino = nullptr; 

    //1. Obtener el origen
    int opcion = 0;
    cout << "Ingrese el tipo de origen: " << endl; 
    cout << "1 -> Cola B   |   2 -> Pila   |   3 -> Lista"<<endl;
    cin >> opcion;
    cout << endl; 
    switch (opcion)
    {
    case 1:
        origen = 0;
        carta = colaB->obtenerCartaADesencolar();
        break;
    case 2: 
        origen = 1;
        cout<<"Ingrese el numero de la pila (0-4)"<<endl;
        cin >> opcion; 
        cout << endl; 
        if(opcion < 0 | opcion > 3){ opcion = 3; }
        pilaOrigen  =pila[opcion];
        carta = pilaOrigen->obtenerCima();
        break;
    default:
        origen = 2;
        cout<<"Ingrese el numero de la lista(0-6)"<<endl; 
        cin >> opcion; 
        cout << endl; 
        if(opcion < 0 | opcion > 6){ opcion = 6; }
        listaOrigen = lista[opcion];
        carta = listaOrigen->obtenerEnIndice(listaOrigen->obtenerLongitud()-1);
        break;
    } 

    //2. Obtener el destinoint 
    cout << "Ingrese el tipo de destino: " << endl; 
    cout << "1 -> Pila   |    2 -> Lista"<<endl;
    cin >> opcion;
    cout << endl; 
    switch (opcion)
    {
    case 1:
        destino = 1;
        cout<<"Ingrese el numero de la pila (0-4)"<<endl;
        cin >> opcion; 
        cout << endl; 
        if(opcion < 0 | opcion > 3){ opcion = 3; }
        pilaDestino  =pila[opcion];
        insertado = pilaDestino->apilarCartaJuego(carta);
        break;
        
    default:
        destino = 2;
        cout<<"Ingrese el numero de la lista(0-6)"<<endl; 
        cin >> opcion; 
        cout << endl; 
        if(opcion < 0 | opcion > 6){ opcion = 6; }
        listaDestino = lista[opcion];
        insertado = listaDestino->insertarAlFinalJuego(carta);
        break;
    } 

    // Perpetuar el intercambio | cola pila lista
    if(insertado){
        switch (origen)
        {
        case 0:
            colaB->desencolar();
            break;
        case 2:
            pilaOrigen->desapilar();
        default:
            listaOrigen->eliminarEnIndice(listaOrigen->obtenerLongitud()-1);
            break;
        }
    }    
}






void Solitario::imprimirTablero(){
    system("cls");
    string linea =""; 
    //1. Imprimir pilas y colas
        //1.1 COLAS 
        if(colaA->verLongitud() > 0){
            linea += "[#]";
        }else{
            linea += "[ ]";
        }

        if(colaB->verLongitud() > 0){
            linea += "[" + colaB->verSuperior() + "]";
        }else{
            linea += "[ ]";
        }

        //1.2 PILAS 
        linea += "    ";
        for (int conPilas = 0; conPilas < 4; conPilas++)
        {
            linea += "  " + pila[conPilas]->verCima();
        }
    
    cout<<linea<<endl; 
    linea = "";

    // 2. Imprimir listas enlazadas
    int altura = 0; 
    int altListaActual =0; 
    for(int conLista = 0; conLista < 7; conLista++){
        altListaActual = lista[conLista]->obtenerLongitud();
        if(altura < altListaActual){
            altura = altListaActual; 
        }
    }

    for (int contAltura = 0; contAltura < altura; contAltura++)
    {
        for (int listaAct = 0; listaAct < 7; listaAct++)
        {
            linea += "  " + lista[listaAct]->imprimir(contAltura);
        }
        cout << linea << endl; 
        linea = "";
    }
    
    cout << endl << endl;
}