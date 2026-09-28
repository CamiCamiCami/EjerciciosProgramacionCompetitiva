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
using GrafoPesado = vector<vector<pair<ll, bool>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

bool visitadosGlobal[1001];
vector<pair<ll, ll>> callesBorradas;
vector<pair<ll, ll>> callesCreadas;
map<pair<ll, ll>, bool> habilitado;

void eliminaBucles(Grafo& g, ll raiz) {
    vector<bool> visitados(g.size(), false);
    stack<pair<ll, ll>> p;
    p.push({raiz, -1});
    while (!p.empty()) {
        auto [actual, desde] = p.top();
        p.pop();
        visitadosGlobal[actual] = visitados[actual] = true;
        for (ll vecino : g[actual]) {
            if (!habilitado[{actual, vecino}] || vecino == desde)
                continue;
            if (vecino == raiz) {
                callesBorradas.push_back({raiz, actual});
                habilitado[{actual, vecino}] = false;
                habilitado[{vecino, actual}] = false;
            }
            if (visitados[vecino])
                continue;
            p.push({vecino, actual});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll vertices, aristas;
    cin >> vertices;
    aristas = vertices - 1;
    initArr(visitadosGlobal, vertices, false);
    Grafo g(vertices);
    forr(i, aristas) {
        ll n1, n2;
        cin >> n1 >> n2;
        n1--;
        n2--;
        habilitado[{n1, n2}] = true;
        habilitado[{n2, n1}] = true;
        g[n1].push_back(n2);
        g[n2].push_back(n1);
    }

    eliminaBucles(g, 0);
    forrr(i, 1, vertices) {
        if (!visitadosGlobal[i]) {
            callesCreadas.push_back({0, i});
        }
        eliminaBucles(g, i);
    }
    cout << callesBorradas.size() << endl;
    forr(i, callesBorradas.size()) {
        auto [b1, b2] = callesBorradas[i];
        auto [c1, c2] = callesCreadas[i];
        cout << b1 + 1 << ' ' << b2 + 1 << ' ' << c1 + 1 << ' ' << c2 + 1 << endl;
    }
}