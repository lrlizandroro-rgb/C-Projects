#include <iostream>
using namespace std;
class Usuario {
private:
    string contrasena;
public:
    void setContrasena(string c) {
        contrasena = c;
    }
    void mostrarEstado() {
        cout << "Contraseña registrada correctamente." << endl;
    }
};
int main() {
    Usuario usuario1;
    usuario1.setContrasena("Segura123");
    usuario1.mostrarEstado();
    return 0;
}