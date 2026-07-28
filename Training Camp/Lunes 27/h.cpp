#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>
#define ll int
#define dd long double
#define forr(i, h) for (ll i = 0; i < h; i++)
#define forrr(i, d, h) for (ll i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, pair<int, int>>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

pair<int, int> operator+(pair<int, int>& a, pair<int, int>& b) {
    return {a.first + b.first, a.second + b.second};
}

bool operator==(pair<int, int>& a, pair<int, int>& b) {
    return a.first == b.first && a.second == b.second;
}

bool buscarBucle(GrafoPesado& g, ll desde) {
    vector<bool> alcanzados(g.size(), false);
    vector<pair<int, int>> alcanzadoEnCopia(g.size());

    queue<ll> q;
    q.push(desde);
    bool encontroBucle = false;
    while (!q.empty() && !encontroBucle) {
        ll actual = q.front();
        q.pop();

        for (auto [vecino, mov] : g[actual]) {
            if (alcanzados[vecino] && alcanzadoEnCopia[actual] + mov != alcanzadoEnCopia[vecino]) {
                encontroBucle = true;
                break;
            }
            if (!alcanzados[vecino]) {
                alcanzadoEnCopia[vecino] = alcanzadoEnCopia[actual] + mov;
                alcanzados[vecino] = true;
                q.push(vecino);
            }
        }
    }
    return encontroBucle;
}

ll matriz[1500][1500];
GrafoPesado g;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll altura, ancho;

    cin >> altura >> ancho;
    ll pasillos = 0;
    ll nodoInicio;

    forr(i, altura) {
        forr(j, ancho) {
            char c;
            cin >> c;
            if (c == 'S')
                nodoInicio = pasillos;
            if (c != '#') {
                ll nodo = matriz[i][j] = pasillos++;
                g.push_back(vector<pair<ll, pair<int, int>>>());
                if (i > 0 && matriz[i - 1][j] != -1) {
                    g[nodo].push_back({matriz[i - 1][j], {0, 0}});
                    g[matriz[i - 1][j]].push_back({nodo, {0, 0}});
                }
                if (j > 0 && matriz[i][j - 1] != -1) {
                    g[nodo].push_back({matriz[i][j - 1], {0, 0}});
                    g[matriz[i][j - 1]].push_back({nodo, {0, 0}});
                }
            } else {
                matriz[i][j] = -1;
            }
        }
    }

    forr(j, ancho) {
        if (matriz[0][j] != -1 && matriz[altura - 1][j] != -1) {
            ll arriba = matriz[0][j], abajo = matriz[altura - 1][j];
            g[arriba].push_back({abajo, {0, 1}});
            g[abajo].push_back({arriba, {0, -1}});
        }
        if (matriz[j][0] != -1 && matriz[j][ancho - 1] != -1) {
            ll izquierda = matriz[j][0], derecha = matriz[j][ancho - 1];
            g[izquierda].push_back({derecha, {-1, 0}});
            g[derecha].push_back({izquierda, {1, 0}});
        }
    }
    bool infinito = buscarBucle(g, nodoInicio);
    cout << (infinito ? "Yes" : "No") << endl;
}