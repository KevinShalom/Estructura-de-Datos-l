#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
using namespace std;

class Animal
{
    public:
        string nombre;
        string raza;

        Animal(string nombre1,string raza1){
            nombre=nombre1;
            raza=raza1;
        }
        Animal(){
            nombre="";
            raza="";
        };

    protected:

    private:
};

#endif // ANIMAL_H
