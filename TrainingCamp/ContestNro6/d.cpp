#include <algorithm>
#include <bitset>
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
#define initArr(arr, largo, contenido)                                         \
    for (int i = 0; i < largo; i++) arr[i] = contenido;
using namespace std;
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

bool enOrden(bitset<200> bits, ll columnas) {
    int idx = 0;
    while (bits[idx++] == 0 && idx < columnas);
    while (bits[idx++] == 1 && idx < columnas);
    return idx >= columnas;
}

void verBits(bitset<200> &bits, ll col) {
    forr(i, col) { cout << (bits[i] ? 1 : 0); }
    cout << endl;
}

void verMatriz(vector<bitset<200>> &bitss, ll col) {
    for (bitset<200> bits : bitss) {
        verBits(bits, col);
    }
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll filas, columnas;
    while (cin >> filas >> columnas) {
        vector<bitset<200>> matriz;
        vector<bool> invertidos;
        forr(i, filas) {
            int invierte = -1, casilla;
            bitset<200> nuevaFila;
            forr(j, columnas) {
                cin >> casilla;
                invierte = invierte == -1 ? casilla : invierte;
                casilla = invierte == 1 ? 1 - casilla : casilla;
                nuevaFila.set(j, casilla == 1);
            }
            invertidos.push_back(invierte == 1);
            matriz.push_back(nuevaFila);
        }

        bitset<200> igual = matriz[0];
        int distintas = 0;
        forrr(i, 1, filas) {
            if (igual != matriz[i]) {
                distintas++;
                if (distintas > 1) break;
            }
        }
        igual = distintas > 1 ? matriz[filas - 1] : matriz[0];

        bool puede = true;
        bool hayPivote = false;
        int pivote = -1;
        for (ll f = 0; f < filas && puede; f++) {
            if (matriz[f] == igual) continue;
            if (!hayPivote && enOrden(matriz[f] ^ igual, columnas)) {
                hayPivote = true;
                pivote = f;
            } else puede = false;
        }
        if (puede) {
            cout << "YES" << endl;
            forr(f, filas) {
                bool antes = f <= pivote;
                bool invirtio = invertidos[f];
                bool cambia = !(antes ^ invirtio);
                cout << (cambia ? 1 : 0);
            }
            cout << endl;
            forr(c, columnas) { cout << igual[c]; }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}