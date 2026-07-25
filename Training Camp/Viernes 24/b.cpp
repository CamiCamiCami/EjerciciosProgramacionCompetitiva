#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define forr(d, h) for (int i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll figuras;
    cin >> figuras;
    vector<ll> figs(figuras + 1);
    figs[0] = 0;
    forr(0, figuras) {
        cin >> figs[i + 1];
    }
    figs.push_back(0);

    ll actual = figs[1], puntos = 0;
    bool infinitos = false;
    for (ll i = 1; !infinitos && i < figuras + 1; i++) {
        ll actual = figs[i];
        ll externa = figs[i - 1];
        ll interna = figs[i + 1];
        if (actual == 1) {
            puntos += externa == 2 ? 3 : (externa == 3 ? 4 : 0);
            puntos += interna == 2 ? 3 : (interna == 3 ? 4 : 0);
            puntos -= interna == 2 && externa == 3 ? 1 : 0;
        } else {
            infinitos = infinitos || (actual == 2 && interna == 3);
            infinitos = infinitos || (actual == 3 && interna == 2);
        }
    }
    if (infinitos) {
        cout << "Infinite\n";
    } else {
        cout << "Finite\n";
        cout << puntos << endl;
    }
}