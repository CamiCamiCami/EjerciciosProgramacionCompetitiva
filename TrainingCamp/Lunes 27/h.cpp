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
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, pair<ll, ll>>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

Par operator+(Par& a, Par& b) {
    return {a.first + b.first, a.second + b.second};
}

bool operator==(Par& a, Par& b) {
    return a.first == b.first && a.second == b.second;
}

char matriz[1500][1500];
Par alcanzadoEnPantalla[1500][1500];
int alto, ancho;

bool buscarBucle(Par desde) {
    queue<Par> q;
    alcanzadoEnPantalla[desde.first][desde.second] = {0, 0};
    matriz[desde.first][desde.second] = 'V';
    q.push(desde);
    bool encontroBucle = false;
    while (!q.empty() && !encontroBucle) {
        auto actual = q.front();
        q.pop();

        for (auto mov : {pair{0, 1}, {1, 0}, {-1, 0}, {0, -1}}) {
            auto [nuevoY, nuevoX] = actual + mov;
            auto pantalla = alcanzadoEnPantalla[actual.first][actual.second];
            if (nuevoY < 0) {
                nuevoY = alto - 1;
                pantalla.first++;
            } else if (nuevoY == alto) {
                nuevoY = 0;
                pantalla.first--;
            }
            if (nuevoX < 0) {
                nuevoX = ancho - 1;
                pantalla.second--;
            } else if (nuevoX == ancho) {
                nuevoX = 0;
                pantalla.second++;
            }
            Par nuevo = {nuevoY, nuevoX};
            if (matriz[nuevoY][nuevoX] == '#')
                continue;
            if (matriz[nuevoY][nuevoX] != 'V') {
                matriz[nuevoY][nuevoX] = 'V';
                alcanzadoEnPantalla[nuevo.first][nuevo.second] = pantalla;
                q.push(nuevo);
            } else if (pantalla != alcanzadoEnPantalla[nuevo.first][nuevo.second]) {
                encontroBucle = true;
                break;
            }
        }
    }
    return encontroBucle;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Par inicio;

    cin >> alto >> ancho;
    ll pasillos = 0;
    ll nodoInicio;

    forr(i, alto) {
        forr(j, ancho) {
            cin >> matriz[i][j];
            if (matriz[i][j] == 'S') {
                inicio = {i, j};
            }
        }
    }

    bool infinito = buscarBucle(inicio);
    cout << (infinito ? "Yes" : "No") << endl;
}