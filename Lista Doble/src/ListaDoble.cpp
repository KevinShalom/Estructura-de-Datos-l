#include "ListaDoble.h"

void ListaDoble::inicializa()
{
    cabeza=nullptr;
    cola=nullptr;
    tamanio=0;
}

void ListaDoble::insertarInicio(Animal animalIngresado)
{
    nodo* temp=new nodo(animalIngresado);
    if(cabeza==nullptr and cola==nullptr){
        cabeza=temp;
        cola=temp;
        tamanio++;
    }
    else{
        temp->setSiguiente(cabeza);
        cabeza->setAnterior(temp);
        cabeza=cabeza->getAnterior();
        tamanio++;
    }
}

void ListaDoble::insertarFinal(Animal animalIngresado)
{
    nodo* temp=new nodo(animalIngresado);
    if(cabeza==nullptr and cola==nullptr){
        cabeza=temp;
        cola=temp;
        tamanio++;
    }
    else{
        temp->setAnterior(cola);
        cola->setSiguiente(temp);
        cola=cola->getSiguiente();
        tamanio++;
    }
}

void ListaDoble::imprimir()
{
    nodo *aux=cabeza;
    cout<<endl;
    if(cabeza==nullptr and cola==nullptr){
        cout<<"Lista vacia..."<<endl;
    }
    else{
        while(aux){
            cout<<"Animal: "<<aux->getAnimal().nombre<<endl<<"Raza: "<<aux->getAnimal().raza<<endl;
            cout<<"Id: "<<aux->getAnimal().id;
            aux=aux->getSiguiente();
            cout<<endl;
        }
    }
    cout<<endl;
}

void ListaDoble::eliminar(Animal animalIngresado)
{
    nodo *aux=cabeza;
    bool bandera=true;
    if(cabeza!=nullptr){
        while(aux and bandera){
            if(aux->getAnimal().nombre==animalIngresado.nombre){
                bandera=false;
            }
            else{
                aux=aux->getSiguiente();
            }
        }
        if(aux==nullptr){
            cout<<"Dato no encontrado..."<<endl;
        }
        else if(cabeza==cola){
            cabeza=nullptr;
            cola=nullptr;
            tamanio--;
            delete aux;
        }
        else if(aux==cabeza){
            cabeza=cabeza->getSiguiente();
            cabeza->setAnterior(nullptr);
            tamanio--;
            delete aux;
        }
        else if(aux==cola){
            cola=cola->getAnterior();
            cola->setSiguiente(nullptr);
            tamanio--;
            delete aux;
        }
        else{
            aux->getAnterior()->setSiguiente(aux->getSiguiente());
            aux->getSiguiente()->setAnterior(aux->getAnterior());
            tamanio--;
            delete aux;
        }
    }
    else{
        cout<<"Lista vacia..."<<endl;
    }
}

nodo* ListaDoble::buscar(Animal animalIngresado)
{
    nodo *aux=cabeza;
    if(aux==nullptr){
       cout<<"Lista vacia..."<<endl;
    }
    else{
         while(aux!=nullptr){
            if(aux->getAnimal().id==animalIngresado.id){
                return aux;
            }
            else{
                aux=aux->getSiguiente();
            }
        }
    cout<<"Dato no encontrado"<<endl;
    }
    return nullptr;
}

bool ListaDoble::vacia()
{
    if(cabeza!=nullptr){
        return false;
    }
    else{
        return true;
    }
}

nodo* ListaDoble::primero()
{
    nodo *aux=cabeza;
    if(aux!=nullptr){
        return aux;
    }
    else{
        cout<<"Lista vacia..."<<endl;
        return nullptr;
    }
}

nodo* ListaDoble::ultimo()
{
    nodo *aux=cola;
    if(aux!=nullptr){
        return aux;
    }
    else{
        cout<<"Lista vacia..."<<endl;
        return nullptr;
    }
}

nodo* ListaDoble::anterior(nodo *ubicacion)
{
    if(cabeza!=nullptr){
        if(ubicacion!=nullptr){
            if(ubicacion->getAnterior()!=nullptr){
                return ubicacion->getAnterior();
            }
            else{
                cout<<"Final de lista..."<<endl;
                return ubicacion;
            }
        }
        else{
            cout<<"No existen mas elementos..."<<endl;
            return ubicacion;
        }
    }
    else{
        cout<<"Lista vacia..."<<endl;
        return ubicacion;
    }
}

nodo* ListaDoble::siguiente(nodo *ubicacion)
{
    if(cabeza!=nullptr){
        if(ubicacion!=nullptr){
            if(ubicacion->getSiguiente()!=nullptr){
                return ubicacion->getSiguiente();
            }
            else{
                cout<<"Final de lista..."<<endl;
                return ubicacion;
            }
        }
        else{
            cout<<"No existen mas elementos..."<<endl;
            return ubicacion;
        }
    }
    else{
        cout<<"Lista vacia..."<<endl;
        return ubicacion;
    }
}

int ListaDoble::tamanioLista()
{
    return this->tamanio;
}

void ListaDoble::vaciar()
{
    nodo *aux=cabeza;

    if(cabeza!=nullptr){
        while(cabeza!=nullptr){
        aux=cabeza;
        cabeza=cabeza->getSiguiente();
        tamanio--;
        delete aux;
        }
    }
    else{
        cout<<"Lista vacia..."<<endl;
    }
}
