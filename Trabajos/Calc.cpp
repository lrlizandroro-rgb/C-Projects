#include <iostream>
using namespace std;
double sumar(const double &a, const double &b){
    return a+b;
}
double restar(const double &a, const double &b){
    return a-b;
}
double multiplicar(const double &a, const double &b){
    return a*b;
}
double dividir(const double &a, const double &b){
    return a/b;
}
void PedirData(const int &option){
        double x=0;
        double y=0;
        if (option!=4)
        {
            cout<<"Excelente..."<<endl;
            cout<<"Primer elemento: ";cin>>x;cout<<endl;
            cout<<"Segundo elemento: ";cin>>y;cout<<endl;
        }
        else
        {
            cout<<"Excelente..."<<endl;
            cout<<"Numerador: ";cin>>x;cout<<endl;
            cout<<"Denomiandor: ";cin>>y;cout<<endl;
            while (y==0)
            {
                cout<<"El denominador no puede ser 0"<<endl;
                cout<<">> ";cin>>y;
            }    
        }
        if (option==1)//Suma
        {
            cout<<"Resultado: "<<sumar(x,y)<<endl;
            return;
        }
        else if (option==2)//Resta
        {
            cout<<"Resultado: "<<restar(x,y)<<endl;
            return;
        }
        else if (option==3)//Multiplicacion
        {
            cout<<"Resultado: "<<multiplicar(x,y)<<endl;
            return;            
        }
        else//Division
        {
            cout<<"Resultado: "<<dividir(x,y)<<endl;
            return;
        }   
}
int main(){

    int opcion=0;
    do
    {
        cout<<"========================"<<endl;
        cout<<"     CALCULADORA        "<<endl;
        cout<<"========================"<<endl;
        cout<<"1.- Sumar"<<endl;
        cout<<"2.- Restar"<<endl;
        cout<<"3.- Multiplicar"<<endl;
        cout<<"4.- Dividir"<<endl;
        cout<<"5.- Salir"<<endl;
        cout<<">> ";cin>>opcion;
        cout<<"\033[2J\033[H"<<endl;
        if (opcion >= 1 && opcion <= 4) {
          PedirData(opcion);
        }
        else if (opcion==5) {
          break;
        }
        else {
          cout<<"Error-Entrada Invalida"<<endl;
          cout<<"REDIRIGIENDO AL MENU"<<endl;
        }
    } while (opcion!=5);
}
