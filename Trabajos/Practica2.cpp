#include <iostream>
#include <string>
using namespace std;

///////////////////////////// CLASES ////////////////////////////////////////

class Persona {
protected:
    int edad;
    string Nombre;
};

// Clase Padre
class Empleado : public Persona {
protected:
    string cargo;
    int sueldo;
    int Fecha[3]; // 0: Dia, 1: Mes, 2: Año
    int nivelCargo; // Valor numérico para facilitar el ordenamiento (3=Gerente, 2=Supervisor, 1=Operario)

public:
    Empleado() { sueldo = 0; nivelCargo = 0; }

    void setDatosBasicos(string name, int age, string cargoAsignado, int f[3]) {
        Nombre = name;
        edad = age;
        cargo = cargoAsignado;
        Fecha[0] = f[0]; Fecha[1] = f[1]; Fecha[2] = f[2];

        if (cargo == "gerente") nivelCargo = 3;
        else if (cargo == "supervisor") nivelCargo = 2;
        else if (cargo == "operario") nivelCargo = 1;
        else nivelCargo = 0;
    }

    // Método virtual puro (Polimorfismo)
    virtual void calcularSueldo() = 0; 

    void mostrarEmpleado() {
        cout << "Nombre: " << Nombre << " | Cargo: " << cargo 
             << " | Sueldo: S/" << sueldo 
             << " | Ingreso: " << Fecha[0] << "/" << Fecha[1] << "/" << Fecha[2] << endl;
    }

    int getSueldo() { return sueldo; }
    string getNombre() { return Nombre; }
    int getNivelCargo() { return nivelCargo; }
    
    // Convierte la fecha a un número YYYYMMDD para comparar fácilmente
    int getValorFecha() { return (Fecha[2] * 10000) + (Fecha[1] * 100) + Fecha[0]; } 
};

// Clase Hija 1
class EmpleadoPlanta : public Empleado {
public:
    void calcularSueldo() {
        int tarifa = 0;
        if (cargo == "operario") tarifa = 50;
        else if (cargo == "supervisor") tarifa = 80;
        else if (cargo == "gerente") tarifa = 100;
        
        sueldo = tarifa * 40; // Fijo 40 horas semanales
    }
};

// Clase Hija 2
class EmpleadoPorHora : public Empleado {
private:
    int horasTrabajadas;
public:
    void setHoras(int horas) { horasTrabajadas = horas; }
    
    void calcularSueldo() {
        int tarifa = 0;
        if (cargo == "operario") tarifa = 50;
        else if (cargo == "supervisor") tarifa = 80;
        else if (cargo == "gerente") tarifa = 100;
        
        sueldo = tarifa * horasTrabajadas; // Depende de las horas ingresadas
    }
};

///////////////////////////////////// FUNCIONES AUXILIARES /////////////////////////////////////

void Validador_de_fecha(int ingreso[]) {
    bool fechaValida = false;
    
    while (!fechaValida) {
        cout << "Dia: "; cin >> ingreso[0];
        cout << "Mes: "; cin >> ingreso[1];
        cout << "Anio: "; cin >> ingreso[2];
        
        // 1. Validar mes
        if (ingreso[1] < 1 || ingreso[1] > 12) {
            cout << "\n[ERROR] Mes invalido. Un anio solo tiene 12 meses. Intente de nuevo.\n";
            continue;
        }
        
        // 2. Determinar días máximos del mes
        int diasMaximos = 31;
        if (ingreso[1] == 4 || ingreso[1] == 6 || ingreso[1] == 9 || ingreso[1] == 11) {
            diasMaximos = 30;
        } else if (ingreso[1] == 2) {
            diasMaximos = 28;
        }
        
        // 3. Validar día
        if (ingreso[0] < 1 || ingreso[0] > diasMaximos) {
            cout << "\n[ERROR] El mes " << ingreso[1] << " solo tiene " << diasMaximos << " dias. Intente de nuevo.\n";
            continue;
        }
        
        fechaValida = true;
    }
}

string elegirCargo() {
    int alternativa;
    cout << "Cargo (1: Operario, 2: Supervisor, 3: Gerente, 4: Sin cargo): ";
    cin >> alternativa;
    cin.ignore();
    switch (alternativa) {
        case 1: return "operario";
        case 2: return "supervisor";
        case 3: return "gerente";
        case 4: return "sin cargo";
        default: return "desconocido";
    }
}

///////////////////////////////////// FUNCION MAIN /////////////////////////////////////////////

