#include <iostream>
using namespace std;
class Usuario {
public:
    virtual void accederSistema() {
        cout << "Acceso básico al sistema." << endl;
    }
};
class Administrador : public Usuario {
public:
    void accederSistema() override {
        cout << "Acceso completo al sistema." << endl;
    }
};
int main() {
    Usuario* usuario;
    Administrador admin;
    usuario = &admin;
    usuario->accederSistema();
    return 0;
}