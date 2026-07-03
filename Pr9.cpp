#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Estudiante {
public:
    int codigo;
    string nombre;
    int edad;
    string carrera;
};
int main() {
    vector<Estudiante> estudiantes;
    int opcion;
    cout << "--- Registro de Estudiantes ---" << endl;
    do {
        cout << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Mostrar todos los estudiantes" << endl;
        cout << "3. Buscar estudiante por codigo" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        if (cin.fail()) {
            cout << "Entrada invalida." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (opcion == 1) {
            Estudiante e;
            cout << "Ingrese el codigo: ";
            cin >> e.codigo;
            cout << "Ingrese el nombre: ";
            cin >> e.nombre;
            cout << "Ingrese la edad: ";
            cin >> e.edad;
            cout << "Ingrese la carrera: ";
            cin >> e.carrera;
            estudiantes.push_back(e);
            cout << "Estudiante registrado." << endl;
        }
        else if (opcion == 2) {
            if (estudiantes.empty()) {
                cout << "No hay estudiantes registrados." << endl;
            } else {
                for (int i = 0; i < (int)estudiantes.size(); i++) {
                    cout << "Codigo: " << estudiantes[i].codigo
                         << " | Nombre: " << estudiantes[i].nombre
                         << " | Edad: " << estudiantes[i].edad
                         << " | Carrera: " << estudiantes[i].carrera << endl;
                }
            }
        }
        else if (opcion == 3) {
            int codigoBuscado;
            cout << "Ingrese el codigo a buscar: ";
            cin >> codigoBuscado;
            bool encontrado = false;
            for (int i = 0; i < (int)estudiantes.size(); i++) {
                if (estudiantes[i].codigo == codigoBuscado) {
                    cout << "Estudiante encontrado:" << endl;
                    cout << "Nombre: " << estudiantes[i].nombre << endl;
                    cout << "Edad: " << estudiantes[i].edad << endl;
                    cout << "Carrera: " << estudiantes[i].carrera << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "No se encontro ningun estudiante con ese codigo." << endl;
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