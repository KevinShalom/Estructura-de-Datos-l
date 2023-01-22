#include "lista.h"

lista::lista()
{
    cabeza=nullptr;
    tamanio=0;
}

void lista::inicializa()
{
    cabeza=nullptr;
    tamanio=0;
}

void lista::insertarFinal(string cadenaIngresada)
{
    nodo *temp=new nodo(cadenaIngresada);
    nodo *aux=cabeza;
    if(cabeza!=nullptr){
        while(aux->getSiguiente()!=nullptr){
            aux=aux->getSiguiente();
        }
        aux->setSiguiente(temp);
        tamanio++;
    }
    else{
        cabeza=temp;
        tamanio++;
    }
}

void lista::imprimir()
{
    nodo *aux=cabeza;
    cout<<endl;
    if(cabeza==nullptr){
        cout<<"Lista vacia..."<<endl;
    }
    else{
        while(aux){
            cout<<aux->getCadena()<<"--->";
            aux=aux->getSiguiente();
        }
    }
    cout<<endl;
}
void lista::insertarInicio(string cadenaIngresada)
{
    nodo *temp=new nodo(cadenaIngresada);
    if(cabeza==nullptr){
        cabeza=temp;
        tamanio++;
    }
    else{
        temp->setSiguiente(cabeza);
        cabeza=temp;
        tamanio++;
    }
}


void lista::eliminar(string cadenaIngresada)
{
    nodo *ant=nullptr;
    nodo *aux=cabeza;
    bool bandera=true;
    if(cabeza!=nullptr){
        while(aux and bandera){
        if(cadenaIngresada!=aux->getCadena()){
            ant=aux;
            aux=aux->getSiguiente();
        }
        else{
            bandera=false;
        }
    }

    if(aux==nullptr){
        cout<<"Dato no encontrado..."<<endl;
    }
    else if(aux==cabeza){
        cabeza=cabeza->getSiguiente();
        cout<<"Elemento eliminado..."<<endl;
        tamanio--;
        delete aux;
    }
    else{
        ant->setSiguiente(aux->getSiguiente());
        tamanio--;
        delete aux;
    }
    }
    else{
        cout<<"Lista vacia..."<<endl;
    }


}

nodo* lista::buscar(string busqueda)
{
    nodo *aux=cabeza;
    if(aux==nullptr){
       cout<<"Lista vacia..."<<endl;
    }
    else{
         while(aux!=nullptr){
            if(aux->getCadena()==busqueda){
                return aux;
            }
            else{
                aux=aux->getSiguiente();
            }
        }
        cout<<endl;
    cout<<"Dato no encontrado"<<endl;
    }
    return nullptr;
}

bool lista::vacia()
{
    bool listaVacia;
    if(cabeza==nullptr){
        listaVacia=true;
    }
    else{
        listaVacia=false;
    }
    return listaVacia;
}

nodo* lista::primero()
{
    nodo *aux=cabeza;
    if(aux!=nullptr){
        return aux;
    }
    else{
        system("cls");
        system("color 0E");
        cout<<endl;
        cout<<"Lista vacia..."<<endl;
        system("pause");
        return nullptr;
    }
}

nodo* lista::ultimo()
{
    if(cabeza!=nullptr){
     nodo *aux=cabeza;
    while(aux->getSiguiente()!=nullptr){
        aux=aux->getSiguiente();
    }
    return aux;
    }
    else{
        system("cls");
        system("color 0E");
        cout<<endl;
        cout<<"Lista vacia..."<<endl;
        system("pause");
        return nullptr;
    }
}

nodo* lista::anterior(nodo *ubicacion)
{
   nodo *ant=nullptr;
    nodo *aux=cabeza;
    bool bandera=true;
    if(cabeza!=nullptr){
        while(aux and bandera){
        if(ubicacion->getCadena()!=aux->getCadena()){
            ant=aux;
            aux=aux->getSiguiente();
        }
        else{
            bandera=false;
        }
    }

    if(ant==nullptr){
        cout<<"No existen mas elementos..."<<endl;
        return aux;
    }
    else{
        return ant;
    }
    }
    else{
        cout<<"Lista vacia..."<<endl;
        system("pause");
        return nullptr;
    }
}

nodo* lista::siguiente(nodo *ubicacion)
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
        system("pause");
        return ubicacion;
    }

}

int lista::tamanioLista()
{
    return tamanio;
}

void lista::vaciar()
{
    nodo *aux=cabeza;

    if(cabeza!=nullptr){
        while(cabeza!=nullptr){
        aux=cabeza;
        cabeza=cabeza->getSiguiente();
        tamanio--;
        delete aux;
        }
    cout<<"Lista vaciada con exito...";
    }
    else{
        cout<<"Lista vacia..."<<endl;
    }
}
