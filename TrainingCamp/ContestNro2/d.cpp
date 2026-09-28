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
#define forr(d, h) for (int i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;

#define MOD 10e6 + 7
#define sum(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define res(a, b) (((a % MOD) - (b % MOD) + MOD) % MOD)
#define mul(a, b) (((a % MOD) * (b % MOD)) % MOD)

ll sigColor(ll colorNodo, ll colorActual, ll cantColores) {
    colorActual = (colorActual + 1) % cantColores;
    if (colorActual == colorNodo)
        colorActual = (colorActual + 1) % cantColores;
    return colorActual;
}

vector<ll> pintar(Grafo g, ll cantColores, ll nodos) {
    vector<ll> colores(nodos, -1);
    stack<ll> siguiente;
    siguiente.push(0);
    ll anterior = 0;
    colores[0] = 0;
    while (!siguiente.empty()) {
        ll actual = siguiente.top();
        siguiente.pop();
        ll color = 0;

        for (ll vecino : g[actual]) {
            if (colores[vecino] != -1)
                color = colores[vecino];
        }
        for (ll vecino : g[actual]) {
            if (colores[vecino] != -1)
                continue;
            color = sigColor(colores[actual], color, cantColores);
            colores[vecino] = color;
            siguiente.push(vecino);
        }
    }

    return colores;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    Grafo g(n);
    vector<ll> grados(n, 0);
    forr(1, n) {
        ll n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;
        g[n1].push_back(n2);
        grados[n1]++;
        g[n2].push_back(n1);
        grados[n2]++;
    }
    ll cantColores = 0;
    for (ll grado : grados) {
        cantColores = grado > cantColores ? grado : cantColores;
    }
    cantColores++;
    vector<ll> colores = pintar(g, cantColores, n);
    cout << cantColores << '\n';
    for (ll color : colores) {
        cout << color + 1 << ' ';
    }
    cout << '\n';
}
