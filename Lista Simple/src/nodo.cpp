#include "nodo.h"

nodo::nodo()
{
    cadena= "";
    siguiente=nullptr;
}

string nodo::getCadena()
{
    return this->cadena;
}

void nodo::setCadena(string cadena)
{
    this->cadena=cadena;
}

nodo* nodo::getSiguiente()
{
    return this->siguiente;
}

void nodo::setSiguiente(nodo *siguiente)
{
    this->siguiente=siguiente;
}
