#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    stack<char> pilaLetras;
    string palabra="";
    string palabraINV="";
    cout<<"ingrese su palabra: ";
    cin>>palabra;
    cout<< "\033c"<<endl;
    for (char letra : palabra) {
        pilaLetras.push(letra);
    }
    while (!pilaLetras.empty()) {
        palabraINV += pilaLetras.top();
        pilaLetras.pop();
    }
    cout << "Palabra original: " << palabra <<endl;
    cout << "Palabra invertida: " << palabraINV <<endl;

    if (palabra==palabraINV)
    {
        cout<<"Es palindromo"<<endl;
    }
    else
    {
        cout<<"No es palindromo"<<endl;
    }
     
    

    return 0;
}
//Como puede apreciar maestro usamos la misma logica del anterior ya que 
//nos da la palabra invertida y si la palabra invertida es igual a la original
//es palindromo
