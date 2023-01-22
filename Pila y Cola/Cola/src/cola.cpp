#include "cola.h"

void cola::insertar(Animal AnimalIng)
{
    nodo *temp=new nodo(AnimalIng);
    if(primero==nullptr){
        primero=temp;
        tamanio++;
    }
    else{
        ultimo->setSiguiente(temp);
        tamanio++;
    }
    ultimo=temp;
}

void cola::dequeue()
{
    nodo *temp=primero;
    if(primero!=nullptr){
        if(primero==ultimo){
            primero=nullptr;
            ultimo=nullptr;
        }
        else{
            primero=primero->getSiguiente();
        }
        delete temp;
        tamanio--;
    }
    else{
        cout<<"Cola vacia..."<<endl<<endl;
    }
}

nodo* cola::first()
{
    if(primero!=nullptr){
        return primero;
    }
    else{
        return nullptr;
    }
}

nodo* cola::last()
{
    if(ultimo!=nullptr){
        return ultimo;
    }
    else{
        return nullptr;
    }
}

void cola::inicializa()
{
    primero=nullptr;
    ultimo=nullptr;
    tamanio=0;
}

bool cola::vacia()
{
     if(primero!=nullptr){
        return true;
    }
    else{
        return false;
    }
}

int cola::tamanioCola()
{
    return tamanio;
}

void cola::vaciar()
{
    nodo *aux=primero;
    if(primero!=nullptr){
        while(primero!=nullptr){
            aux=primero;
            primero=primero->getSiguiente();
            tamanio--;
            delete aux;
        }
        ultimo=nullptr;
    }
    else{
        cout<<"Cola vacia..."<<endl<<endl;
    }
}

void cola::mostrarCola()
{
    nodo *aux=primero;
    if(aux!=nullptr){
            cout<<"------DATOS GUARDADOS------"<<endl<<endl;
            while(aux){
                cout<<"Nombre: "<<aux->getAnimal().nombre<<endl;
                cout<<"Raza: "<<aux->getAnimal().raza<<endl<<endl;
                aux=aux->getSiguiente();
            }
    }
    else{
        cout<<"Cola vacia..."<<endl<<endl;
    }
}

