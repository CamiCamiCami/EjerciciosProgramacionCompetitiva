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
using Digrafo = vector<vector<tuple<ll, bool, ll, ll>>>;
using Arbol = vector<vector<ll>>;

vector<ll> ordenTopologico;
vector<bool> visitadoTarjan;
vector<ll> marcas;
ll ordenados;
bool visitarTarjan(Digrafo &g, ll nodo, ll marcaActual, ll pesoMinimo) {
    if (visitadoTarjan[nodo]) return true;
    if (marcas[nodo] == marcaActual) return false;
    marcas[nodo] = marcaActual;
    bool hayCiclo = false;
    for (auto [vecino, salida, peso, _] : g[nodo]) {
        if (!salida) continue;
        if (peso <= pesoMinimo) continue;
        if (hayCiclo) break;
        hayCiclo = !visitarTarjan(g, vecino, marcaActual, pesoMinimo);
    }
    visitadoTarjan[nodo] = true;
    ordenTopologico[nodo] = ordenados++;
    return !hayCiclo;
}

bool ordenamientoTarjan(Digrafo &g, ll pesoMinimo) {
    ordenTopologico = vector<ll>(g.size());
    visitadoTarjan = vector<bool>(g.size(), false);
    marcas = vector<ll>(g.size(), -1);
    ordenados = 0;
    bool esAciclico = true;
    for (ll nodo = 0; nodo < g.size() && esAciclico; nodo++) {
        if (visitadoTarjan[nodo]) continue;
        esAciclico = visitarTarjan(g, nodo, nodo, pesoMinimo);
    }
    return esAciclico;
}

bool func(Digrafo &g, ll peso) { return ordenamientoTarjan(g, peso); }

ll solve(Digrafo &g, vector<ll> &pesos) {
    ll L = 0;
    ll R = pesos.size() - 1;
    ll ans = -1;
    while (L <= R) {
        ll mid = L + (R - L) / 2;
        if (func(g, pesos[mid])) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    return pesos[ans];
}

Digrafo leerGrafo(ll vertices, ll aristas,
                  vector<tuple<ll, ll, ll, ll>> &pesosIDs) {
    Digrafo g(vertices);
    ll n1, n2, peso, arista = 1;
    forr(i, aristas) {
        cin >> n1 >> n2 >> peso;
        n1--;
        n2--;
        g[n1].push_back({n2, true, peso, arista});
        g[n2].push_back({n1, false, peso, arista});
        pesosIDs.push_back({peso, arista, n1, n2});
        arista++;
    }
    return g;
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll vertices, aristas;
    while (cin >> vertices >> aristas) {
        vector<tuple<ll, ll, ll, ll>> pesosIDs;
        Digrafo g = leerGrafo(vertices, aristas, pesosIDs);
        sort(pesosIDs.begin(), pesosIDs.end());
        vector<ll> pesos = {0};
        for (auto [peso, _, __, ___] : pesosIDs) {
            pesos.push_back(peso);
        }
        ll pesoMinimo = solve(g, pesos);
        ordenamientoTarjan(g, pesoMinimo);
        vector<ll> aristasInvertir;
        for (auto [peso, id, desde, hasta] : pesosIDs) {
            if (peso > pesoMinimo) break;
            if (ordenTopologico[desde] >= ordenTopologico[hasta]) continue;
            aristasInvertir.push_back(id);
        }
        cout << pesoMinimo << " " << aristasInvertir.size() << endl;
        for (ll id : aristasInvertir) {
            cout << id << " ";
        }
        cout << endl;
    }
}