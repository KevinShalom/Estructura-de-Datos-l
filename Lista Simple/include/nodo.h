#ifndef NODO_H
#define NODO_H

#include <string>
using namespace std;

class nodo
{
    public:
        nodo();
        nodo(string cadingresada){
            cadena=cadingresada;
            siguiente=nullptr;
        }
        nodo(string cadingresada,nodo *temp){
            cadena=cadingresada;
            siguiente=temp;
        }
        string getCadena();
        void setCadena(string);

        nodo* getSiguiente();
        void setSiguiente(nodo*);

    private:
        string cadena;
        nodo *siguiente;
};

#endif // NODO_H
