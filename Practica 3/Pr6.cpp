#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
    queue<string> clientes;
    string nombre;
    int opcion;
    cout << "--- Registro de Clientes con Colas ---" << endl;
    do {
        cout << endl;
        cout << "1. Registrar cliente" << endl;
        cout << "2. Atender cliente" << endl;
        cout << "3. Mostrar clientes pendientes" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cout << "Entrada invalida." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (opcion == 1) {
            cout << "Ingrese el nombre del cliente: ";
            cin >> nombre;
            clientes.push(nombre);
            cout << "Cliente registrado." << endl;
        }
        else if (opcion == 2) {
            if (!clientes.empty()) {
                cout << "Cliente atendido: " << clientes.front() << endl;
                clientes.pop();
            } else {
                cout << "No hay clientes para atender." << endl;
            }
        }
        else if (opcion == 3) {
            if (!clientes.empty()) {
                queue<string> copia = clientes;
                cout << "Clientes pendientes:" << endl;
                while (!copia.empty()) {
                    cout << "- " << copia.front() << endl;
                    copia.pop();
                }
            } else {
                cout << "No hay clientes pendientes." << endl;
            }
        }
        else if (opcion == 4) {
            cout << "Saliendo..." << endl;
        }
        else {
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);
    return 0;
}