#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int> pila;
    int numero;
    bool fin=false;
    cout << "Ingrese sus numeros"<<endl;
    cout<<"Si desea dejar de ingresar presione -1 cuando le ingrese su numero"<<endl;
    while (!fin) {
        cout << "> ";
        cin >> numero;
        if (cin.fail()) {
            cerr << "Error: entrada invalida, ingrese solo numeros.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (numero == -1) {
            fin = true;
        }
        else {
            pila.push(numero);
        }
    }
    cout << "CNumero de elementos guardados en la pila:" << pila.size() << "\n";
    if (!pila.empty()) {
        cout << "Ultimo elemento ingresado: " << pila.top() << "\n";
    } else {
        cout << "Error: La pila esta vacia";
    }
    return 0;
}