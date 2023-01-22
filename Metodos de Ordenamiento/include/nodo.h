#ifndef NODO_H
#define NODO_H

#include "producto.h"

class nodo
{
    public:
        nodo(producto productoingresado){
            productoNew=productoingresado;
            siguiente=nullptr;
            anterior=nullptr;
        };
        nodo(producto productoIngresado, nodo *temp1, nodo *temp2){
            productoNew=productoIngresado;
            siguiente=temp1;
            anterior=temp2;
        }

        producto getProducto();
        void setProducto(producto);
        nodo* getSiguiente();
        void setSiguiente(nodo*);
        nodo* getAnterior();
        void setAnterior(nodo*);
    private:
        producto productoNew;
        nodo* siguiente;
        nodo* anterior;
};

#endif // NODO_H
