#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
    queue<string> espera;
    string nombre;
    cout << "Registro de Personas en Espera" << endl;
    for (int i = 1; i <= 10; i++) {
        cout << "Ingrese el nombre de la persona " << i << ": ";
        cin >> nombre;
        espera.push(nombre);
    }
    cout << endl << "Atendiendo personas (por orden FIFO)" << endl;
    while (!espera.empty()) {
        cout << "Atendiendo a: " << espera.front() << endl;
        espera.pop();
    }
    cout << endl << "Todas las personas han sido atendidas." << endl;
    return 0;
}