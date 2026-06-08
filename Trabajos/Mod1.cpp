#include <iostream>

using namespace std;

int main() {
    int total_elementos = 1000;
    int* numeros = new int[total_elementos];
    int suma_total = 0;

    for (int i = 0; i < total_elementos; i++) {
        numeros[i] = 1;
    }

    for (int i = 0; i < total_elementos; i++) {
        suma_total += numeros[i];
    }

    cout << "[Secuencial] Suma total: " << suma_total << endl;

    delete[] numeros;
    return 0;
}