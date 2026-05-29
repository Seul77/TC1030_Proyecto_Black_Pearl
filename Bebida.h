#ifndef BEBIDA_H
#define BEBIDA_H

#include <iostream>
using namespace std;

class Bebida{
    private:
    string nombre;
    double precio;
    float grado_alcohol;

    public:
    Bebida(){
        nombre = "";
        precio = 0.0;
        grado_alcohol = 0.0;
    }
    Bebida(string n, double p, float g, int ){
        nombre = n;
        precio = p;
        grado_alcohol = g;
    }

    string getNombre(){
        return nombre;
    }
    double getPrecio(){
        return precio;
    }
    float getGradoAlcohol(){
        return grado_alcohol;
    }

    void mostrarInfo(){
        cout << "\nNombre: " << nombre << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Grado de alcohol: " << grado_alcohol << "%" << endl;
    }


};

#endif