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
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

#define color2idx(c) ((c) == 'R' ? 0 : ((c) == 'G' ? 1 : 2))
#define idx2Color(c) ((c) == 0 ? 'R' : ((c) == 1 ? 'G' : 'B'))

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll largo;
    cin >> largo;
    ll aparicionesMod[3][3];
    initArr(aparicionesMod[0], 3, 0);
    initArr(aparicionesMod[1], 3, 0);
    initArr(aparicionesMod[2], 3, 0);
    forr(i, largo) {
        char c;
        cin >> c;
        aparicionesMod[i % 3][color2idx(c)]++;
    }

    ll minimo = 10E9 + 10;
    vector<ll> orden;
    forr(i, 3) {
        forr(j, 3) {
            if (j == i)
                continue;
            forr(k, 3) {
                if (k == j || k == i)
                    continue;
                ll suma = 0;
                suma += aparicionesMod[0][j] + aparicionesMod[0][k];
                suma += aparicionesMod[1][i] + aparicionesMod[1][k];
                suma += aparicionesMod[2][i] + aparicionesMod[2][j];
                if (suma < minimo) {
                    minimo = suma;
                    orden = {i, j, k};
                }
            }
        }
    }
    cout << minimo << endl;
    forr(i, largo) {
        cout << idx2Color(orden[i % 3]);
    }
    cout << endl;
}