int main() {
    Empleado* nomina[10]; 
    string NAME, CARGO;
    int AGE;
    int ingreso[3];

    // 1. Ingreso de Empleados de Planta (5)
    cout << "--- INGRESANDO 5 EMPLEADOS DE PLANTA ---" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\nEmpleado de planta " << i + 1 << ":" << endl;
        EmpleadoPlanta* emp = new EmpleadoPlanta();
        
        cout << "Nombre: "; getline(cin, NAME);
        
        cout << "Edad: "; cin >> AGE;
        while (AGE < 0 || AGE > 100) {
            cout << "Edad invalida. Digite una edad dentro de los estandares logicos.\n";
            cout << "Edad: "; cin >> AGE;
        }
        
        CARGO = elegirCargo();
        
        bool datosLegales = false;
        while (!datosLegales) {
            cout << "Fecha de ingreso:" << endl;
            Validador_de_fecha(ingreso);
            
            // Validacion legal (Referencia año actual 2026)
            int edadAlIngresar = AGE - (2026 - ingreso[2]);
            if (edadAlIngresar < 18 || ingreso[2] > 2026) {
                cout << "\n[ERROR LEGAL] Inconsistencia en los datos." << endl;
                if (ingreso[2] > 2026) {
                    cout << "El anio de ingreso no puede ser en el futuro." << endl;
                } else {
                    cout << "Con " << AGE << " anios, si ingreso en " << ingreso[2] 
                         << ", empezo a trabajar a los " << edadAlIngresar << " anios." << endl;
                    cout << "La edad minima legal para trabajar es de 18 anios.\n";
                }
                cout << "Por favor, digite una fecha de ingreso valida.\n\n";
            } else {
                datosLegales = true;
            }
        }
        cin.ignore();

        emp->setDatosBasicos(NAME, AGE, CARGO, ingreso);
        emp->calcularSueldo();
        nomina[i] = emp; 
    }

    // 2. Ingreso de Empleados Por Hora (5)
    cout << "\n--- INGRESANDO 5 EMPLEADOS POR HORA ---" << endl;
    for (int i = 5; i < 10; i++) {
        cout << "\nEmpleado por hora " << (i - 4) << ":" << endl;
        EmpleadoPorHora* emp = new EmpleadoPorHora();
        
        cout << "Nombre: "; getline(cin, NAME);
        
        cout << "Edad: "; cin >> AGE; 
        while (AGE < 0 || AGE > 100) {
            cout << "Edad invalida. Digite una edad dentro de los estandares logicos.\n";
            cout << "Edad: "; cin >> AGE;
        }
        
        CARGO = elegirCargo();
        
        int horas;
        cout << "Horas trabajadas en la semana: "; cin >> horas;
        
        bool datosLegales = false;
        while (!datosLegales) {
            cout << "Fecha de ingreso:" << endl;
            Validador_de_fecha(ingreso);
            
            int edadAlIngresar = AGE - (2026 - ingreso[2]);
            if (edadAlIngresar < 18 || ingreso[2] > 2026) {
                cout << "\n[ERROR LEGAL] Inconsistencia en los datos." << endl;
                if (ingreso[2] > 2026) {
                    cout << "El anio de ingreso no puede ser en el futuro." << endl;
                } else {
                    cout << "Con " << AGE << " anios, si ingreso en " << ingreso[2] 
                         << ", empezo a trabajar a los " << edadAlIngresar << " anios." << endl;
                    cout << "La edad minima legal para trabajar es de 18 anios.\n";
                }
                cout << "Por favor, digite una fecha de ingreso valida.\n\n";
            } else {
                datosLegales = true;
            }
        }
        cin.ignore();

        emp->setDatosBasicos(NAME, AGE, CARGO, ingreso);
        emp->setHoras(horas);
        emp->calcularSueldo();
        nomina[i] = emp;
    }

    // 3. Hallar empleado con mayor salario y el más veterano
    Empleado* maxSalarioEmp = nomina[0];
    Empleado* veteranoEmp = nomina[0];

    for (int i = 1; i < 10; i++) {
        if (nomina[i]->getSueldo() > maxSalarioEmp->getSueldo()) {
            maxSalarioEmp = nomina[i];
        }
        if (nomina[i]->getValorFecha() < veteranoEmp->getValorFecha()) {
            veteranoEmp = nomina[i];
        }
    }

    // 4. Ordenar por cargo (Gerente > Supervisor > Operario)
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (nomina[j]->getNivelCargo() < nomina[j + 1]->getNivelCargo()) {
                Empleado* temp = nomina[j];
                nomina[j] = nomina[j + 1];
                nomina[j + 1] = temp;
            }
        }
    }

    // 5. Mostrar Resultados Finales
    cout << "\n============================================\n";
    cout << "EMPLEADO CON MAYOR SALARIO:\n";
    maxSalarioEmp->mostrarEmpleado();
    
    cout << "\nEMPLEADO MAS VETERANO (Mayor tiempo):\n";
    veteranoEmp->mostrarEmpleado();

    cout << "\nLISTA DE EMPLEADOS ORDENADOS POR CARGO:\n";
    for (int i = 0; i < 10; i++) {
        nomina[i]->mostrarEmpleado();
    }
    cout << "============================================\n";

    // Liberar memoria
    for (int i = 0; i < 10; i++) {
        delete nomina[i];
    }

    return 0;
}