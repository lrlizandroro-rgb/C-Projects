#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Cliente {
public:
    string nombre; // haha
};
int main() {
    vector<Cliente> clientes;
    string nombre;
    int opcion;
    cout << "--- Bank Simulator ---" << endl;
    do {
        cout << endl;
        cout << "1. Agregar cliente" << endl;
        cout << "2. Atender cliente" << endl;
        cout << "3. Mostrar siguiente cliente" << endl;
        cout << "4. Mostrar cantidad de clientes" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cout << "Entrada invalida." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (opcion == 1) {
            Cliente c;
            cout << "Ingrese el nombre del cliente: ";
            cin >> c.nombre;
            clientes.push_back(c);
            cout << "Cliente agregado a la lista." << endl;
        }
        else if (opcion == 2) {
            if (!clientes.empty()) {
                cout << "Atendiendo a: " << clientes.front().nombre << endl;
                clientes.erase(clientes.begin());
            } else {
                cout << "No hay clientes en espera." << endl;
            }
        }
        else if (opcion == 3) {
            if (!clientes.empty()) {
                cout << "Siguiente cliente: " << clientes.front().nombre << endl;
            } else {
                cout << "No hay clientes en espera." << endl;
            }
        }
        else if (opcion == 4) {
            cout << "Cantidad de clientes en espera: " << clientes.size() << endl;
        }
        else if (opcion == 5) {
            cout << "Cerrando el banco..." << endl;
        }
        else {
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 5);

    return 0;
}