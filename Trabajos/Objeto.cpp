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

int main() {
    Usuario usuario1;

    usuario1.setNombre("Carlos");
    usuario1.mostrarNombre();

    return 0;
}