#ifndef BLACKPEARLN_H
#define BLACKPEARLN_H

#include <iostream>
#include <vector>
#include "ClienteN.h"
#include "EmpleadoN.h"
#include "BebidaN.h"
using namespace std;

class BlackPearl {
    private:
    vector<Cadenero> cadeneros;
    vector<DJ> djs;
    vector<Bartender> bartenders;
    vector<Cliente> clientes;
    vector<Bebida> bebidas;

    public:
    BlackPearl(vector<Cadenero> ca, vector<DJ> dj, vector<Bartender> ba, vector<Cliente> cl, vector<Bebida> be) {
        cadeneros = ca;
        djs = dj;
        bartenders = ba;
        clientes = cl;
        bebidas = be;
    }

    void mostrarEmpleados() {
        cout << "Lista de empleados:" << endl;
        int indice = 1;
        for (int i = 0; i < cadeneros.size(); i++) {
            cout << indice << ". ";
            cadeneros[i].mostrarInfo();
            cout << endl;
            indice++;
        }
        for (int i = 0; i < djs.size(); i++) {
            cout << indice << ". ";
            djs[i].mostrarInfo();
            cout << endl;
            indice++;
        }
        for (int i = 0; i < bartenders.size(); i++) {
            cout << indice << ". ";
            bartenders[i].mostrarInfo();
            cout << endl;
            indice++;
        }
    }

    void mostrarClientes() {
        cout << "Lista de clientes:" << endl;
        for (int i = 0; i < clientes.size(); i++)
            cout << i+1 << ". " << clientes[i].getNombre() << ", Edad: " << clientes[i].getEdad() << ", " << (clientes[i].getEbrio() ? "Ebrio" : "Sobrio") << endl;
    }

    void mostrarBebidas() {
        cout << "Lista de bebidas:" << endl;
        for (int i = 0; i < bebidas.size(); i++)
            cout << "- " << bebidas[i].getNombre() << ": $" << bebidas[i].getPrecio() << ", " << bebidas[i].getGradoAlcohol() << "%" << endl;
    }
};

#endif