CPP = g++
TARGET = solitario

#all
all: .all-post

.all-post: Carta.o Nodo.o NodoDoble.o Cola.o ListaDoble.o  Pila.o Solitario.o Main.o
		$(CPP) Carta.o Nodo.o NodoDoble.o Cola.o ListaDoble.o  Pila.o Solitario.o Main.o -o $(TARGET)

Carta.o: Carta.cpp Carta.h
		$(CPP) -c Carta.cpp
Nodo.o: Nodo.cpp Nodo.h
		$(CPP) -c Nodo.cpp
NodoDoble.o: NodoDoble.cpp NodoDoble.h
		$(CPP) -c NodoDoble.cpp
Cola.o: Cola.cpp Cola.h
		$(CPP) -c Cola.cpp
ListaDoble.o: ListaDoble.cpp ListaDoble.h
		$(CPP) -c ListaDoble.cpp
Pila.o: Pila.cpp Pila.h
		$(CPP) -c Pila.cpp
Solitario.o: Solitario.cpp Solitario.h
		$(CPP) -c Solitario.cpp

Main.o: 
		$(CPP) -c Main.cpp

#clean
clean:
	rm -f *.o $(TARGET)