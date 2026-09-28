#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define forr(d, h) for (int i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;

int main() {
    ll queries;
    cin >> queries;
    while (queries--) {
        int cant, f, s;
        vector<pair<int, int>> original;
        vector<pair<int, int>> ordenado;
        cin >> cant;
        for (int i = 0; i < cant; i++) {
            cin >> f >> s;
            original.push_back(make_pair(f, s));
            ordenado.push_back(make_pair(f, s));
        }
        sort(ordenado.begin(), ordenado.end());
        set<pair<int, int>> g1, g2;
        int grupo = 1, cantGrupos = 1;
        int final = ordenado[0].second;
        g1.insert(ordenado[0]);
        for (int i = 1; i < cant; i++) {
            if (ordenado[i].first <= final) {
                if (grupo == 1) {
                    g1.insert(ordenado[i]);
                } else {
                    g2.insert(ordenado[i]);
                }
                final = max(ordenado[i].second, final);

            } else {
                if (grupo == 1) {
                    g2.insert(ordenado[i]);
                    grupo = 2;
                } else {
                    grupo = 1;
                    g1.insert(ordenado[i]);
                }
                cantGrupos++;
                final = ordenado[i].second;
            }
        }
        if (cantGrupos == 1) {
            cout << "-1" << '\n';
        } else {
            for (int i = 0; i < cant; i++) {
                if (g1.count(original[i])) {
                    cout << "1";
                } else {
                    cout << "2";
                }
                if (i < cant - 1) {
                    cout << ' ';
                } else {
                    cout << '\n';
                }
            }
        }
    }
}