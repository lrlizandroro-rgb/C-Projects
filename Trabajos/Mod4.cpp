#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

struct Buffer {
    int dato;
    bool hay_dato = false;
    mutex candado;
};

void productor(Buffer* b) {
    for (int i = 1; i <= 3; i++) {
        bool entregado = false;
        while (!entregado) {
            b->candado.lock();
            if (!b->hay_dato) {
                b->dato = i * 10;
                b->hay_dato = true;
                cout << "[Productor] Genero: " << b->dato << endl;
                entregado = true;
            }
            b->candado.unlock();
        }
    }
}

void consumidor(Buffer* b) {
    for (int i = 1; i <= 3; i++) {
        bool recogido = false;
        while (!recogido) {
            b->candado.lock();
            if (b->hay_dato) {
                cout << "       -> [Consumidor] Proceso: " << b->dato << endl;
                b->hay_dato = false;
                recogido = true;
            }
            b->candado.unlock();
        }
    }
}

int main() {
    Buffer bandeja;
    thread t_prod(productor, &bandeja);
    thread t_cons(consumidor, &bandeja);

    t_prod.join();
    t_cons.join();
    return 0;
}