#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Ticket {
public:
    int codigo;
    string cliente;
    int prioridad;
};
int main() {
    vector<Ticket> tickets;
    int opcion;
    cout << "--- Sistema de Atencion Tecnica ---" << endl;
    do {
        cout << endl;
        cout << "1. Registrar ticket" << endl;
        cout << "2. Mostrar orden de atencion" << endl;
        cout << "3. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        if (cin.fail()) {
            cout << "Entrada invalida." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (opcion == 1) {
            Ticket t;
            cout << "Ingrese el codigo del ticket: ";
            cin >> t.codigo;
            cout << "Ingrese el nombre del cliente: ";
            cin >> t.cliente;
            cout << "Ingrese la prioridad (1 = alta, 2 = media, 3 = baja): ";
            cin >> t.prioridad;
            int pos = 0;
            while (pos < (int)tickets.size() && tickets[pos].prioridad <= t.prioridad) {
                pos++;
            }
            tickets.insert(tickets.begin() + pos, t);
            cout << "Ticket registrado." << endl;
        }
        else if (opcion == 2) {
            if (tickets.empty()) {
                cout << "No hay tickets registrados." << endl;
            } else {
                cout << "Orden de atencion:" << endl;
                for (int i = 0; i < (int)tickets.size(); i++) {
                    cout << i + 1 << ". Codigo: " << tickets[i].codigo
                         << " | Cliente: " << tickets[i].cliente
                         << " | Prioridad: " << tickets[i].prioridad << endl;
                }
            }
        }
        else if (opcion == 3) {
            cout << "Saliendo..." << endl;
        }
        else {
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 3);
    return 0;
}