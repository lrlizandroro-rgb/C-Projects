#include <iostream>
using namespace std;
class Usuario {
protected:
    string nombre;
public:
    void setNombre(string n) {
        nombre = n;
    }
    void mostrarNombre() {
        cout << "Usuario: " << nombre << endl;
    }
};
class Administrador : public Usuario {
public:
    void mostrarPermiso() {
        cout << "Permiso de administrador activado." << endl;
    }
};
int main() {
    Administrador admin;
    admin.setNombre("Carlos");
    admin.mostrarNombre();
    admin.mostrarPermiso();
    return 0;
}