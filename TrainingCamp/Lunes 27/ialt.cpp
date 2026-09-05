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
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

char gallina2letra(ll gallina) {
    if ('a' + gallina <= 'z') {
        return 'a' + gallina;
    }
    gallina -= ('z' - 'a' + 1);
    if ('A' + gallina <= 'Z') {
        return 'A' + gallina;
    }
    gallina -= ('Z' - 'A' + 1);
    return '0' + gallina;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        ll alto, ancho, gallinas, arroz = 0;
        cin >> alto >> ancho >> gallinas;
        vector<vector<char>> campo(alto);
        forr(i, alto) {
            forr(j, ancho) {
                char c;
                cin >> c;
                campo[i].push_back(c);
                if (c == 'R')
                    arroz++;
            }
        }

        bool reversa = true;
        ll arrocesPorGallina = arroz / gallinas;
        ll arrocesExtra = arroz % gallinas;
        ll gallinaActual = -1;
        ll arrocesFaltantes = 0;

        forr(fila, alto) {
            reversa = not reversa;
            for (ll col = (reversa ? ancho - 1 : 0); col < ancho && col >= 0; col = col + (reversa ? -1 : 1)) {
                if (arrocesFaltantes == 0) {
                    gallinaActual++;
                    if (gallinaActual == gallinas)
                        gallinaActual--;
                    arrocesFaltantes = arrocesPorGallina + (arrocesExtra <= 0 ? 0 : 1);
                    arrocesExtra--;
                }
                if (campo[fila][col] == 'R') {
                    arrocesFaltantes--;
                }
                campo[fila][col] = gallina2letra(gallinaActual);
            }
        }

        forr(fila, alto) {
            forr(col, ancho) {
                cout << campo[fila][col];
            }
            cout << endl;
        }
    }
}