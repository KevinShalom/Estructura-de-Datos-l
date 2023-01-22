#include "nodo.h"

Animal nodo::getAnimal()
{
    return this->animal;
}

void nodo::setAnimal(Animal animal)
{
    this->animal=animal;
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
