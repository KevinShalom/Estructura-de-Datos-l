#ifndef NODO_H
#define NODO_H

#include "Animal.h"

class nodo
{
    public:
        nodo(Animal animalIngresado){
            animal=animalIngresado;
            siguiente=nullptr;
            anterior=nullptr;
        };
        nodo(Animal animalIngresado, nodo *temp1, nodo *temp2){
            animal=animalIngresado;
            siguiente=temp1;
            anterior=temp2;
        }

        Animal getAnimal();
        void setAnimal(Animal);

        nodo* getSiguiente();
        void setSiguiente(nodo*);

        nodo* getAnterior();
        void setAnterior(nodo*);
    private:
        Animal animal;
        nodo* siguiente;
        nodo* anterior;
};

#endif // NODO_H
