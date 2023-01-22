#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;
#include "nodo.h"

class lista
{
    public:
        lista();
        nodo *cabeza;
        int tamanio;
        void inicializa();
        void insertarInicio(string);
        void insertarFinal(string);
        void imprimir();
        void eliminar(string);
        nodo* buscar(string);
        bool vacia();
        nodo* primero();
        nodo* ultimo();
        nodo* anterior(nodo *);
        nodo* siguiente(nodo *);
        int tamanioLista();
        void vaciar();

    private:
};

#endif // LISTA_H
