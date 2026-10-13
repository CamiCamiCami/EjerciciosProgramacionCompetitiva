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

vector<ll> componente;
vector<bool> visitado;
stack<ll> semiOrden;
#define CENTINELA -1
void visitarKosaraju(Digrafo &g, ll nodo) {
    if (visitado[nodo]) return;
    visitado[nodo] = true;
    for (auto [vecino, salida] : g[nodo]) {
        if (!salida) continue;
        visitarKosaraju(g, vecino);
    }
    semiOrden.push(nodo);
}

void asignarKosaraju(Digrafo &g, ll nodo, ll comp) {
    if (componente[nodo] != CENTINELA) return;
    componente[nodo] = comp;
    for (auto [vecino, salida] : g[nodo]) {
        if (salida) continue;
        asignarKosaraju(g, vecino, comp);
    }
}

// Determina componentes fuertemente conexas de un dígrafo (aristas [vecino,
// salida?])
ll algoritmoKosaraju(Digrafo &g) {
    componente = vector<ll>(g.size(), CENTINELA);
    visitado = vector<bool>(g.size(), false);
    forr(nodo, g.size()) { visitarKosaraju(g, nodo); }
    ll nroComponentes = 0;
    while (!semiOrden.empty()) {
        ll nodo = semiOrden.top();
        asignarKosaraju(g, nodo, nroComponentes);
        nroComponentes = max(nroComponentes, componente[nodo] + 1);
        semiOrden.pop();
    }
    return nroComponentes;
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll cruces, aristas;
    while (cin >> cruces) {
        vector<ll> costos(cruces);
        forr(i, cruces) { cin >> costos[i]; }
        cin >> aristas;
        Digrafo g(cruces);
        forr(i, aristas) {
            ll desde, hasta;
            cin >> desde >> hasta;
            desde--;
            hasta--;
            g[desde].push_back({hasta, true});
            g[hasta].push_back({desde, false});
        }
        ll componentes = algoritmoKosaraju(g);
        vector<ll> menorCosto(componentes, (ll)1e10), opciones(componentes);
        forr(i, cruces) {
            if (menorCosto[componente[i]] == costos[i]) {
                opciones[componente[i]]++;
            } else if (costos[i] < menorCosto[componente[i]]) {
                menorCosto[componente[i]] = costos[i];
                opciones[componente[i]] = 1;
            }
        }
        ll costoTotal = 0, formas = 1;
        forr(i, componentes) {
            costoTotal += menorCosto[i];
            formas = (formas * opciones[i]) % 1000000007;
        }
        cout << costoTotal << " " << formas << endl;
    }
}