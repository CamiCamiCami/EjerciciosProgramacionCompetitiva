#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using Grafo = vector<vector<pair<ll, ll>>>;

int main() {
    ll monedas;
    cin >> monedas;
    bool posible[100001];
    initArr(posible, 100001, false);
    while (monedas--) {
        ll valor;
        cin >> valor;
        for (ll i = 100000; i >= valor; i--) {
            ll ant = i - valor;
            if (ant > 0)
                posible[i] = posible[i] || posible[ant];
        }
        posible[valor] = true;
    }
    ll posibles = 0;
    for (ll i = 0; i < 100001; i++) {
        if (posible[i])
            posibles++;
    }
    cout << posibles << endl;
    for (ll i = 0; i < 100001; i++) {
        if (posible[i])
            cout << i << " ";
    }
    cout << endl;
}