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
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

vector<ll> predecesores;
vector<ll> profundidades;

ll buscarRepresentante(ll i) {
    if (predecesores[i] == i)
        return i;
    return predecesores[i] = buscarRepresentante(predecesores[i]);
}

void unirConjuntos(ll e1, ll e2) {
    e1 = buscarRepresentante(e1);
    e2 = buscarRepresentante(e2);
    if (e1 == e2)
        return;
    if (profundidades[e1] < profundidades[e2]) {
        predecesores[e1] = e2;
    } else if (profundidades[e1] > profundidades[e2]) {
        predecesores[e2] = e1;
    } else {
        predecesores[e1] = e2;
        profundidades[e1]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll cantVertices, cantAristas;
    cin >> cantVertices >> cantAristas;
    vector<pair<ll, pair<ll, ll>>> aristas;
    map<pair<ll, ll>, ll> indice;
    vector<bool> necesaria(cantAristas);
    forr(i, cantAristas) {
        ll v1, v2, peso;
        cin >> v1 >> v2 >> peso;
        aristas.push_back({peso, {v1, v2}});
        indice[{v1, v2}] = i;
    }
    forr(i, cantVertices) {
        predecesores.push_back(i);
        profundidades.push_back(0);
    }
    sort(aristas.begin(), aristas.end());
    vector<vector<pair<ll, ll>>> porPeso;

    ll ultimoPeso = 0;
    for (auto [peso, arista] : aristas) {
        if (peso != ultimoPeso) {
            porPeso.push_back(vector<pair<ll, ll>>());
        }
        porPeso.back().push_back(arista);
    }

    for (auto mismoPeso : porPeso) {
        set<ll> componentes;
        for (auto [v1, v2] : mismoPeso) {
            v1 = buscarRepresentante(v1);
            v2 = buscarRepresentante(v2);
            componentes.insert(v1);
            componentes.insert(v2);
        }
        }
}