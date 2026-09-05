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
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

int alto, ancho;
vector<bitset<200>> matriz(alto);

#define todosUnos(fila, mascara) ((((fila) ^ (mascara)) & (mascara)) == 0)

int esCompatible(int chequearDesde, bitset<200> cambios, ll pivote) {
    ll nuevoPivote = pivote;
    bool compatible = true;
    for (int i = chequearDesde; i >= 0; i--) {
        bitset<200> BitsFila = matriz[i];
        if (todosUnos(BitsFila, cambios))
            continue;
        BitsFila.flip();
        if (todosUnos(BitsFila, cambios))
            continue;
        if (pivote == -1) {
            pivote = i;
        } else {
            compatible = false;
            break;
        }
    }
    return (!compatible ? -1 : nuevoPivote);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> alto >> ancho;
    forr(i, alto) {
        bitset<200> bits;
        forr(j, ancho) {
            char c;
            cin >> c;
            if (c == '1') {
                bits = bits.set(0, true);
            }
            bits = bits >> 1;
        }
        matriz.push_back(bits);
    }

    stack<bitset<200>> historial;
    bitset<200> cambios;
    int fila = alto - 1;
    vector<int> pasadas(alto, 0);
    int pivote = -1;
    int seteaPivote = alto - 1;
    while (!historial.empty() && fila > 0) {
        fila--;
        pasadas[fila]++;
        if (seteaPivote == fila) {
            pivote = -1;
            seteaPivote = -1;
        }

        if (pasadas[fila] == 3) {
            if (pivote == -1) {
                pivote = fila;
                seteaPivote = fila;
            } else {
                fila += 2;
                if (!historial.empty()) {
                    cambios = historial.top();
                    historial.pop();
                }
            }
            continue;
        }

        if (pasadas[fila] == 1)
            matriz[fila] = matriz[fila].flip();
        for (int i = matriz[fila]._Find_first(); i < ancho; i = matriz[fila]._Find_next(i)) {
            cambios.set(i, true);
        }
        int compatible = esCompatible(fila - 1, cambios, pivote);
        if (compatible != -1) {
            if (pivote != compatible) {
                pivote = compatible;
                seteaPivote = fila;
            }
            historial.push(bitset<200>(cambios));
        } else {
            fila += 2;
            if (!historial.empty()) {
                cambios = historial.top();
                historial.pop();
            }
        }
    }
    cout << (fila == 0 ? "YES" : "NO") << endl;
}