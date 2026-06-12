/*
 * Black Pearl
 * Saúl Gómez Oñate
 * A01714080
 * 10/06/2026
 * Esta clase define el objeto de tipo Empleado.
 * Cada empleado tiene un nombre, ID, salario, turno 
 * y puesto. Tambien contiene las clases heredadas
 * de Cadenero, DJ y Bartender. Aquí se definen las 
 * funciones de cada clase.
 */

#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
using namespace std;

// Se declara la clase Empleado
class Empleado{
    // Atributos protegidos de la clase Empleado, para ser heredados por las clases hijas
    protected: 
    string nombre;
    int ID;
    double salario;
    string turno;
    string puesto;

    // Se declaran los metodos para la clase
    public:
    Empleado(){
        nombre = "";
        ID = 0;
        salario = 0.0;
        turno = "";
        puesto = "";
    }

    /** 
     * Empleado
     * 
     * El constructor recibe de parametros el nombre, ID, salario, turno y puesto del empleado
     * @param string n, int id, double s, string t, string p
     */
    Empleado(string n, int id, double s, string t, string p){
        nombre = n;
        ID = id;
        salario = s;
        turno = t;
        puesto = p;
    }

    // Getters de nombre
    string getNombre(){
        return nombre;
    }

    // Getter de ID
    int getID(){
        return ID;
    }

    // Getter de salario
    virtual double getSalario(){
        return salario;
    }

    // Getter de turno
    string getTurno(){
        return turno;
    }

    // Getter de puesto
    string getPuesto(){
        return puesto;
    }

    // Metodo virtual que sera sobreescrito por las clases hijas para mostrar la informacion de cada empleado
    virtual void mostrarInfo() = 0;
};

    // Clase cadenero que hereda de Empleado
class Cadenero : public Empleado{
    // Atributos privados de la clase hija
    private:
    double peso;

    // Metodos publicos de la clase
    public:
    Cadenero() : Empleado ("", 0, 0.0, "", "Cadenero") {}; // Constructor por default

    /** Cadenero
     * 
     * El constructor del cadenero recibe su nombre, ID, salario, turno, puesto y peso
     * @param string n, int id, double s, string t, double p
     * @return
     * 
     */
    Cadenero(string n, int id, double s, string t, double p) : Empleado(n, id, s, t, "Cadenero") {
        peso = p;
    }

    /** expulsarCliente
     * 
     * Este metodo se usa para cuando un cadenero revise a un cliente, si esta ebrio o es menor de edad, el cadenero
     * lo expulsa del antro y el metodo devuelve verdadero, si el cliente no tiene problemas, el metodo devuelve falso
     * @param Cliente &c
     * @return bool
     */
    bool expulsarCliente(Cliente &c){
        if (c.getEbrio()){
            cout << "El cadenero " << nombre << " ha expulsado al cliente " << c.getNombre() << " por estar ebrio." << endl;
            return true;
        }

        else if (c.getEdad() < 18){
            cout << "El cadenero " << nombre << " ha expulsado al cliente " << c.getNombre() << " por ser menor de edad." << endl;
            return true;
        }
        else {
            cout << "El cadenero " << nombre << " ha revisado al cliente " << c.getNombre() << " y no encontro problemas." << endl;
            return false;
        }
    }

    /** mostrarInfo
     * 
     * Este metodo muestra la informacion del cadenero
     * Imprime su nombre, ID, salario, turno, puesto y peso
     * @return
     */
    void mostrarInfo(){
        cout << "Nombre: " << getNombre() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Salario: $" << getSalario() << endl;
        cout << "Turno: " << getTurno() << endl;
        cout << "Puesto: " << getPuesto() << endl;
        cout << "Peso: " << peso << " kg" << endl;
    }
};

    // Clase DJ que hereda de Empleado
class DJ : public Empleado{
    // Se declaran los atributos privados del DJ
    private:
    string generos[20];
    int numGeneros = 5;
    int generoActual = 0;

