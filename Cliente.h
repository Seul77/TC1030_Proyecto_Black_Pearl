#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "Bebida.h"
using namespace std;

class Cliente{
    private:
    string nombre;
    int edad;
    double dinero;
    bool ebrio;
    int bebidas_tomadas = 0;


    public: 
    Cliente(){
        nombre = "";
        edad = 0;
        dinero = 0;
        ebrio = false;
        bebidas_tomadas = 0;
    }

    Cliente(string n, int e, double d, bool eb, int bt){
        nombre = n;
        edad = e;
        dinero = d;
        ebrio = eb;
        bebidas_tomadas = bt;
    }

    string getNombre(){
        return nombre;
    }

    int getEdad(){
        return edad;   
    }

    double getDinero(){
        return dinero;
    }

    bool getEbrio(){
        return ebrio;
    }

    int getBebidasTomadas(){
        return bebidas_tomadas;
    }

    void mostrarInfo(){
        cout << "Nombre: " << nombre << endl;
        cout << "Dinero: $" << dinero << endl;
        cout << "Edad: " << edad << endl;
        cout << "Bebidas consumidas: " << bebidas_tomadas << endl;
        cout << "Ebrio: " << (ebrio ? "Si" : "No") << endl;
    }


    void pagarBebida(Bebida &b){
        if (dinero >= b.getPrecio()){
            dinero -= b.getPrecio();
            cout << nombre << " ha pagado $" << b.getPrecio() << " por un " << b.getNombre() << ". " << endl;
            bebidas_tomadas++;
            if (bebidas_tomadas >= 4) {
                ebrio = true;
            }
            cout << nombre << " ahora tiene $" << dinero << ", ha tomado " << bebidas_tomadas << " bebidas y ahora esta " << (ebrio ? "ebrio" : "sobrio") << "." << endl;
        } else {
            cout << nombre << " no tiene lo suficiente para comprar " << b.getNombre() << "." << endl;
        }
    }


};

#endif