#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int cantidad;
vector<long long> pesos;

int analizaCaso(unsigned long long caso) {
    long long suma = pesos[cantidad - 1];
    for(int i = 0; i < cantidad-1; i++) {
        if((caso >> i) & 1) {
            suma -= pesos[i];
        } else {
            suma += pesos[i];
        }
    }
    return abs(suma);
}


int main() {
    cin >> cantidad;
    unsigned long long peso;
    for (int i = 0; i < cantidad; i++) {
        cin >> peso;
        pesos.push_back(peso);
    }
    unsigned long long mínimo = accumulate(pesos.begin(), pesos.end(), 0);
    for(unsigned long long i = 0; i < (1 << cantidad); i++) {
        unsigned long long resultado = analizaCaso(i);
        if (resultado < mínimo)
            mínimo = resultado;
    }

    cout << mínimo << "\n";
}
