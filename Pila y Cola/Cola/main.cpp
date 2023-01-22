#include <iostream>
#include <string>
#include <cstdlib>
#include "Animal.h"
#include "nodo.h"
#include "cola.h"
using namespace std;
int main()
{
    setlocale( LC_ALL, "Spanish" );
    bool continuar =true;
    int OPC;
    Animal *Animalnuevo=new Animal;
    cola *cola1=new cola;
    nodo *primero=new nodo(*Animalnuevo);
    nodo *ultimo=new nodo(*Animalnuevo);
    cola1->inicializa();
    do{
        system("cls");
        cout<<"------MENU------"<<endl<<endl;
        cout<<"1) Insertar (enqueue)"<<endl;
        cout<<"2) Eliminar (dequeue)"<<endl;
        cout<<"3) Primero"<<endl;
        cout<<"4) Ultimo"<<endl;
        cout<<"5) Vacia?"<<endl;
        cout<<"6) Tamaño de la cola"<<endl;
        cout<<"7) Vaciar"<<endl;
        cout<<"8) Mostrar cola"<<endl;
        cout<<"9) Salir"<<endl;
        cout<<"Opcion: ";
        cin>>OPC;
        system("cls");
        switch(OPC){
        case 1:
            cout<<"--REGISTRO--"<<endl;
            cout<<"Nombre: ";
            cin>>Animalnuevo->nombre;
            cout<<"Raza: ";
            cin>>Animalnuevo->raza;
            cola1->insertar(*Animalnuevo);
            break;
        case 2:
            cola1->dequeue();
            break;
        case 3:
            primero=cola1->first();
            if(primero!=nullptr){
                cout<<"El primero es: "<<primero->getAnimal().nombre<<endl<<endl;
            }
            else{
                cout<<"Cola vacia..."<<endl<<endl;
            }
            break;
        case 4:
            ultimo=cola1->last();
            if(ultimo!=nullptr){
                cout<<"El ultimo es: "<<ultimo->getAnimal().nombre<<endl<<endl;
            }
            else{
                cout<<"Cola vacia..."<<endl<<endl;
            }
            break;
        case 5:
            if(cola1->vacia()){
                cout<<"Cola con datos..."<<endl<<endl;
            }
            else{
                cout<<"Cola Vacia..."<<endl<<endl;
            }
            break;
        case 6:
            cout<<"El tamaño de la cola es: ";
            cout<<cola1->tamanioCola()<<endl<<endl;
            break;
        case 7:
            cola1->vaciar();
            break;
        case 8:
            cola1->mostrarCola();
            break;
        case 9:
            continuar=false;
            break;
        default:
            cout<<"Opcion no valida..."<<endl<<endl;
            break;
        }
        system("pause");
    }while(continuar);
    return 0;
}

