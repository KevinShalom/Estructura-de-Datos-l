#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include "nodo.h"
#include "ListaDoble.h"
#include "Animal.h"
#define TAMANIOCADENA 50

using namespace std;

enum{INSERTARI=1,INSERTARF,ELIMINAR,BUSCAR,VACIA,PRIMERO,ULTIMO,ANTERIOR,SIGUIENTE,TAMANIO,VACIAR,
MOSTRAR,SALIR};

int main()
{
    setlocale( LC_ALL, "Spanish" );
    bool continuaPrograma=true;
    int opcionMenu,i=0;
    char animalIngresado[TAMANIO];
    ListaDoble *lis=new ListaDoble;
    Animal *animalNuevo=new Animal;
    nodo *posicion=new nodo(*animalNuevo);
    nodo *busqueda=new nodo(*animalNuevo);
    lis->inicializa();
    do{
        system("cls");
        cout<<"-------Menu------"<<endl<<endl;
        cout<<"1) Insertar al inicio"<<endl;
        cout<<"2) Insertar (Inicializa)"<<endl;
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
        cout<<"13) Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcionMenu;
        cout<<endl;
        switch(opcionMenu){
        case INSERTARI:
            cout<<"Cual es el nombre del animal: ";
            cin>>animalNuevo->nombre;
            cout<<"Cual es la raza: ";
            cin>>animalNuevo->raza;
            i++;
            animalNuevo->id=i;
            lis->insertarInicio(*animalNuevo);
            break;
        case INSERTARF:
            cout<<"El nombre del animal: ";
            cin>>animalNuevo->nombre;
            cout<<"Cual es la raza: ";
            cin>>animalNuevo->raza;
            i++;
            animalNuevo->id=i;
            lis->insertarFinal(*animalNuevo);
            break;
        case ELIMINAR:
            cout<<"Cual es el nombre del animal: ";
            cin>>animalNuevo->nombre;
            lis->eliminar(*animalNuevo);
            i--;
            animalNuevo->id=i;
            break;
        case BUSCAR:
            cout<<"Ingresa un id para buscar: ";
            cin>>animalNuevo->id;
            busqueda=lis->buscar(*animalNuevo);
            cout<<endl;
            if(busqueda!=nullptr){
                cout<<"El dato que contiene su id es: "<<busqueda->getAnimal().nombre<<" Raza: "<<busqueda->getAnimal().raza<<endl;
            }
            break;
        case VACIA:
            if(lis->vacia()){
                cout<<"Lista vacia..."<<endl;
            }
            else{
                cout<<"Lista con elementos..."<<endl;
            }
            break;
        case PRIMERO:
            posicion=lis->primero();
                if(posicion!=nullptr){
                    cout<<"El primer elemento en la lista es: ";
                    cout<<posicion->getAnimal().nombre<<endl;
                }
            break;
        case ULTIMO:
            posicion=lis->ultimo();
                if(posicion!=nullptr){
                    cout<<"El ultimo elemento en la lista es: ";
                    cout<<posicion->getAnimal().nombre<<endl;
                }
            break;
        case ANTERIOR:
            posicion=lis->anterior(posicion);
            if(posicion!=nullptr){
                    cout<<"El anterior elemento en la lista es: ";
                    cout<<posicion->getAnimal().nombre<<endl;
                }
            break;
        case SIGUIENTE:
            posicion=lis->siguiente(posicion);
            if(posicion!=nullptr){
                    cout<<"El siguiente elemento en la lista es: ";
                    cout<<posicion->getAnimal().nombre<<endl;
                }
            break;
        case TAMANIO:
            cout<<"El tamaño de la lista es: ";
            cout<<lis->tamanioLista()<<endl;
            break;
        case VACIAR:
            lis->vaciar();
            break;
        case MOSTRAR:
            cout<<"-----DATOS GUARDADOS-----"<<endl;
            lis->imprimir();
            break;
        case SALIR:
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
