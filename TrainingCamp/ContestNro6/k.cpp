#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define forr(i, h) for (ll i = 0; i < h; i++)
#define forrr(i, d, h) for (ll i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

Grafo g;
vector<bool> visitado(1000000 + 5, false);

ll mayorVertice(ll i) {
    visitado[i] = true;
    ll mayor = i;
    for (ll vecino : g[i]) {
        if (visitado[vecino])
            continue;
        mayor = max(mayor, mayorVertice(vecino));
    }
    return mayor;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll vertices, aristas;
    cin >> vertices >> aristas;
    g = vector<vector<ll>>(vertices);
    forr(i, aristas) {
        ll n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;
        g[n1].push_back(n2);
        g[n2].push_back(n1);
    }
    ll debeLlegar = -1, uniones = 0;
    forr(i, vertices) {
        if (visitado[i])
            continue;
        if (i <= debeLlegar)
            uniones++;
        debeLlegar = max(mayorVertice(i), debeLlegar);
    }
    cout << uniones << endl;
}