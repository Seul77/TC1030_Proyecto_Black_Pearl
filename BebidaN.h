#ifndef BEBIDAN_H
#define BEBIDAN_H

#include <iostream>
using namespace std;
#include <vector>

class Bebida{
    private:
    string nombre;
    vector<string> bebidas;
    double precio;
    float grado_alcohol;
    int stock;

    public:
    Bebida(){
        nombre = "";
        precio = 0.0;
        grado_alcohol = 0.0;
        stock = 0;
    }
    Bebida(string n, double p, float g, int s){
        nombre = n;
        precio = p;
        grado_alcohol = g;
        stock = s;
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
    int getStock(){
        return stock;
    }

    void mostrarBebidas(){
        cout << "Lista de bebidas: " << endl;
        int indice = 1;
        for (string b : bebidas){
            cout << indice << ". " << b << endl;
            indice++;
        }
    }
};

#endif