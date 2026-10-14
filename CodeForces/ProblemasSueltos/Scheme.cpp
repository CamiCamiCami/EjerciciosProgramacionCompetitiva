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
#define endl '\n'
#define initArr(arr, largo, contenido)                                         \
    for (int i = 0; i < largo; i++) arr[i] = contenido;
using namespace std;
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Digrafo = vector<vector<pair<ll, bool>>>;
using Arbol = vector<vector<ll>>;

vector<bool> visitadosAux;
bool componenteCiclo = false;
ll analizaComponente(Digrafo &g, ll raiz, vector<ll> &fuentes,
                     vector<bool> &visitados) {
    queue<ll> q;
    q.push(raiz);
    while (!q.empty()) {
        ll actual = q.front();
        q.pop();
        if (visitados[actual]) continue;
        visitados[actual] = true;
        bool esFuente = true;
        for (auto [vecino, salida] : g[actual]) {
            if (!salida) esFuente = false;
            if (visitados[vecino]) continue;
            q.push(vecino);
        }
        if (esFuente) fuentes.push_back(actual);
    }
    if (fuentes.empty()) {
        fuentes.push_back(raiz);
        componenteCiclo = true;
    }

    q.push(raiz);
    while (!q.empty()) {
        ll actual = q.front();
        q.pop();
        if (visitadosAux[actual]) continue;
        visitadosAux[actual] = true;
        for (auto [vecino, salida] : g[actual]) {
            if (!salida) continue;
            if (visitadosAux[vecino]) return actual;
            q.push(vecino);
        }
    }
    return raiz;
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll miembros;
    while (cin >> miembros) {
        Digrafo g(miembros);
        forr(desde, miembros) {
            ll hacia;
            cin >> hacia;
            hacia--;
            g[desde].push_back({hacia, true});
            g[hacia].push_back({desde, false});
        }

        vector<pair<ll, vector<ll>>> nuevasAristas;
        visitadosAux = vector<bool>(miembros, false);
        vector<bool> visitados(miembros, false);
        vector<ll> finCiclo, siguientes;
        ll anterior = analizaComponente(g, 0, finCiclo, visitados);
        ll cantidadNuevas = 0, componentes = 1;
        forrr(i, 1, miembros) {
            if (visitados[i]) continue;
            componentes++;
            ll nuevo = analizaComponente(g, i, siguientes, visitados);
            cantidadNuevas += siguientes.size();
            nuevasAristas.push_back({anterior, siguientes});
            anterior = nuevo;
            siguientes.clear();
        }
        nuevasAristas.push_back({anterior, finCiclo});
        if (componentes == 1 && componenteCiclo) {
            cout << 0 << endl;
            continue;
        }

        cantidadNuevas += finCiclo.size();
        cout << cantidadNuevas << endl;
        for (auto [desde, destinos] : nuevasAristas) {
            for (ll hasta : destinos) {
                cout << desde + 1 << " " << hasta + 1 << endl;
            }
        }
    }
}