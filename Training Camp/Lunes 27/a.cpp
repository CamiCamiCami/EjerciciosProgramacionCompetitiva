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

vector<Grafo> componentesConexas(Grafo& g) {
    vector<bool> visitados(g.size(), false);
    vector<Grafo> grafos;
    queue<ll> q;
    forr(nodo, g.size()) {
        if (visitados[nodo])
            continue;
        q.push(nodo);
        map<ll, ll> nuevosNombres;
        Grafo nuevo;
        ll vertices = 0;
        while (!q.empty()) {
            ll actual = q.front();
            q.pop();
            if (visitados[actual])
                continue;
            visitados[actual] = true;
            nuevosNombres[actual] = vertices;
            nuevo.push_back(vector<ll>());
            vertices++;
            for (ll vecino : g[actual]) {
                if (visitados[vecino]) {
                    ll nombreVecino = nuevosNombres[vecino], nombreActual = nuevosNombres[actual];
                    nuevo[nombreActual].push_back(nombreVecino);
                    nuevo[nombreVecino].push_back(nombreActual);
                }
                q.push(vecino);
            }
        }
        grafos.push_back(nuevo);
    }
    return grafos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll vertices, aristas;
    cin >> vertices >> aristas;
    Grafo g(vertices);
    forr(i, aristas) {
        ll v1, v2;
        cin >> v1 >> v2;
        v1--;
        v2--;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    vector<Grafo> componentes = componentesConexas(g);
    ll PELIGRO = 1;
    for (Grafo& conexo : componentes) {
        ll exponente = conexo.size() - 1;
        while (exponente-- != 0)
            PELIGRO *= 2;
    }
    cout << PELIGRO << endl;
}
