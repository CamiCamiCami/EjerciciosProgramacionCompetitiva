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

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll alto, ancho;
    while (cin >> alto >> ancho) {
        bitset<200> primeraFila, significativos;
        forr(j, ancho) {
            ll bit;
            cin >> bit;
            primeraFila.set(ancho - j - 1, bit == 1);
            significativos.set(ancho - j - 1, true);
        }
        vector<bitset<200>> matriz;
        forr(i, alto - 1) {
            bitset<200> fila;
            forr(j, ancho) {
                ll bit;
                cin >> bit;
                fila.set(ancho - j - 1, bit == 1);
            }
        }
        bool compatibles = true;
        int pivote = -1, numFila = 0;
        vector<int> filasCambian(1, 0);
        for (bitset<200> fila : matriz) {
            numFila++;
            if (fila == primeraFila)
                filasCambian.push_back(0);
            else if ((fila.flip() & significativos) == primeraFila)
                filasCambian.push_back(1);
            if (pivote == -1)
                pivote = numFila;
            else
                compatibles = false;
        }

        if (!pivote)
    }
}