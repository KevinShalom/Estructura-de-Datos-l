#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "nodo.h"
#include "ListaDoble.h"
#include "producto.h"
using namespace std;

int main()
{
    setlocale( LC_ALL, "Spanish" );
    bool continuaPrograma=true;
    int opc;
    ListaDoble *lis=new ListaDoble;
    producto *productoNuevo=new producto;
    nodo *posicion=new nodo(*productoNuevo);
    nodo *busqueda=new nodo(*productoNuevo);
    lis->inicializa();
    do{
        system("cls");
        cout<<"----------MENU----------"<<endl<<endl;
        cout<<"1) Insertar al inicio"<<endl;
        cout<<"2) Insertar al final"<<endl;
        cout<<"3) Eliminar"<<endl;
        cout<<"4) Buscar"<<endl;
        cout<<"5) Lista vacia?"<<endl;
        cout<<"6) Primero"<<endl;
        cout<<"7) Ultimo"<<endl;
        cout<<"8) Anterior"<<endl;
        cout<<"9) Siguiente"<<endl;
        cout<<"10) Tamaño lista"<<endl;
        cout<<"11) Vaciar lista"<<endl;
        cout<<"12) Mostrar lista"<<endl;
        cout<<"13) Ordenar por ID (Insert Sort)"<<endl;
        cout<<"14) Ordenar precio (Select Sort)"<<endl;
        cout<<"15) Ordenar por ID (QuickSort)"<<endl;
        cout<<"16) Ordenar precio (MergeSort)"<<endl;
        cout<<"17) Salir"<<endl;
        cout<<"Selecciona una opcion: ";
        cin>>opc;
        cout<<endl;
        switch(opc){
        case 1:
            cout<<"Cual es el nombre del producto: ";
            cin>>productoNuevo->nombre;
            cout<<"Cual es el precio: ";
            cin>>productoNuevo->precio;
            cout<<"Ingresa el id del producto: ";
            cin>>productoNuevo->id;
            lis->insertarInicio(*productoNuevo);
            break;
        case 2:
            cout<<"Cual es el nombre del producto: ";
            cin>>productoNuevo->nombre;
            cout<<"Cual es el precio: ";
            cin>>productoNuevo->precio;
            cout<<"Ingresa el id del producto: ";
            cin>>productoNuevo->id;
            lis->insertarInicio(*productoNuevo);
            break;
        case 3:
            cout<<"Cual es el nombre del producto: ";
            cin>>productoNuevo->nombre;
            lis->eliminar(*productoNuevo);
            break;
        case 4:
            cout<<"Ingresa un id para buscar: ";
            cin>>productoNuevo->id;
            busqueda=lis->buscar(*productoNuevo);
            cout<<endl;
            if(busqueda!=nullptr){
                cout<<"El dato que contiene su id es: "<<busqueda->getProducto().nombre<<endl;
            }
            break;
        case 5:
            if(lis->vacia()){
                cout<<"Lista vacia..."<<endl;
            }
            else{
                cout<<"Lista con elementos..."<<endl;
            }
            break;
        case 6:
            posicion=lis->primero();
                if(posicion!=nullptr){
                    cout<<"El primer elemento en la lista es: ";
                    cout<<posicion->getProducto().nombre<<endl;
                }
            break;
        case 7:
            posicion=lis->ultimo();
                if(posicion!=nullptr){
                    cout<<"El ultimo elemento en la lista es: ";
                    cout<<posicion->getProducto().nombre<<endl;
                }
            break;
        case 8:
            posicion=lis->anterior(posicion);
            if(posicion!=nullptr){
                    cout<<"El anterior elemento en la lista es: ";
                    cout<<posicion->getProducto().nombre<<endl;
                }
            break;
        case 9:
            posicion=lis->siguiente(posicion);
            if(posicion!=nullptr){
                    cout<<"El siguiente elemento en la lista es: ";
                    cout<<posicion->getProducto().nombre<<endl;
                }
            break;
        case 10:
            cout<<"El tamaño de la lista es: ";
            cout<<lis->tamanioLista()<<endl;
            break;
        case 11:
            lis->vaciar();
            break;
        case 12:
            lis->imprimir();
            break;
        case 13:
            lis->insertSort();
            system("cls");
            cout<<"Productos del id mas alto al mas bajo...."<<endl;
            lis->imprimir();
            break;
        case 14:
            lis->selectSort();
            system("cls");
            cout<<"Productos del mas barato al mas caro...."<<endl;
            lis->imprimir();
            break;
        case 15:
            lis->quickSort(lis);
            system("cls");
            cout<<"Productos del id mas bajo al mas alto...."<<endl;
            lis->imprimir();
            break;
        case 16:
            lis->mergeSort(lis->tamanio,lis);
            system("cls");
            cout<<"Productos del mas caro al mas barato...."<<endl;
            lis->imprimir();
            break;
        case 17:
            continuaPrograma=false;
            break;
        default:
            cout<<"Opcion no valida..."<<endl;
            break;
        }
        cout<<endl;
        system("pause");
    }while(continuaPrograma);
    return 0;
}
