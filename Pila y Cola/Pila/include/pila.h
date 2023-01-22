#ifndef PILA_H
#define PILA_H
#include <string>
#include <iostream>
#include "nodo.h"
#include "Animal.h"
using namespace std;

class pila
{
    public:
        nodo *tope;
        int tamanio;

        pila(){
            tope=nullptr;
            tamanio=0;
        };

        void push(Animal);
        void pop();
        bool vacia();
        nodo* mostrarTope();
        void inicializa();
        int tamanioPila();
        void vaciar();
        void mostrarPila();

    protected:

    private:
};

#endif // PILA_H
