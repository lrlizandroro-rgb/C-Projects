#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

struct Memoria {
    int* numeros;
    int suma_total = 0;
};

mutex candado;

void hilo_paralelo(Memoria* mem, int inicio, int fin) {
    int suma_local = 0;

    for (int i = inicio; i < fin; i++) {
        suma_local += mem->numeros[i];
    }

    candado.lock();
    mem->suma_total += suma_local;
    candado.unlock();
}

int main() {
    Memoria datos;
    int total = 1000;
    datos.numeros = new int[total];
    for(int i=0; i<total; i++) datos.numeros[i] = 1;

    thread t1(hilo_paralelo, &datos, 0, 500);
    thread t2(hilo_paralelo, &datos, 500, 1000);

    t1.join();
    t2.join();

    cout << "[Paralelo] Suma total: " << datos.suma_total << endl;
    delete[] datos.numeros;
    return 0;
}