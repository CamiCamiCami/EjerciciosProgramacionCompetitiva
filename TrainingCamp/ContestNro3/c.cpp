#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
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

map<ll, pair<ll, ll>> grafo2matriz;
map<pair<ll, ll>, ll> matriz2grafo;
vector<vector<char>> matriz;

vector<bool> visitadas;
ll porBloquear;

void bloquearCasillas(Grafo& g, ll desde) {
    visitadas[desde] = true;

    for (ll vecino : g[desde]) {
        if (!porBloquear)
            break;
        if (visitadas[vecino])
            continue;
        bloquearCasillas(g, vecino);
    }
    if (porBloquear) {
        auto [i, j] = grafo2matriz[desde];
        matriz[i][j] = 'X';
        porBloquear--;
    }
}

Grafo creaGrafo(ll alto, ll ancho) {
    Grafo g;

    forr(i, alto) {
        forr(j, ancho) {
            if (matriz[i][j] == '#')
                continue;
            vector<ll> vecinos;
            if (i - 1 >= 0 && matriz[i - 1][j] == '.')
                vecinos.push_back(matriz2grafo[{i - 1, j}]);
            if (j - 1 >= 0 && matriz[i][j - 1] == '.')
                vecinos.push_back(matriz2grafo[{i, j - 1}]);
            if (i + 1 < alto && matriz[i + 1][j] == '.')
                vecinos.push_back(matriz2grafo[{i + 1, j}]);
            if (j + 1 < ancho && matriz[i][j + 1] == '.')
                vecinos.push_back(matriz2grafo[{i, j + 1}]);
            g.push_back(vecinos);
        }
    }

    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll alto, ancho;
    cin >> alto >> ancho >> porBloquear;
    matriz = vector<vector<char>>(alto);
    ll casillas = 0;
    forr(i, alto) {
        forr(j, ancho) {
            char casilla;
            cin >> casilla;
            matriz[i].push_back(casilla);
            if (casilla == '.') {
                grafo2matriz[casillas] = {i, j};
                matriz2grafo[{i, j}] = casillas;
                casillas++;
            }
        }
    }
    Grafo g = creaGrafo(alto, ancho);
    visitadas = vector<bool>(g.size(), false);
    bloquearCasillas(g, 0);
    forr(i, alto) {
        forr(j, ancho) {
            char c = matriz[i][j];
            cout << c;
        }
        cout << '\n';
    }
}