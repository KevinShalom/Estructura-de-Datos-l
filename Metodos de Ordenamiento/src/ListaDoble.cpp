#include "ListaDoble.h"

void ListaDoble::inicializa()
{
    cabeza=nullptr;
    cola=nullptr;
    tamanio=0;
}

void ListaDoble::insertarInicio(producto productoIngresado)
{
    nodo* temp=new nodo(productoIngresado);
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

void ListaDoble::insertarFinal(producto productoIngresado)
{
    nodo* temp=new nodo(productoIngresado);
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
            cout<<"Producto: "<<aux->getProducto().nombre<<" Precio: "<<aux->getProducto().precio;
            cout<<" Id: "<<aux->getProducto().id;
            aux=aux->getSiguiente();
            cout<<endl;
        }
    }
    cout<<endl;
}

void ListaDoble::eliminar(producto productoIngresado)
{
    nodo *aux=cabeza;
    bool bandera=true;
    if(cabeza!=nullptr){
        while(aux and bandera){
            if(aux->getProducto().nombre==productoIngresado.nombre){
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

nodo* ListaDoble::buscar(producto productoIngresado)
{
    nodo *aux=cabeza;
    if(aux==nullptr){
       cout<<"Lista vacia..."<<endl;
    }
    else{
         while(aux!=nullptr){
            if(aux->getProducto().id==productoIngresado.id){
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

void ListaDoble::insertSort()
{
    if(cabeza!=nullptr){
       nodo *aux=cabeza->getSiguiente();
       bool bandera;
       while(aux){
        bandera=true;
        producto temp=aux->getProducto();
        nodo *auxAnt=aux->getAnterior();
        while(auxAnt and bandera){
            if(auxAnt->getProducto().id<temp.id){
                auxAnt->getSiguiente()->setProducto(auxAnt->getProducto());
                auxAnt->setProducto(temp);
            }
            else{
                bandera=false;
            }
            auxAnt=auxAnt->getAnterior();
        }
        aux=aux->getSiguiente();
    }
    }
}

void ListaDoble::selectSort()
{
    nodo *aux=cabeza;
    nodo *menor=cabeza;
    nodo *posicion=cabeza;
    producto temp;
    while(posicion){
        aux=posicion;
        menor=posicion;
        while(aux){
            if(menor->getProducto().precio > aux->getProducto().precio){
                menor=aux;
            }
            aux=aux->getSiguiente();
        }
        temp=posicion->getProducto();
        posicion->setProducto(menor->getProducto());
        menor->setProducto(temp);
        posicion=posicion->getSiguiente();
    }
}

void ListaDoble::quickSort(ListaDoble *lis)
{
    nodo *pivote;
    nodo *pivoteGuardado;
    nodo *aux;
    ListaDoble *arriba=new ListaDoble;
    ListaDoble *abajo=new ListaDoble;
    if(lis->cabeza){
        pivote=lis->cabeza;
        pivoteGuardado=new nodo(lis->cabeza->getProducto());
        aux=lis->cabeza->getSiguiente();
        while(aux){
            if(aux->getProducto().id<pivote->getProducto().id){
                abajo->insertarInicio(aux->getProducto());
            }
            else{
                arriba->insertarInicio(aux->getProducto());
            }
            aux=aux->getSiguiente();
        }
        quickSort(arriba);
        quickSort(abajo);

        aux=lis->cabeza;
        nodo *aba=abajo->cabeza;
        while(aba){
            aux->setProducto(aba->getProducto());
            aux=aux->getSiguiente();
            aba=aba->getSiguiente();
        }

        aux->setProducto(pivoteGuardado->getProducto());
        aux=aux->getSiguiente();

        nodo *arri=arriba->cabeza;
        while(arri){
            aux->setProducto(arri->getProducto());
            aux=aux->getSiguiente();
            arri=arri->getSiguiente();
        }
    }
}

void ListaDoble::mergeSort(int tam,ListaDoble *lis)
{
    ListaDoble *derecha=new ListaDoble;
    ListaDoble *izquierda=new ListaDoble;
    nodo *aux=lis->cabeza;
    int media=tam/2;
    int diferencia=tam%2;
    int i,j;
    if(lis->tamanio>1){
        i=0;
        while(aux and i<media){
            izquierda->insertarInicio(aux->getProducto());
            i++;
            aux=aux->getSiguiente();
        }
        j=0;
        while(aux and j<media+diferencia){
            derecha->insertarInicio(aux->getProducto());
            j++;
            aux=aux->getSiguiente();
        }
        mergeSort(izquierda->tamanio,izquierda);
        mergeSort(derecha->tamanio,derecha);
        nodo *iz=izquierda->cabeza;
        nodo *de=derecha->cabeza;
        aux=lis->cabeza;
        i=0;
        while(iz and de){
            if(iz->getProducto().precio > de->getProducto().precio){
                aux->setProducto(iz->getProducto());
                iz=iz->getSiguiente();
                aux=aux->getSiguiente();
            }
            else{
                aux->setProducto(de->getProducto());
                de=de->getSiguiente();
                aux=aux->getSiguiente();
            }
        }
        if(iz){
            while(iz){
                aux->setProducto(iz->getProducto());
                iz=iz->getSiguiente();
                aux=aux->getSiguiente();
            }
        }
        if(de){
            while(de){
               aux->setProducto(de->getProducto());
                de=de->getSiguiente();
                aux=aux->getSiguiente();
            }
        }
    }

}

