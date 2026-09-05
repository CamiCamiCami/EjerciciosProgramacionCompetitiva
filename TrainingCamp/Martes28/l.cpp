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
    ll casos;
    cin >> casos;
    while (casos--) {
        ll Nvertices, Naristas, k;
        cin >> Nvertices >> Naristas >> k;
        vector<tuple<ll, ll, ll>> aristas;
        forr(i, Naristas) {
            ll v1, v2, peso;
            cin >> v1 >> v2 >> peso;
            aristas.push_back({peso, v1 - 1, v2 - 1});
        }
        predecesores.clear();
        profundidades.clear();
        forr(i, Nvertices) {
            predecesores.push_back(i);
            profundidades.push_back(0);
        }
        sort(aristas.begin(), aristas.end());

        ll maximoPeso = 0;
        ll menorDistancia = 1E10;
        ll cambiosForzados = 0;
        for (auto [peso, v1, v2] : aristas) {
            menorDistancia = min(menorDistancia, (k - peso >= 0 ? k - peso : peso - k));
            if (buscarRepresentante(v1) == buscarRepresentante(v2))
                continue;

            maximoPeso = max(maximoPeso, peso);
            if (peso > k)
                cambiosForzados += peso - k;
            unirConjuntos(v1, v2);
        }
        if (maximoPeso <= k) {
            cout << menorDistancia << endl;
        } else {
            cout << cambiosForzados << endl;
        }
    }
}