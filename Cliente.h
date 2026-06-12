/*
 * Black Pearl
 * Saúl Gómez Oñate
 * A01714080
 * 10/06/2026
 * Esta clase define el objeto de tipo Cliente.
 * Cada cliente tiene un nombre, edad, dinero y 
 * estado de embriaguez.
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include "Bebida.h"
using namespace std;

// Se declara la clase Cliente con sus atributos y métodos
class Cliente{
    // Atributos privados de la clase Cliente
    private:
    string nombre;
    int edad;
    double dinero;
    bool ebrio;
    int bebidas_tomadas = 0;

    // Declaración de métodos públicos de la clase
    public: 

    // Constructores, uno default y otro con parámetros
    Cliente(){
        nombre = "";
        edad = 0;
        dinero = 0;
        ebrio = false;
        bebidas_tomadas = 0;
    }

    /** 
     * Cliente
     * 
     * Es el constructor Cliente
     * @param string n, int e, double d, bool eb, int bt
     * @return
     */
    Cliente(string n, int e, double d, bool eb, int bt){
        nombre = n;
        edad = e;
        dinero = d;
        ebrio = eb;
        bebidas_tomadas = bt;
    }

    // Getter de nombre

    string getNombre(){
        return nombre;
    }

    // Getter de edad

    int getEdad(){
        return edad;   
    }

    // Getter de dinero

    double getDinero(){
        return dinero;
    }

    // Getter de estado (ebrio o no)

    bool getEbrio(){
        return ebrio;
    }

    // Getter de bebidas tomadas

    int getBebidasTomadas(){
        return bebidas_tomadas;
    }

    /** mostrarInfo
     * 
     * Este metodo devuelve la informacion de cada cliente, incluye su nombre, dinero, edad, bebidas tomados y estado de embriaguez
     * @return 
     */

    void mostrarInfo(){
        cout << "Nombre: " << nombre << endl;
        cout << "Dinero: $" << dinero << endl;
        cout << "Edad: " << edad << endl;
        cout << "Bebidas consumidas: " << bebidas_tomadas << endl;
        cout << "Ebrio: " << (ebrio ? "Si" : "No") << endl;
    }

    /** pagarBebida
     * 
     * Este metodo permite a un cliente pagar su bebida,
     * si el cliente tiene suficiente dinero, se le descontara el precio de la bebida y se aumentara el contador de bebidas tomadas, 
     * si el cliente ha tomado 4 o mas bebidas, su estado de embriaguez cambiara a verdadero.
     * @param Bebida &b
     * @return 
     */

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