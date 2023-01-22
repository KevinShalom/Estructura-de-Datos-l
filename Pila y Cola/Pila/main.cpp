#include <iostream>
#include <string>
#include "Animal.h"
#include "nodo.h"
#include "pila.h"
using namespace std;
int main()
{
    setlocale( LC_ALL, "Spanish" );
    bool continua = true;
    int OPC;
    Animal *Animalnuevo = new Animal;
    pila *pila1=new pila;
    nodo *tope=new nodo(*Animalnuevo);
    pila1->inicializa();
    do{
        system("cls");
        cout<<"------MENU------"<<endl<<endl;
        cout<<"1) Insertar (Push)"<<endl;
        cout<<"2) Eliminar Tope (Pop)"<<endl;
        cout<<"3) Mostrar tope"<<endl;
        cout<<"4) Esta vacia (Is Empty)"<<endl;
        cout<<"5) Tamaño de la pila"<<endl;
        cout<<"6) Vaciar"<<endl;
        cout<<"7) Mostrar pila"<<endl;
        cout<<"8) Salir"<<endl;
        cout<<"Opcion: ";
        cin>>OPC;
        system("cls");
        switch(OPC){
        case 1:
            cout<<"Nuevo Animal"<<endl;
            cout<<"Nombre: ";
            cin>>Animalnuevo->nombre;
            cout<<"Raza: ";
            cin>>Animalnuevo->raza;
            pila1->push(*Animalnuevo);
            break;
        case 2:
            pila1->pop();
            break;
        case 3:
            tope=pila1->mostrarTope();
            if(tope!=nullptr){
                cout<<"El tope es: "<<tope->getAnimal().nombre<<endl<<endl;
            }
            break;
        case 4:
            if(pila1->vacia()){
                cout<<"Pila con datos..."<<endl<<endl;
            }
            else{
                cout<<"Pila Vacia..."<<endl<<endl;
            }
            break;
        case 5:
            cout<<"El tamaño es: ";
            cout<<pila1->tamanioPila()<<endl<<endl;
            break;
        case 6:
            pila1->vaciar();
            break;
        case 7:
            pila1->mostrarPila();
            break;
        case 8:
            continua = false;
            break;
        default:
            cout<<"Opcion no existente..."<<endl<<endl;
            break;
        }
        system("pause");
    }while(continua);
    return 0;
}
