#ifndef COLA_H
#define COLA_H

#include <string>
#include <iostream>
#include "nodo.h"
#include "Animal.h"
using namespace std;

class cola
{
    public:
        nodo *primero;
        nodo *ultimo;
        int tamanio;

        cola(){
            primero=nullptr;
            ultimo=nullptr;
            tamanio=0;
        };

        void insertar(Animal);
        void dequeue();
        nodo* first();
        nodo* last();
        void inicializa();
        bool vacia();
        int tamanioCola();
        void vaciar();
        void mostrarCola();

    protected:

    private:
};

#endif // COLA_H
