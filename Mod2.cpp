#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

struct Memoria {
    int* numeros;
    int total_elementos;
    int indice_actual = 0;
    int suma_total = 0;
};

mutex candado;

void hilo_concurrente(Memoria* mem, int id) {
    while (true) {
        int valor_leido = 0;
        
        candado.lock();
        if (mem->indice_actual < mem->total_elementos) {
            valor_leido = mem->numeros[mem->indice_actual];
            mem->suma_total += valor_leido;
            mem->indice_actual++;
        } else {
            candado.unlock();
            break;
        }
        candado.unlock();
    }
}

int main() {
    Memoria datos;
    datos.total_elementos = 1000;
    datos.numeros = new int[datos.total_elementos];
    for(int i=0; i<1000; i++) datos.numeros[i] = 1;

    thread t1(hilo_concurrente, &datos, 1);
    thread t2(hilo_concurrente, &datos, 2);

    t1.join();
    t2.join();

    cout << "[Concurrente] Suma total: " << datos.suma_total << endl;
    delete[] datos.numeros;
    return 0;
}
