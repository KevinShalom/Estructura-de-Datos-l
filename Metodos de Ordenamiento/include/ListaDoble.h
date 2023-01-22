#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "nodo.h"
#include "producto.h"

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
        void insertarInicio(producto);
        void insertarFinal(producto);
        void imprimir();
        void eliminar(producto);
        nodo* buscar(producto);
        bool vacia();
        nodo* primero();
        nodo* ultimo();
        nodo* anterior(nodo *);
        nodo* siguiente(nodo *);
        int tamanioLista();
        void vaciar();

        void insertSort();
        void selectSort();
        void quickSort(ListaDoble*);
        void mergeSort(int,ListaDoble*);

    private:
};

#endif // LISTADOBLE_H
