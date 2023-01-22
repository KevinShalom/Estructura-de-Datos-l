#include "nodo.h"

producto nodo::getProducto()
{
    return this->productoNew;
}

void nodo::setProducto(producto productoNew)
{
    this->productoNew=productoNew;
}

nodo* nodo::getSiguiente()
{
    return this->siguiente;
}

void nodo::setSiguiente(nodo *siguiente)
{
    this->siguiente=siguiente;
}

nodo* nodo::getAnterior()
{
    return this->anterior;
}

void nodo::setAnterior(nodo *anterior)
{
    this->anterior=anterior;
}
