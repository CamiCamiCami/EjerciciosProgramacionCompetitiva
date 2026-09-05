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

Arbol ancestros;

void calcularAncestros(Arbol& g, ll raiz) {
    calcularAncestrosInmediatos(g, raiz);
    ll k = for (ll i = 1; i < g.size())
}

void calcularAncestrosInmediatos(Arbol& g, ll raiz) {
    vector<bool> visitados(g.size(), false);
    queue<ll> q;
    q.push(raiz);
    while (!q.empty()) {
        ll actual = q.front();
        q.pop();
        visitados[actual] = true;
        for (ll vecino : g[actual]) {
            if (visitados[vecino])
                continue;
            ancestros[vecino].push_back(actual);
            q.push(vecino);
        }
    }
    ancestros[raiz].push_back(-1);
}

void calcularKsimoAncestro(Arbol& g, ll raiz, ll k /*Ancestros 2^k, k > 0*/) {
    forr(nodo, g.size()) {
        ll mitadCamino = ancestros[nodo][k - 1];
        ll ancestro = ancestros[mitadCamino][k - 1];
        if (ancestro != -1) {
            ancestros[nodo].push_back(ancestro);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {}
}