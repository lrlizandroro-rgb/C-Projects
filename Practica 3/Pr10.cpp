#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Contacto {
public:
    string nombre;
    string telefono;
    string correo;
};
int main() {
    vector<Contacto> contactos;
    int opcion;
    cout << "--- APP CONYTACTOS ---" << endl;
    do {
        cout << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Buscar contacto por nombre" << endl;
        cout << "3. Eliminar contacto" << endl;
        cout << "4. Mostrar todos los contactos" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        if (cin.fail()) {
            cout << "Entrada invalida." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (opcion == 1) {
            Contacto c;
            cout << "Ingrese el nombre: ";
            cin >> c.nombre;
            cout << "Ingrese el telefono: ";
            cin >> c.telefono;
            cout << "Ingrese el correo electronico: ";
            cin >> c.correo;
            contactos.push_back(c);
            cout << "Contacto agregado." << endl;
        }
        else if (opcion == 2) {
            string nombreBuscado;
            cout << "Ingrese el nombre a buscar: ";
            cin >> nombreBuscado;

            bool encontrado = false;
            for (int i = 0; i < (int)contactos.size(); i++) {
                if (contactos[i].nombre == nombreBuscado) {
                    cout << "Contacto encontrado:" << endl;
                    cout << "Telefono: " << contactos[i].telefono << endl;
                    cout << "Correo: " << contactos[i].correo << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "No se encontro ningun contacto con ese nombre." << endl;
            }
        }
        else if (opcion == 3) {
            string nombreEliminar;
            cout << "Ingrese el nombre del contacto a eliminar: ";
            cin >> nombreEliminar;

            bool eliminado = false;
            for (int i = 0; i < (int)contactos.size(); i++) {
                if (contactos[i].nombre == nombreEliminar) {
                    contactos.erase(contactos.begin() + i);
                    eliminado = true;
                    break;
                }
            }
            if (eliminado) {
                cout << "Contacto eliminado." << endl;
            } else {
                cout << "No se encontro ningun contacto con ese nombre." << endl;
            }
        }
        else if (opcion == 4) {
            if (contactos.empty()) {
                cout << "No hay contactos registrados." << endl;
            } else {
                for (int i = 0; i < (int)contactos.size(); i++) {
                    cout << "Nombre: " << contactos[i].nombre
                         << " | Telefono: " << contactos[i].telefono
                         << " | Correo: " << contactos[i].correo << endl;
                }
            }
        }
        else if (opcion == 5) {
            cout << "Saliendo..." << endl;
        }
        else {
            cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);
    return 0;
}