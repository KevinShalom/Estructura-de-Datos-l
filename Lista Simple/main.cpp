//lista programa 1
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "nodo.h"
#include "lista.h"
#define CADENA 100

using namespace std;

int main()
{
    bool Lvacia;
    int opc = 0;
    char palabra[CADENA];
    lista *lis=new lista;
    nodo *posicion=new nodo;
    nodo *busqueda=new nodo;
    lis->inicializa();
    do
    {
        system("cls");
        system("color 0B");
        setlocale( LC_ALL, "Spanish" );
        cout<<"-----MENU PRINCIPAL-----"<<endl<<endl;
        cout<<"1) Insertar"<<endl;
        cout<<"2) Eliminar"<<endl;
        cout<<"3) Buscar"<<endl;
        cout<<"4) Lista vacia?"<<endl;
        cout<<"5) Inicializa "<<endl;
        cout<<"6) Primero en la lista"<<endl;
        cout<<"7) Ultimo en la lista"<<endl;
        cout<<"8) Anterior en la lista"<<endl;
        cout<<"9) Siguiente en la lista"<<endl;
        cout<<"10) Tamaño de la lista"<<endl;
        cout<<"11) Vaciar la lista"<<endl;
        cout<<"12) Mostrar toda lista"<<endl;
        cout<<"13) Salir"<<endl;
        cout<<"Escoja una opcion: ";
        cin>>opc;
        cout<<endl;
        switch(opc)
        {
        case 1:
            system("cls");
            system("color 0E");
            cout<<endl;
            cout<<"Ingresa una palabra o numeros: ";
            cin.ignore();
            cin.getline(palabra,CADENA);
            lis->insertarInicio(palabra);
            cout<<"Dato guardado..."<<endl;
            system("pause");
            break;
        case 2:
            system("cls");
            system("color 0E");
            cout<<endl;
            cout<<"Ingresa la palabra o numero para eliminar: ";
            cin.ignore();
            cin.getline(palabra,CADENA);
            lis->eliminar(palabra);
            system("pause");
            break;
        case 3:
            system("cls");
            system("color 0E");
            cout<<endl;
            cout<<"Ingresa la palabra o numero para buscar: ";
            cin.ignore();
            cin.getline(palabra,CADENA);
            busqueda=lis->buscar(palabra);
            cout<<endl;
            if(busqueda!=nullptr)
            {
                cout<<"Dato encontrado: "<<busqueda->getCadena()<<endl;
            }
            system("pause");
            break;
        case 4:
            Lvacia=lis->vacia();
            if(Lvacia)
            {
                system("cls");
                system("color 0E");
                cout<<endl;
                cout<<"Lista sin elementos..."<<endl;
                system("pause");
            }
            else
            {
                system("cls");
                system("color 0E");
                cout<<endl;
                cout<<"Lista con elementos..."<<endl;
                system("pause");
            }
            break;
        case 5:
            system("cls");
            system("color 0E");
            cout<<endl;
            cout<<"Ingresa una palabra o numeros: ";
            cin.ignore();
            cin.getline(palabra,CADENA);
            lis->insertarFinal(palabra);
            cout<<"Dato guardado..."<<endl;
            system("pause");
            break;

        case 6:
            posicion=lis->primero();
            if(posicion!=nullptr)
            {
                system("cls");
                system("color 0E");
                cout<<endl;
                cout<<"El primer elemento registrado: ";
                cout<<posicion->getCadena()<<endl;
                system("pause");
            }
            break;
        case 7:
            posicion=lis->ultimo();
            if(posicion!=nullptr)
            {
                system("cls");
                system("color 0E");
                cout<<endl;
                cout<<"El ultimo elemento registrado: ";
                cout<<posicion->getCadena()<<endl;
                system("pause");
            }
            break;
        case 8:
            posicion=lis->anterior(posicion);
            if(posicion!=nullptr)
            {
                system("cls");
                system("color 0E");
                cout<<endl;
                cout<<"El anterior elemento registrado: ";
                cout<<posicion->getCadena()<<endl;
                system("pause");
            }
            break;
        case 9:
            posicion=lis->siguiente(posicion);
            if(posicion!=nullptr)
            {
                system("cls");
                system("color 0E");
                cout<<endl;
                cout<<"El siguiente elemento registrado: ";
                cout<<posicion->getCadena()<<endl;
                system("pause");
            }
            break;
        case 10:
            system("cls");
            system("color 0E");
            cout<<endl;
            cout<<"El total de elementos registrados en la lista es de: ";
            cout<<lis->tamanioLista()<<endl;
            system("pause");
            break;
        case 11:
            system("cls");
            system("color 0E");
            cout<<endl;
            lis->vaciar();
            system("pause");
            break;
        case 12:
            system("cls");
            system("color 0E");
            cout<<endl;
            cout<<"------Elementos Registrados de la Lista-----"<<endl;
            lis->imprimir();
            system("pause");
            break;
        case 13:
            cout<<"Finalizando..."<<endl;
            break;
        default:
            cout<<"Dato invalido...."<<endl;
            break;
        }
        cout<<endl;
    }
    while(opc!=13);
system("pause");
    return 0;
}
