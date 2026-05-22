#ifndef CLIENTEN_H
#define CLIENTEN_H

#include <iostream>
using namespace std;

class Cliente{
    private:
    string nombre;
    int edad;
    double dinero;
    bool ebrio;


    public: 
    Cliente(){
        nombre = "";
        edad = 0;
        dinero = 0;
        ebrio = false;
    }

    Cliente(string n, int e, double d, bool eb){
        nombre = n;
        edad = e;
        dinero = d;
        ebrio = eb;
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

    void mostrarInfo(){
        cout << "Nombre: " << nombre << endl;
        cout << "Dinero: $" << dinero << endl;
        cout << "Ebrio: " << (ebrio ? "Sí" : "No") << endl;
    }

    void pagarBebida(Bebida b){
        if (dinero >= b.getPrecio()){
            dinero -= b.getPrecio();
            cout << nombre << " ha pagado $" << b.getPrecio() << " por un " << b.getNombre() << ". " << endl;
            
        } else {
            cout << nombre << " no tiene lo suficiente para comprar " << b.getNombre() << "." << endl;
        }
    }

};

#endif
