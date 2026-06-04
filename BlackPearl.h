#ifndef BLACKPEARL_H
#define BLACKPEARL_H

#include <iostream>
using namespace std;
#include "Cliente.h"
#include "Empleado.h"
#include "Bebida.h"


class BlackPearl{
    private:
    Empleado* empleados[6];
    Cliente* clientes[4];
    Bebida* bebidas[8];

    public: 
    BlackPearl(Empleado* e[6], Cliente* cl[4], Bebida* be[8]){
        for (int i = 0; i < 6; i++){
            empleados[i] = e[i];
        }
        for (int i = 0; i < 4; i++){
            clientes[i] = cl[i];
        }
        for (int i = 0; i < 8; i++){
            bebidas[i] = be[i];
        }
    }

    void mostrarEmpleados(){
        cout << "Lista de empleados:" << endl;
        for (Empleado* e : empleados){
            e->mostrarInfo();
            cout << endl;
        }
    }

    void mostrarClientes(){
        cout << "Lista de clientes:" << endl;
        int indice = 1;
        for (Cliente* c : clientes){
            cout << indice << ". " << c->getNombre() << ", Edad: " << c->getEdad() << ",  " << (c->getEbrio() ? "Ebrio" : "Sobrio") << endl;
            indice++;
        }
    }

    void mostrarBebidas(){
        cout << "Lista de bebidas:" << endl;
        for (Bebida* b : bebidas){
            b->mostrarInfo();
        }
    }

};

#endif
