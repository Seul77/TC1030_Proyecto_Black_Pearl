/*
 * Black Pearl
 * Saúl Gómez Oñate
 * A01714080
 * 10/06/2026
 * Este programa simula un antro en el que el
 * usuario puede controlar a los empleados y clientes,
 * ver su informacion y tomar decisiones para simular
 * el funcionamiento del antro.
 */

#include <iostream>
using namespace std;

// Se incluyen todas las clases
#include "Bebida.h"
#include "Cliente.h"
#include "Empleado.h"
#include "BlackPearl.h"

int main(){
    // Se crean los objetos de tipo cliente, empleado y bebida con sus respectivos atributos en la memoria dinamica
    Cliente* c1 = new Cliente("Kari", 25, 1000.0, false, 1);
    Cliente* c2 = new Cliente("Dani", 17, 550.0, false, 0);
    Cliente* c3 = new Cliente("Mir", 30, 2500.0, false, 2);
    Cliente* c4 = new Cliente("Diego", 22, 750.0, false, 1);

    Cadenero* e1 = new Cadenero("Hector", 29094, 500.0, "Nocturno", 76.4);
    Cadenero* e2 = new Cadenero("Marco", 29095, 550.0, "Nocturno", 80.0);
    DJ* e3 = new DJ("Isa", 29101, 600.0, "Nocturno");
    DJ* e4 = new DJ("Rashell", 29102, 750.0, "Nocturno");
    Bartender* e5 = new Bartender("Gerardo", 30101, 700.0, "Nocturno", 6);
    Bartender* e6 = new Bartender("Mar", 30102, 800.0, "Nocturno", 7);

    Bebida* b1 = new Bebida("Mojito", 135.0, 5.0);
    Bebida* b2 = new Bebida("Paloma", 120.0, 7.0);
    Bebida* b3 = new Bebida("Cuba", 90.0, 6.0);
    Bebida* b4 = new Bebida("Black Pearl", 300.0, 50.0);
    Bebida* b5 = new Bebida("Cerveza", 100.0, 4.0);
    Bebida* b6 = new Bebida("Ron", 150.0, 40.0);
    Bebida* b7 = new Bebida("Mosco mule", 200.0, 6.0);
    Bebida* b8 = new Bebida("Don Julio", 1000.0, 45.0);

    // Se crean los arreglos de punteros a empleados, clientes y bebidas para ser pasados al constructor de BlackPearl
    Empleado* empleados[] = {e1, e2, e3, e4, e5, e6};
    Cliente* clientes[] = {c1, c2, c3, c4};      
    Bebida* bebidas[] = {b1, b2, b3, b4, b5, b6, b7, b8};

    // Objeto BlackPearl, con los arreglos de punteros a empleados, clientes y bebidas
    BlackPearl bar(empleados, clientes, bebidas);

    int opcion = 0; // Variable para controlar el menu de opciones
    cout << "Bienvenido al Black Pearl!, usted en este momento esta supervisando el antro." << endl;
    cout << "Su trabajo aqui es controlar todo lo que sucede tanto empleados como clientes, Buena suerte!" << endl;  
    // Ciclo while para que el programa siga corriendo hasta que el usuario decida salir
    while (opcion != 6){ 
    cout << "\nQue desea hacer?" << endl;
    cout << "1. Ver lista de clientes" << endl;
    cout << "2. Ver lista de empleados" << endl;
    cout << "3. Ver lista de bebidas" << endl;
    cout << "4. Controlar un empleado" << endl;
    cout << "5. Controlar un cliente" << endl;
    cout << "6. Salir" << endl;

    cin >> opcion; 
    // Switch para controlar las opciones del menu
    switch (opcion){
        // En el caso 1, se muestra la lista de clientes
        case 1:
            bar.mostrarClientes();
            break;
        // En el caso 2, se muestra la lista de empleados
        case 2:
            bar.mostrarEmpleados();
            break;
        // En el caso 3, se muestra la lista de bebidas
        case 3:                                                                                                     
            bar.mostrarBebidas();
            break;
        // En el caso 4, se puede controlar a un empleado
        case 4:{
            cout << "Que empleado deseas controlar?" << endl;
            int opcionEmpleado = 0;
            for (int i = 0; i < 6; i++){
                cout << i + 1 << ". " << empleados[i]->getNombre() << ", " << empleados[i]->getPuesto() << endl;
            }
            cin >> opcionEmpleado;

            if (opcionEmpleado == 1 || opcionEmpleado == 2){ // Si el usuario elige cadenero
                Cadenero* cadenero = (opcionEmpleado == 1 ? e1 : e2); // Se asigna el puntero al cadenero seleccionado
                cout << "Haz elegido a " << cadenero->getNombre() << endl; // Se muestra el nombre del cadenero seleccionado
                cout << "Que quieres hacer?" << endl;
                int indice = 1;
                cout << indice << ". Revisar cliente" << endl;
                cout << ++indice << ". Ver informacion" << endl;
                int opcionRevisar = 0;
                cin >> opcionRevisar;
                if (opcionRevisar == 1){ // Se muestra la lista de clientes para que el usuario eliga cual revisar
                    cout << "Que cliente deseas revisar?" << endl;
                    for (int i=0; i<4; i++){
                        cout << i + 1 << ". " << clientes[i]->getNombre() << ", Edad: " << clientes[i]->getEdad() << ", " << clientes[i]->getEbrio() << ", dinero: $" << clientes[i]->getDinero() << endl;
                    }
                    int opcionCliente;
                    cin >> opcionCliente;
                    if (opcionCliente >= 1 && opcionCliente <= 4){
                    bool expulsado = cadenero->expulsarCliente(*clientes[opcionCliente - 1]); // Se llama al metodo expulsarCliente del cadenero seleccionado
                    if (expulsado){ // Si se expulsa el cliente, se elimina de la lista de clientes
                        bar.eliminarCliente(opcionCliente - 1);
                        bar.mostrarClientes();
                        }
                    }
                }
                else if (opcionRevisar == 2){ // Si el usuario elige ver informacion del cadenero, se llama al metodo mostrarInfo del cadenero que se selecciono
                    cadenero->mostrarInfo();
                }
            }

            else if (opcionEmpleado == 3 || opcionEmpleado == 4){ // Si el usuario elige DJ
                DJ* dj = (opcionEmpleado == 3 ? e3 : e4); // Se asigna el puntero al DJ seleccionado
                cout << "Haz elegido a " << dj->getNombre() << endl; // Se muestra el nombre del DJ seleccionado
                cout << "Que deseas hacer?" << endl;
                int indice = 1;
                cout << indice << ". Mostrar lista de generos que tiene" << endl;
                cout << ++indice << ". Pedirle al Dj que agregue un genero" << endl;
                cout << ++indice << ". Ver que genero esta sonando" << endl;
                cout << ++indice << ". Ver informacion del DJ" << endl;
                cout << ++indice << ". Cambiar genero musical" << endl;
                int opcionDJ;
                cin >> opcionDJ;
                if (opcionDJ == 1){ // Se llama el metodo mostrarGeneros y muestra la lista del DJ seleccionado
                    dj->mostrarGeneros();
                }
                else if (opcionDJ == 2 ){ // Se llaman los metodos agregaGenero y mostrarGeneros para el DJ seleccionado
                    dj->agregaGenero();
                    dj->mostrarGeneros();
                }
                else if (opcionDJ == 3){ // Se llama al getter de generoActual para mostrar el genero que esta sonando
                    cout << "El genero actual es: " << dj->getGeneroActual() << endl;
                }
                else if (opcionDJ == 4){ // Se llama al metodo mostrarInfo para mostrar la informacion del DJ que se selecciono
                    dj->mostrarInfo();
                }
                else if (opcionDJ == 5){ // Se llaman los metodos cambiarGenero y mostrarGeneros para el DJ seleccionado
                    dj->cambiarGenero();
                    dj->mostrarGeneros();
                }

            }

            else if (opcionEmpleado == 5 || opcionEmpleado == 6){ // Si el usuario elige bartender
                Bartender* bartender = (opcionEmpleado == 5 ? e5 : e6); // Se asigna el puntero al bartender seleccionado
                cout << "Haz elegido a " << bartender->getNombre() << endl; // Se muestra el nombre del bartender seleccionado            
                cout << "Que quieres hacer?" << endl;
                int indice = 1;
                cout << indice << ". Ver informacion" << endl;
                cin >> indice; 
                if (indice == 1){ // Se llama al metodo mostrarInfo para mostrar la informacion del bartender
                    bartender->mostrarInfo();
                }
            }
        }
        break;
        // En el caso 5, el usuario puede controlar a un cliente
        case 5:{
            cout << "Que cliente deseas controlar?" << endl;
            for (int i=0; i<4; i++){ // Se muestra la lista de clientes para que el usuario eliga
                cout << i + 1 << ". " << clientes[i]->getNombre() << ", Edad: " << clientes[i]->getEdad() << ", Dinero: $" << clientes[i]->getDinero() << ", Bebidas tomadas: " << clientes[i]->getBebidasTomadas() << endl;
            }
            int opcionCliente;
            cin >> opcionCliente;
            if (opcionCliente >= 1){ // Si el usuario elige un cliente, se muestra su nombre y se le dan opciones para controlarlo
                cout << "Haz elegido a " << clientes[opcionCliente - 1]->getNombre() << endl;
                cout << "Que quieres hacer?" << endl;
                int indice = 1;
                cout << indice << ". Pedir una bebida" << endl;
                cout << ++indice << ". Ver informacion" << endl;
                int opcionPedir = 0;
                cin >> opcionPedir;
                if (opcionPedir == 1){ // Si el usuario elige pedir una bebida
                    int opcionBebida;
                    cout << "Que bebida deseas pedir?" << endl;
                    for (int i=0; i<8; i++){ // Se muestra la lista de bebidas
                        cout << i + 1 << ". " << bebidas[i]->getNombre() << " $" << bebidas[i]->getPrecio() << endl;
                    }
                    cin >> opcionBebida;
                    if (opcionBebida >= 1 && opcionBebida <= 8){ // Se llama al metodo pagarBebida del cliente seleccionado, con la bebida seleccionada como parametro
                        clientes[opcionCliente - 1]->pagarBebida(*bebidas[opcionBebida - 1]);
                    }
                }
                else if (opcionPedir == 2){ // Si el usuario quiere ver la informacion del cliente, se llama al metodo mostrarInfo del cliente seleccionado
                    clientes[opcionCliente - 1]->mostrarInfo();
                }
            }
        }
    }
}
    return 0;

}