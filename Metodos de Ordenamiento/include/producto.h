#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
using namespace std;

class producto
{
    public:
        string nombre;
        float precio;
        int id;

        producto(string nombre1,float precio1,int i){
            nombre=nombre1;
            precio=precio1;
            id=i;
        }
        producto(){
            nombre="";
            precio=0;
            id=0;
        };
};

#endif // PRODUCTO_H
