#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
using namespace std;

class Animal
{
    public:
        string nombre;
        string raza;
        int id;

        Animal(string nom,string raz){
            nombre=nom;
            raza=raz;
            id++;
        }
        Animal(){
            nombre="";
            raza="";
            id=0;
        };

    private:
};

#endif // ANIMAL_H
