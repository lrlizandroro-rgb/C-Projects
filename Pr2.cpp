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
    return 0;
}