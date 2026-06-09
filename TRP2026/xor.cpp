#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll entradas, buscado, acumulado = 0;
    cin >> entradas;
    
    while(entradas--) {
        ll num; cin >> num;
        acumulado = acumulado^num;
    }
    cin >> buscado;
    ll K = buscado^acumulado;
    cout << "SI" << endl;
    cout << K << endl;
}