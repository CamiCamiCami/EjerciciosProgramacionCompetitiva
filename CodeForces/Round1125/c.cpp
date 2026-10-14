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
#define endl '\n'
#define initArr(arr, largo, contenido)                                         \
    for (int i = 0; i < largo; i++) arr[i] = contenido;
using namespace std;
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Digrafo = vector<vector<pair<ll, bool>>>;
using Arbol = vector<vector<ll>>;

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    while (cin >> casos) {
        while (casos--) {
            ll teclas;
            cin >> teclas;
            vector<ll> satisfaccion(teclas), amores;
            set<ll> tiposAmor;
            map<ll, ll> apariciones;
            forr(i, teclas) { cin >> satisfaccion[i]; }
            forr(i, teclas - 4) {
                ll amor =
                    satisfaccion[i] + satisfaccion[i + 2] - satisfaccion[i + 4];
                amores.push_back(amor);
                if (tiposAmor.count(amor) == 0) {
                    tiposAmor.insert(amor);
                    apariciones[amor] = 1;

                } else {
                    apariciones[amor]++;
                }
            }

            ll formas = 0;
            for (ll amor : tiposAmor) {
                formas += (apariciones[amor] * (apariciones[amor] - 1)) / 2;
            }
            forr(i, teclas - 4) {
                if (i + 2 < teclas - 4 && amores[i] == amores[i + 2]) formas--;
                if (i + 4 < teclas - 4 && amores[i] == amores[i + 4]) formas--;
            }
            cout << formas << endl;
        }
    }
}