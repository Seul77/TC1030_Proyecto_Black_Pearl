/*
 * Black Pearl
 * Saúl Gómez Oñate
 * A01714080
 * 10/06/2026
 * Esta clase define el objeto de tipo
 * BlackPearl, que es el antro que contiene
 * a los empleados, clientes y bebidas.
 */

#ifndef BLACKPEARL_H
#define BLACKPEARL_H

#include <iostream>
using namespace std;

// Se incluyen las clases de Cliente, Empleado y Bebida para ser utilizadas en la clase BlackPearl
#include "Cliente.h"
#include "Empleado.h"
#include "Bebida.h"

// Se declara la clase BlackPearl
class BlackPearl{
    // Atributos privados de la clase 
    private:
    Empleado* empleados[6]; // Arreglo de punteros a empleados
    Cliente* clientes[4]; // Arreglo de punteros a clientes
    Bebida* bebidas[8]; // Arreglo de punteros a bebidas
    int numClientes = 4; // Contador de clientes actuales en el antro

    // Se declaran los metodos publicos de la clase
    public: 
    /** BlackPearl
     * 
     * El costructor recibe como parametros los arreglos de punteros a empleados, clientes y bebidas
     * 
     * @param Empleado* e, Cliente* cl, Bebida* be
     * @return
     */
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

    // Getter de numero de clientes
    int getNumClientes(){ 
        return numClientes; 
    }

    /** mostrarEmpleados
     * 
     * Este metodo muestra a los empleados en forma de lista y para cada uno su respectiva informacion
     * @return 
     */
    void mostrarEmpleados(){
        cout << "Lista de empleados:" << endl;
        for (Empleado* e : empleados){
            e->mostrarInfo(); // Se llama al metodo mostrarInfo de cada empleado
            cout << endl;
        }
    }

    /** mostrarClientes
     * 
     * Este metodo muestra a los clientes en forma de lista y su respectiva informacion
     * @return 
     */

    void mostrarClientes(){
    cout << "Lista de clientes:" << endl;
    for (int i = 0; i < numClientes; i++){
        cout << i+1 << ". " << clientes[i]->getNombre() << ", Edad: " << clientes[i]->getEdad() << ",  " << (clientes[i]->getEbrio() ? "Ebrio" : "Sobrio") << endl;
    }
}

    /** mostrarBebidas
     * 
     * Este metodo muestra a las bebidas en forma de lista con la respectiva informacion de cada una
     * 
     * @return
     */
    void mostrarBebidas(){
        cout << "Lista de bebidas:" << endl;
        for (Bebida* b : bebidas){
            b->mostrarInfo(); // Se llama al metodo mostrarInfo de cada bebida
        }
    }

    /** eliminarCliente
     * 
     * Este metodo es usado en caso de que un cliente sea expulsado por el cadenero, el cual elimina al cliente seleccionado
     * de la lista de clientes actuales en el antro
     * 
     * @param int indice
     * @return
     */
    void eliminarCliente(int indice){
    delete clientes[indice];
    for (int j = indice; j < numClientes - 1; j++){
        clientes[j] = clientes[j + 1];
    }
    numClientes--;
}
};

#endif