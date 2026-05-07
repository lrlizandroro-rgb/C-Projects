#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

struct Trabajo {
    int* tareas;
    int cantidad;
    int indice_actual = 0;
};
mutex mtx;
void trabajador(Trabajo* t, int id) {
    while (true) {
        int tarea_asignada = -1;
        
        mtx.lock();
        if (t->indice_actual < t->cantidad) {
            tarea_asignada = t->tareas[t->indice_actual];
            t->indice_actual++;
        }
        mtx.unlock();

        if (tarea_asignada == -1) break;
        
        cout << "[Trabajador " << id << "] resolvio la tarea " << tarea_asignada << endl;
    }
}

int main() {
    Trabajo datos;
    datos.cantidad = 5;
    datos.tareas = new int[datos.cantidad]{100, 200, 300, 400, 500};

    cout << "[Maestro] Trabajo preparado. Iniciando cuadrilla..." << endl;

    thread w1(trabajador, &datos, 1);
    thread w2(trabajador, &datos, 2);

    w1.join();
    w2.join();

    cout << "[Maestro] Todos los trabajadores han finalizado." << endl;
    
    delete[] datos.tareas;
    return 0;
}
