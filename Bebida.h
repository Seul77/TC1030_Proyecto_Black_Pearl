/*
 * Black Pearl
 * Saúl Gómez Oñate
 * A01714080
 * 10/06/2026
 * Esta clase define el objeto de tipo Bebida.
 * Cada bebida tiene un nombre, precio y grado de alcohol.
 */

#ifndef BEBIDA_H
#define BEBIDA_H

#include <iostream>
using namespace std;

// Se declara la clase Bebida con sus atributos y métodos
class Bebida{
    // Atributos privados de la clase Bebida
    private:
    string nombre;
    double precio;
    float grado_alcohol;

    // Declaración de métodos públicos de la clase
    public:

    // Constructores para bebida, uno por defecto y otro con parámetros
    Bebida(){
        nombre = "";
        precio = 0.0;
        grado_alcohol = 0.0;
    }

    /** Bebida
     * 
     * Este constructor de bebida recibe su nombre, precio y grado de alcohol.
     * @param string n, double p, float g
     * @return
     */
    
    Bebida(string n, double p, float g){
        nombre = n;
        precio = p;
        grado_alcohol = g;
    }

    // Getter de nombre
    string getNombre(){
        return nombre;
    }

    // Getter de precio
    double getPrecio(){
        return precio;
    }

    // Getter de grado de alcohol
    float getGradoAlcohol(){
        return grado_alcohol;
    }

    /** mostrarInfo
     * 
     * Este metodo muestra la informacion de cada bebida, incluyendo su nombre,
     * precio, y grado de alcohol
     * 
     * @return
     */
    void mostrarInfo(){
        cout << "\nNombre: " << nombre << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Grado de alcohol: " << grado_alcohol << "%" << endl;
    }


};

#endif