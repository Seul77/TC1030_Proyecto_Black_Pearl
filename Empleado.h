#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
using namespace std;

class Empleado{
    protected: 
    string nombre;
    int ID;
    double salario;
    string turno;
    string puesto;

    public:
    Empleado(){
        nombre = "";
        ID = 0;
        salario = 0.0;
        turno = "";
        puesto = "";
    }

    Empleado(string n, int id, double s, string t, string p){
        nombre = n;
        ID = id;
        salario = s;
        turno = t;
        puesto = p;
    }

    string getNombre(){
        return nombre;
    }

    int getID(){
        return ID;
    }

    virtual double getSalario(){
        return salario;
    }

    string getTurno(){
        return turno;
    }

    string getPuesto(){
        return puesto;
    }

    virtual void mostrarInfo(){
        cout << "Nombre: " << nombre << endl;
        cout << "ID: " << ID << endl;
        cout << "Salario: $" << salario << endl;
        cout << "Turno: " << turno << endl;
        cout << "Puesto: " << puesto << endl;
    }
};

class Cadenero : public Empleado{
    private:
    double peso;
    public:
    Cadenero() : Empleado ("", 0, 0.0, "", "Cadenero") {};
    Cadenero(string n, int id, double s, string t, double p) : Empleado(n, id, s, t, "Cadenero") {
        peso = p;
    }

    void expulsarCliente(Cliente &c){
        if (c.getEbrio()){
            cout << "El cadenero " << nombre << " ha expulsado al cliente " << c.getNombre() << " por estar ebrio." << endl;
        }

        else if (c.getEdad() < 18){
            cout << "El cadenero " << nombre << " ha expulsado al cliente " << c.getNombre() << " por ser menor de edad." << endl;
        }
        else {
            cout << "El cadenero " << nombre << " ha revisado al cliente " << c.getNombre() << " y no encontro problemas." << endl;
        }
    }

    void mostrarInfo(){
        cout << "Nombre: " << getNombre() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Salario: $" << getSalario() << endl;
        cout << "Turno: " << getTurno() << endl;
        cout << "Puesto: " << getPuesto() << endl;
        cout << "Peso: " << peso << " kg" << endl;
    }
};

class DJ : public Empleado{
    private:
    string generos[20];
    int numGeneros = 5;
    int generoActual = 0;


    public: 
    DJ() : Empleado ("", 0, 0.0, "", "DJ") { 
        generos[0] = "Reggaeton";
        generos[1] = "Techno";
        generos[2] = "House";
        generos[3] = "Rock";
        generos[4] = "Pop";
    };

    DJ(string n, int id, double s, string t) : Empleado(n, id, s, t, "DJ") {
        generos[0] = "Reggaeton";
        generos[1] = "Techno";
        generos[2] = "House";
        generos[3] = "Rock";
        generos[4] = "Pop";

    }

    void mostrarGeneros(){
        cout << "Generos musicales: " << endl;
        for (int i=0; i<numGeneros; i++){
            cout << i + 1 << ". " << generos[i] << endl;
        }
    }

    string getGeneroActual(){
        return generos[generoActual]; 
    }

    void cambiarGenero(){
        generoActual++;
        if (generoActual >= numGeneros){
        generoActual = 0;
        }
        cout << "DJ " << nombre << " ha cambiado el genero musical a " << getGeneroActual() << "." << endl;

    }

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


    void mostrarInfo(){
        cout << "Nombre: " << nombre << endl;
        cout << "ID: " << ID << endl;
        cout << "Salario: $" << salario << endl;
        cout << "Turno: " << turno << endl;
        cout << "Puesto: " << puesto << endl;
        cout << "Genero actual: " << getGeneroActual() << endl;
        }

};

class Bartender : public Empleado{
    private:
    int tiempo_experiencia;
    
    public:
    Bartender() : Empleado ("", 0, 0.0, "", "Bartender") {};
    Bartender(string n, int id, double s, string t, int te) : Empleado(n, id, s, t, "Bartender") {
        tiempo_experiencia = te;
    }


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
