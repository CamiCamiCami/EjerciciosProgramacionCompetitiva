#include <bits/stdc++.h>
#define ll long long
#define dd long double
#define ull unsigned long long
#define forr(i, h) for (ll i = 0; i < h; i++)
#define forrr(i, d, h) for (ll i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define endl '\n'
#define initArr(arr, largo, contenido)                                                                                                               \
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
            ll libros, visibles;
            cin >> libros;
            visibles = libros;
            set<ll> primeros, segundos;
            vector<ll> medio;
            forr(i, libros) {
                ll libro;
                cin >> libro;
                if (!primeros.count(libro)) primeros.insert(libro);
                else if (!segundos.count(libro)) segundos.insert(libro);
                else {
                    visibles--;
                    medio.push_back(libro);
                }
            }

            cout << visibles << endl;
            for (ll libro : primeros) {
                cout << libro << " ";
            }
            for (ll libro : medio) {
                cout << libro << " ";
            }
            stack<ll> orden;
            for (ll libro : segundos) {
                orden.push(libro);
            }
            while (!orden.empty()) {
                cout << orden.top() << " ";
                orden.pop();
            }
            cout << endl;
        }
    }
}