    // Se declaran los metodos  de la clase
    public: 

    // Constructor por default del DJ, y asigna los 5 generos musicales iniciales
    DJ() : Empleado ("", 0, 0.0, "", "DJ") { 
        generos[0] = "Reggaeton";
        generos[1] = "Techno";
        generos[2] = "House";
        generos[3] = "Rock";
        generos[4] = "Pop";
    };

    /** DJ
     * 
     * El constructor del DJ recibe su nombre, ID, salario, turno y los generos musicales que maneja
     * @param string n, int id, double s, string t
     * @return
     * 
     */
    DJ(string n, int id, double s, string t) : Empleado(n, id, s, t, "DJ") {
        generos[0] = "Reggaeton";
        generos[1] = "Techno";
        generos[2] = "House";
        generos[3] = "Rock";
        generos[4] = "Pop";

    }

    /** mostrarGeneros
     * 
     * Este metodo muestra los generos musicales que maneja el DJ
     * @return
     */
    void mostrarGeneros(){
        cout << "Generos musicales: " << endl;
        for (int i=0; i<numGeneros; i++){
            cout << i + 1 << ". " << generos[i] << endl;
        }
    }

    // Getter de genero actual
    string getGeneroActual(){
        return generos[generoActual]; 
    }

    /** cambiarGenero
     * 
     * El DJ puede cambiar el genero musical que esta sonando, el metodo cambia al genero siguiente en la lista
     * y si llega al final de la lista, regresa al primer genero
     * @return
     */
    void cambiarGenero(){
        generoActual++;
        if (generoActual >= numGeneros){
        generoActual = 0;
        }
        cout << "DJ " << nombre << " ha cambiado el genero musical a " << getGeneroActual() << "." << endl;

    }

    /** agregarGenero
     * 
     * Este metodo permite al DJ agregar un genero que el usuario ingrese, agrega el genero al arreglo y aumenta el
     * contador. Si el DJ tiene 20 generos, no se pueden agregar más
     * @return
     */

    void agregaGenero(){
        if (numGeneros < 20){
        string genero;
        cout << "Ingresa el genero que desea agregar: ";
        cout << endl;
        cin >> genero;
        generos[numGeneros] = genero;
        numGeneros++;
        }
    }

    /** mostrarInfo
     * 
     * Este metodo muestra la informacion del DJ
     * @return
     */
    void mostrarInfo(){
        cout << "Nombre: " << nombre << endl;
        cout << "ID: " << ID << endl;
        cout << "Salario: $" << salario << endl;
        cout << "Turno: " << turno << endl;
        cout << "Puesto: " << puesto << endl;
        cout << "Genero actual: " << getGeneroActual() << endl;
        }

};

// Clase Bartender que hereda de Empleado
class Bartender : public Empleado{
    // Atributos privados
    private:
    int tiempo_experiencia;
    
    // Metodos de la clase
    public:
    // Constructor por default
    Bartender() : Empleado ("", 0, 0.0, "", "Bartender") {};
    /** Bartender
     * 
     * El constructor recibe nombre, ID, salario, turno, puesto y tiempo de experiencia
     * @param string n, int id, double s, string t, int te
     * @return
     * 
     */

    Bartender(string n, int id, double s, string t, int te) : Empleado(n, id, s, t, "Bartender") {
        tiempo_experiencia = te;
    }

    /** mostrarInfo
     * 
     * Este metodo muestra la informacion del bartender, incluyendo su tiempo de experiencia
     * @return
     */
    void mostrarInfo(){
        cout << "Nombre: " << getNombre() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Salario: " << getSalario() << endl;
        cout << "Turno: " << getTurno() << endl;
        cout << "Puesto: " << getPuesto() << endl;
        cout << "Tiempo de experiencia: " << tiempo_experiencia << " años" << endl;
    }
};
#endif
