#include <iostream>
using namespace std;

class Usuario {
private:
    string nombre;
    int nivelAcceso;

public:
    void setDatos(string n, int nivel) {
        nombre = n;
        nivelAcceso = nivel;
    }

    void mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Nivel de acceso: " << nivelAcceso << endl;
    }
};