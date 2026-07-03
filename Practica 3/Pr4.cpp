#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    stack<string> historial;
    string pagActual = "";
    int opcion;
    cout<<"-------BRAVE-------" << endl;
    do {
        cout << endl;
        cout << "1. Visitar pagina" << endl;
        cout << "2. Retroceder" << endl;
        cout << "3. Mostrar pagina actual" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        if (cin.fail()) {
            cout << "Entrada invalida." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else if (opcion == 1) {
            string pagina;
            cout << "Ingrese la URL de la pagina: ";
            cin >> pagina;
            if (!pagActual.empty()) {
                historial.push(pagActual);
            }
            pagActual = pagina;
            cout << "Ahora esta en: " << pagActual << endl;
        }
        else if (opcion == 2) {
            if (!historial.empty()) {
                pagActual = historial.top();
                historial.pop();
                cout << "Retrocedio a: " << pagActual << endl;
            } else {
                cout << "No hay paginas anteriores en el historial." << endl;
            }
        }
        else if (opcion == 3) {
            if (!pagActual.empty()) {
                cout << "Pagina actual: " << pagActual << endl;
            } else {
                cout << "Aun no ha visitado ninguna pagina." << endl;
            }
        }
        else if (opcion == 4) {
            cout << "Saliendo del navegador..." << endl;
        }
        else {
            cout << "Opcion invalida, intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}