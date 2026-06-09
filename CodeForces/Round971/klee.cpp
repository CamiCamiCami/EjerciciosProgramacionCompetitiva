#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long sumatoria(long long k, long long n) {
    return (n-1)*k+((n-1)*n)/2;
}


ll buscar(ll inicio, ll fin, long long buscado) {
    long long idx1 = (inicio+fin)/2, idx2 = idx1+1;
    long long suma1 = sumatoria(inicio, idx1), suma2 = sumatoria(inicio, idx2);
    if(suma1 <= buscado && buscado <= suma2) {
        return suma2 - buscado < buscado - suma1 ? idx2 : idx1;
    } else if(suma2 < buscado) {
        return idx2 + buscar(idx2, fin, buscado-sumatoria(inicio, idx2));
    } else {
        return buscar(inicio, idx1, buscado);
    }
}



ll 


int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n, k;
        cin >> n >> k;
        cout << buscar(k, k+n-1, sumatoria(k, n)/2) - k + 1 << endl;
    }
}