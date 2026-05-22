#include <iostream>
using namespace std;

#include <vector>
#include "BebidaN.h"
#include "ClienteN.h"
#include "EmpleadoN.h"
#include "BlackPearlN.h"


int main() {
    Cliente c1("Kari", 25, 100.0, false);
    Cliente c2("Dani", 17, 5.0, false);
    Cliente c3("Mir", 30, 200.0, true);
    Cliente c4("Diego", 22, 150.0, false);
    Cadenero e1("Hector", 29094, 500.0, "Nocturno");
    Cadenero e2("Marco", 29095, 550.0, "Nocturno");
    DJ e3("Isa", 29101, 600.0, "Nocturno");
    DJ e4("Rashell", 29102, 750.0, "Nocturno");
    Bartender e5("Gerardo", 30101, 700.0, "Nocturno");
    Bartender e6("Mar", 30102, 800.0, "Nocturno");
    Bebida b1("Mojito", 135.0, 5.0, 10);
    Bebida b2("Paloma", 120.0, 7.0, 5);
    Bebida b3("Cuba", 90.0, 6.0, 8);
    Bebida b4("Black Pearl", 300.0, 50.0, 20);
    Bebida b5("Cerveza", 100.0, 4.0, 50);
    Bebida b6("Ron", 150.0, 40.0, 15);
    Bebida b7("Mosco mule", 200.0, 6.0, 10);
    Bebida b8("Don Julio", 1000.0, 45.0, 5);

    vector<Cadenero>cadeneros = {e1, e2};
    vector<DJ>djs = {e3, e4};
    vector<Bartender>bartenders = {e5, e6};
    vector<Cliente>clientes = {c1, c2, c3, c4};
    vector<Bebida>bebidas = {b1, b2, b3, b4, b5, b6, b7, b8};

    BlackPearl bar(cadeneros, djs, bartenders, clientes, bebidas);

    int opcion = 0;
    cout << "Bienvenido al Black Pearl!, usted en este momento esta supervisando el antro." << endl;
    cout << "Su trabajo aqui es controlar todo lo que sucede, Buena suerte!" << endl;  
    while (opcion != 6){ 
    cout << "\nQue desea hacer?" << endl;
    cout << "1. Ver lista de clientes" << endl;
    cout << "2. Ver lista de empleados" << endl;
    cout << "3. Ver lista de bebidas" << endl;
    cout << "4. Controlar un empleado" << endl;
    cout << "5. Controlar un cliente" << endl;
    cout << "6. Salir" << endl;
    cin >> opcion; 
    switch (opcion){
        case 1:
            bar.mostrarClientes();
            break;
        case 2:
            bar.mostrarEmpleados();
            break;
        case 3:
            bar.mostrarBebidas();
            break;
        case 4: {
            cout << "Que empleado deseas controlar?" << endl;
            int opcionEmpleado = 0;
            cout << "1. " << e1.getNombre() << " - " << e1.getPuesto() << endl;
            cout << "2. " << e2.getNombre() << " - " << e2.getPuesto() << endl;
            cout << "3. " << e3.getNombre() << " - " << e3.getPuesto() << endl;
            cout << "4. " << e4.getNombre() << " - " << e4.getPuesto() << endl;
            cout << "5. " << e5.getNombre() << " - " << e5.getPuesto() << endl;
            cout << "6. " << e6.getNombre() << " - " << e6.getPuesto() << endl;
            cin >> opcionEmpleado;
            if (opcionEmpleado == 1 || opcionEmpleado == 2){
                cout << "Haz elegido a " << (opcionEmpleado == 1 ? e1.getNombre() : e2.getNombre()) << endl;
                cout << "Que quieres hacer?" << endl;
                int indice = 1;
                cout << indice << ". Revisar cliente" << endl;
                cout << ++indice << ". Ver informacion" << endl;
                int opcionRevisar = 0;
                cin >> opcionRevisar;
                if (opcionRevisar == 1){
                    cout << "Que cliente deseas revisar?" << endl;
                    for (int i=0; i<clientes.size(); i++){
                        cout << i + 1 << ". " << clientes[i].getNombre() << ", " << clientes[i].getEdad() << ", " << clientes[i].getEbrio() << endl;
                    }
                    int opcionCliente;
                    cin >> opcionCliente;
                    if (opcionCliente >= 1 && opcionCliente <= clientes.size()){
                    (opcionEmpleado == 1 ? e1 : e2).expulsarCliente(clientes[opcionCliente - 1]);                    
                    }
                    }
                else if (opcionRevisar == 2){
                    (opcionEmpleado == 1 ? e1 : e2).mostrarInfo();
                }
            }
            else if (opcionEmpleado == 3 || opcionEmpleado == 4){
                cout << "Haz elegido a " << (opcionEmpleado == 3 ? e3.getNombre() : e4.getNombre()) << endl;
                cout << "Que deseas hacer?" << endl;
                int indice = 1;
                cout << indice << ". Mostrar lista de generos que tiene" << endl;
                cout << ++indice << ". Pedirle al Dj que agregue un genero" << endl;
                cout << ++indice << ". Ver que genero esta sonando" << endl;
                cout << ++indice << ". Ver informacion del DJ" << endl;
                cout << ++indice << ". Cambiar genero musical" << endl;
                int opcionDJ;
                cin >> opcionDJ;
                if (opcionDJ == 1){
                    (opcionEmpleado == 3 ? e3 : e4).mostrarGeneros();
                }
                else if (opcionDJ == 2 ){
                    (opcionEmpleado == 3 ? e3 : e4).agregaGenero();
                    (opcionEmpleado == 3 ? e3 : e4).mostrarGeneros();
                }
                else if (opcionDJ == 3){
                    cout << "El genero actual es: " << (opcionEmpleado == 3 ? e3 : e4).getGeneroActual() << endl;
                }
                else if (opcionDJ == 4){
                    (opcionEmpleado == 3 ? e3 : e4).mostrarInfo();
                }
                else if (opcionDJ == 5){
                    (opcionEmpleado == 3 ? e3 : e4).cambiarGenero();
                    (opcionEmpleado == 3 ? e3 : e4).mostrarGeneros();
                }

            }

            else if (opcionEmpleado == 5 || opcionEmpleado == 6){
                cout << "Haz elegido a " << (opcionEmpleado == 5 ? e5.getNombre() : e6.getNombre()) << endl;
                // Aquí iría la logica para controlar el bartender

            }
        }
        break;

        case 5:{
            cout << "Que cliente deseas controlar?" << endl;
            for (int i=0; i<clientes.size(); i++){
                cout << i + 1 << ". " << clientes[i].getNombre() << ", " << clientes[i].getEdad() << ", " << clientes[i].getEbrio() << endl;
            }
            int opcionCliente;
            cin >> opcionCliente;
            if (opcionCliente >= 1){
                cout << "Haz elegido a " << clientes[opcionCliente - 1].getNombre() << endl;
                cout << "Que quieres hacer?" << endl;
                int indice = 1;
                cout << indice << ". Pagar una bebida" << endl;
                cout << ++indice << ". Ver informacion" << endl;
                int opcionPedir = 0;
                cin >> opcionPedir;
                if (opcionPedir == 1){
                    int opcionBebida;
                    cout << "Que bebida deseas pedir?" << endl;
                    for (int i=0; i<bebidas.size(); i++){
                        cout << i + 1 << ". " << bebidas[i].getNombre() << " $" << bebidas[i].getPrecio() << endl;
                    }
                    cin >> opcionBebida;
                    if (opcionBebida >= 1 && opcionBebida <= bebidas.size()){
                        clientes[opcionCliente - 1].pagarBebida(bebidas[opcionBebida - 1]);
                    }
                }
                else if (opcionPedir == 2){
                    clientes[opcionCliente - 1].mostrarInfo();
                }
            }
        }
    }
};

    return 0;
}
