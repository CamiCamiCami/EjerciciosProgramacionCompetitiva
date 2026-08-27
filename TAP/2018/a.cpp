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
#define forr(i, h) for (int i = 0; i < h; i++)
#define forrr(i, d, h) for (int i = d; i < h; i++)
using namespace std;
using GrafoPesado = vector<vector<pair<ll, char>>>;

#define DIRCONTRARIA(d) (d == 'R' ? 'L' : (d == 'L' ? 'R' : (d == 'U' ? 'D' : 'U')))

string caminoMasCorto(GrafoPesado& g, ll desde, ll hasta) {
    vector<bool> visitados(g.size(), false);
    vector<pair<ll, char>> anteriores(g.size(), {-1, '#'});
    queue<tuple<ll, ll, pair<ll, ll>>> q;
    q.push({hasta, 0, {hasta, '#'}});
    while (!q.empty()) {
        auto [actual, disAct, llego] = q.front();
        q.pop();
        if (visitados[actual])
            continue;

        visitados[actual] = true;
        anteriores[actual] = llego;
        if (actual == desde) {
            q.push({actual, disAct, llego});
            break;
        }
        for (auto [vecino, mov] : g[actual]) {
            if (visitados[vecino])
                continue;
            q.push({vecino, disAct + 1, {actual, mov}});
        }
    }
    string camino = "";
    if (q.empty()) {
        return camino;
    }
    ll actual = desde;
    auto [anterior, mov] = anteriores[actual];
    while (actual != anterior) {
        camino += DIRCONTRARIA(mov);
        actual = anterior;
        anterior = anteriores[actual].first;
        mov = anteriores[actual].second;
    }

    return camino;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll filas, cols;
    cin >> filas >> cols;
    vector<vector<ll>> parado(filas + 4, vector<ll>(cols + 4, -1)), horizontal(filas + 4, vector<ll>(cols + 4, -1)),
            vertical(filas + 4, vector<ll>(cols + 4, -1));
    ll nodos = 0;
    ll llegada, partida;
    forrr(f, 2, filas + 2) {
        forrr(c, 2, cols + 2) {
            char cas;
            cin >> cas;
            if (cas != '#') {
                if (cas == 'E')
                    llegada = nodos;
                if (cas == 'C')
                    partida = nodos;
                parado[f][c] = nodos++;
                if (parado[f][c - 1] != -1)
                    horizontal[f][c] = nodos++;
                if (parado[f - 1][c] != -1)
                    vertical[f][c] = nodos++;
            }
        }
    }

    GrafoPesado g(nodos);
    forrr(f, 2, filas + 2) {
        forrr(c, 2, cols + 2) {
            if (horizontal[f][c] != -1 && horizontal[f - 1][c] != -1) {
                g[horizontal[f][c]].push_back({horizontal[f - 1][c], 'U'});
                g[horizontal[f - 1][c]].push_back({horizontal[f][c], 'D'});
            }
            if (vertical[f][c] != -1 && vertical[f][c - 1] != -1) {
                g[vertical[f][c]].push_back({vertical[f][c - 1], 'L'});
                g[vertical[f][c - 1]].push_back({vertical[f][c], 'R'});
            }
            if (parado[f][c] != -1) {
                if (horizontal[f][c - 1] != -1) {
                    g[parado[f][c]].push_back({horizontal[f][c - 1], 'L'});
                    g[horizontal[f][c - 1]].push_back({parado[f][c], 'R'});
                }
                if (horizontal[f][c + 2] != -1) {
                    g[parado[f][c]].push_back({horizontal[f][c + 2], 'R'});
                    g[horizontal[f][c + 2]].push_back({parado[f][c], 'L'});
                }
                if (vertical[f - 1][c] != -1) {
                    g[parado[f][c]].push_back({vertical[f - 1][c], 'U'});
                    g[vertical[f - 1][c]].push_back({parado[f][c], 'D'});
                }
                if (vertical[f + 2][c] != -1) {
                    g[parado[f][c]].push_back({vertical[f + 2][c], 'D'});
                    g[vertical[f + 2][c]].push_back({parado[f][c], 'U'});
                }
            }
        }
    }

    string camino = caminoMasCorto(g, partida, llegada);
    if (camino == "") {
        cout << -1 << endl;
    } else {
        cout << camino.size() << endl;
        for (char c : camino) {
            cout << c;
        }
        cout << endl;
    }
}