#ifndef EMPLEADON_H
#define EMPLEADON_H

#include <iostream>
#include <vector>
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

    void mostrarInfo() {
        cout << "Nombre: " << nombre << endl;
        cout << "ID: " << ID << endl;
        cout << "Salario: $" << salario << endl;
        cout << "Turno: " << turno << endl;
        cout << "Puesto: " << puesto << endl;
    }
};

class Cadenero : public Empleado {
    public:
    Cadenero() : Empleado ("", 0, 0.0, "", "Cadenero") {};
    Cadenero(string n, int id, double s, string t) : Empleado(n, id, s, t, "Cadenero") {}

    void expulsarCliente(Cliente c){
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

    void mostrarInfo() {
        Empleado::mostrarInfo();
    }
};

class DJ : public Empleado {
    private:
    vector<string> generos;
    int generoActual = 0;


    public: 
    DJ() : Empleado ("", 0, 0.0, "", "DJ") { 
        generos = {"Reggaeton", "Techno", "House", "Rock", "Pop"};
    };

    DJ(string n, int id, double s, string t) : Empleado(n, id, s, t, "DJ") {
        generos = {"Reggaeton", "Techno", "House", "Rock", "Pop"};
    }

    void mostrarGeneros(){
        cout << "Generos musicales: " << endl;
        for (int i=0; i<generos.size(); i++){
            cout << i + 1 << ". " << generos[i] << endl;
        }
    }

        string getGeneroActual(){
        return generos[generoActual]; 
    }

    void cambiarGenero(){
        generoActual++;

        if (generoActual >= generos.size()){
        generoActual = 0;
        }
    }

    void agregaGenero(){
        string genero;
        cout << "Ingresa el genero que deseas agregar: ";
        cout << endl;
        cin >> genero;
        generos.push_back(genero);
    }


    void mostrarInfo() {
        Empleado::mostrarInfo();
        cout << "Genero actual: " << getGeneroActual() << endl;
    }
};

class Bartender : public Empleado {
   public:
    Bartender() : Empleado ("", 0, 0.0, "", "Bartender") {};
    Bartender(string n, int id, double s, string t) : Empleado(n, id, s, t, "Bartender") {}

    // Lógica para que el bartender agrege una bebida al vector de bebidas


    void mostrarInfo() {
        Empleado::mostrarInfo();
    }
};

#endif
