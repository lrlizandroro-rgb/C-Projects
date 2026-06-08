#include <iostream>
using namespace std;

class Usuario {
private:
    string nombre;

public:
    void setNombre(string n) {
        nombre = n;
    }
    void mostrarNombre() {
        cout << "Usuario: " << nombre << endl;
    }
};