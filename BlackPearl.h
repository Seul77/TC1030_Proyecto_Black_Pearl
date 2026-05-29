#ifndef BLACKPEARL_H
#define BLACKPEARL_H

#include <iostream>
using namespace std;
#include "Cliente.h"
#include "Empleado.h"
#include "Bebida.h"


class BlackPearl{
    private:
    Cadenero* cadeneros[2];
    DJ* djs[2];
    Bartender* bartenders[2];
    Cliente* clientes[4];
    Bebida* bebidas[8];

    public: 
    BlackPearl(Cadenero* c[2], DJ* d[2], Bartender* b[2], Cliente* cl[4], Bebida* be[8]){
        for (int i = 0; i < 2; i++){
            cadeneros[i] = c[i];
        }
        for (int i = 0; i < 2; i++){
            djs[i] = d[i];
        }
        for (int i = 0; i < 2; i++){
            bartenders[i] = b[i];
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
        for (Cadenero* c : cadeneros){
            c->mostrarInfo();
            cout << endl;}
        for (DJ* d : djs){
            d->mostrarInfo();
            cout << endl;}
        for (Bartender* b : bartenders){
            b->mostrarInfo();
            cout << endl;}
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