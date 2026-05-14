#include <iostream>
#include <set>
using namespace std;

int main() {
    set<long long> numeros;
    long long cantidad, numero;
    cin >> cantidad;
    while(cantidad--) {
        cin >> numero;
        numeros.insert(numero);
    }
    cout << numeros.size() << '\n';
}