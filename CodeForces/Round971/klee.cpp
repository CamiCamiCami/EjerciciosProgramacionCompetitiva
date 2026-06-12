#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define vector std::vector
#define map std::map
#define set std::set
using namespace std;
using Grafo = vector<vector<pair<ll, ll>>>;

// Desde inclusivo, Hasta no inclusivo
ll sumatoria(ll desde, ll hasta) {
    ll suma1 = (desde * (desde - 1)) / 2;
    ll suma2 = ((hasta - 1) * hasta) / 2;
    return suma2 - suma1;
}

ll largo;
ll K;
ll N;

ll calculaX(ll idx) {
    ll suma = sumatoria(K, idx + 1);
    ll resta = sumatoria(idx + 1, K + N);
    ll total = suma - resta;
    return total > 0 ? total : -total;
}

ll f(ll x) {
    ll sig = calculaX(x + 1);
    ll ant = calculaX(x - 1);
    ll in = calculaX(x);
    if (ant < in) {
        return 1;
    } else if (in > sig) {
        return -1;
    } else {
        return 0;
    }
}

ll busquedaBinaria(ll desde, ll hasta) {
    while (desde <= hasta) {
        ll medio = (desde + hasta) / 2;
        ll eval = f(medio);
        if (eval == 0) {
            return medio;
        }
        if (eval > 0) {
            hasta = medio - 1;
        } else {
            desde = medio + 1;
        }
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> N >> K;
        cout << calculaX(busquedaBinaria(K, K + N - 1)) << endl;
    }
}