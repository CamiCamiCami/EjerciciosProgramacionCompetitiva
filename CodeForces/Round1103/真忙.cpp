#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;

vector<ll> encontrarCamino(Grafo grafo, ll desde, ll hasta) {
    vector<ll> camino;
    camino.push_back(desde);
    stack<ll> busqueda;
    ll actual = desde;
    while (!busqueda.empty() && actual != hasta) {
        actual = busqueda.top();
        if (camino.back() == actual) {
            busqueda.pop();
            camino.pop_back();
            continue;
        }
        camino.push_back(actual);
        for (ll vecino : grafo[actual]) {
            busqueda.push(vecino);
        }
    }
    return camino;
}

int main() {
    ll casos;
    cin >> casos;
    while (casos--) {
        ll n, queries;
        cin >> n >> queries;
        Grafo g(n, vector<ll>(1));
        vector<ll> pesos;
        for (int i = 0; i < n; i++) {
            ll peso;
            cin >> peso;
            pesos.push_back(peso);
        }
        for (int i = 0; i < n - 1; i++) {
            ll n1, n2;
            cin >> n1 >> n2;
            g[n1].push_back(n2);
            g[n2].push_back(n1);
        }
        while (queries--) {
            ll desde, hasta;
            cin >> desde >> hasta;
            vector<ll> camino = encontrarCamino(g, desde, hasta);
            for (ll nodo : camino) {
                cout << nodo << " ";
            }
            cout << endl;
        }
    }
}