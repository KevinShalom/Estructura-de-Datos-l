#include "pila.h"
void pila::push(Animal AnimalIng)
{
    nodo *temp=new nodo(AnimalIng);
    if(temp!=nullptr){
            temp->setSiguiente(tope);
            tope=temp;
            tamanio++;
    }
    else{
        temp->setAnimal(AnimalIng);
        tamanio++;
    }
}

void pila::pop()
{
    nodo *temp=tope;
    if(temp!=nullptr){
        tope=temp->getSiguiente();
        delete temp;
        cout<<"TOPE ELIMINADO"<<endl;
        tamanio--;
    }
    else{
        cout<<"Pila vacia..."<<endl<<endl;
    }
}

bool pila::vacia()
{
    if(tope!=nullptr){
        return true;
    }
    else{
        return false;
    }
}

nodo* pila::mostrarTope()
{
    if(tope!=nullptr){
        return tope;
    }
    else{
        cout<<"Pila vacia..."<<endl;
        return nullptr;
    }
}

void pila::inicializa()
{
    tope=nullptr;
    tamanio=0;
}

int pila::tamanioPila()
{
    return this->tamanio;
}

void pila::vaciar()
{
    nodo *aux=tope;
    if(tope!=nullptr){
        while(tope!=nullptr){
            aux=tope;
            tope=tope->getSiguiente();
            tamanio--;
            delete aux;
        }
    }
    else{
        cout<<"Pila vacia..."<<endl<<endl;
    }
}

void pila::mostrarPila()
{
    nodo *aux=tope;
    if(aux!=nullptr){
            cout<<"-----Datos Guardados-----"<<endl<<endl;
            while(aux){
                cout<<"Nombre: "<<aux->getAnimal().nombre<<endl;
                cout<<"Raza: "<<aux->getAnimal().raza<<endl<<endl;
                aux=aux->getSiguiente();
            }
    }
    else{
        cout<<"Pila vacia..."<<endl<<endl;
    }
}
