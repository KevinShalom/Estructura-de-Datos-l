#ifndef NODO_H
#define NODO_H
#include <string>
#include <iostream>
#include "Animal.h"
using namespace std;

class nodo
{
     public:
        nodo(Animal AnimalIng){
            animal=AnimalIng;
            siguiente=nullptr;
        };
        nodo(Animal AnimalIng, nodo *temp1){
            animal=AnimalIng;
            siguiente=temp1;
        }

        Animal getAnimal();
        void setAnimal(Animal);

        nodo* getSiguiente();
        void setSiguiente(nodo*);

    private:
        Animal animal;
        nodo* siguiente;

};

#endif // NODO_H
