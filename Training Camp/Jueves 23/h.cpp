#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
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
using GrafoPesado = vector<vector<pair<ll, char>>>;
using Grafo = vector<vector<ll>>;

GrafoPesado digrafo;
vector<bool> visitados;

ll buscaDistancia(GrafoPesado& g, ll desde, ll hasta) {
    if (desde == hasta)
        return 0;
    visitados[desde] = true;

    vector<tuple<ll, ll, char>> distancias;
    ll menorDist = 10E9;
    for (auto [vecino, letra] : g[desde]) {
        if (visitados[vecino])
            continue;
        ll distVecino = buscaDistancia(g, vecino, hasta);
        menorDist = menorDist > distVecino ? distVecino : menorDist;
        distancias.push_back({distVecino, vecino, letra});
    }
    for (auto [dist, vecino, letra] : distancias) {
        if (dist == menorDist) {
            digrafo[desde].push_back({vecino, letra});
        }
    }
    return menorDist + 1;
}

void digrafear(GrafoPesado& g) {
    digrafo = GrafoPesado(g.size());
    visitados = vector<bool>(g.size(), false);
    buscaDistancia(g, 1, g.size() - 1);
}

vector<ll> menorCamino;

string menosLexografico(ll desde, ll hasta) {
    string s = "";
    menorCamino.push_back(desde);
    while (desde != hasta) {
        ll minimoVecino = 0;
        char minimoCaracter = 'z' + 1;
        for (auto [v, l] : digrafo[desde]) {
            if (minimoCaracter > l) {
                minimoVecino = v;
                minimoCaracter = l;
            }
        }
        s += minimoCaracter;
        desde = minimoVecino;
        menorCamino.push_back(desde);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll vertices, aristas;
    cin >> vertices >> aristas;
    GrafoPesado g(vertices + 1);
    forr(0, aristas) {
        ll v1, v2;
        char esp, c;
        cin >> v1 >> v2 >> c;
        g[v1].push_back({v2, c});
        g[v2].push_back({v1, c});
    }
    digrafear(g);
    string minimoLexografico = menosLexografico(1, vertices);
    cout << minimoLexografico.size() << '\n';
    for (ll n : menorCamino) {
        cout << n << ' ';
    }
    cout << '\n';
    cout << minimoLexografico << '\n';
}