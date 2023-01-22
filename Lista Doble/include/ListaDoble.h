#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "nodo.h"
using namespace std;

class ListaDoble
{
    public:
        nodo *cabeza;
        nodo *cola;
        int tamanio;

        ListaDoble(){
            cabeza=nullptr;
            cola=nullptr;
            tamanio=0;
        };

        void inicializa();
        void insertarInicio(Animal);
        void insertarFinal(Animal);
        void imprimir();
        void eliminar(Animal);
        nodo* buscar(Animal);
        bool vacia();
        nodo* primero();
        nodo* ultimo();
        nodo* anterior(nodo *);
        nodo* siguiente(nodo *);
        int tamanioLista();
        void vaciar();

    private:
};

#endif // LISTADOBLE_H
