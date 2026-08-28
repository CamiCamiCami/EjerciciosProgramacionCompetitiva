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

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll cantantes;
    while (cin >> cantantes) {
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> inicios, finales;
        vector<char> escuelas;
        vector<ll> id2inicios;
        forr(alumnos, cantantes) {
            char escuela;
            ll ini, fin;
            cin >> escuela >> ini >> fin;
            inicios.push({ini, alumnos});
            finales.push({fin, alumnos});
            escuelas.push_back(escuela);
            id2inicios.push_back(ini);
        }
        vector<bool> cerrado(cantantes, false);
        queue<pair<ll, ll>> daniAbiertos, javiAbiertos;
        ll maxRango = 0;
        while (!finales.empty()) {
            if (inicios.empty() || finales.top().first <= inicios.top().first) {
                auto [hasta, alumno] = finales.top();
                finales.pop();
                cerrado[alumno] = true;
                ll desde, primero;
                if (escuelas[alumno] == 'D') {
                    if (javiAbiertos.empty())
                        desde = hasta;
                    else {
                        tie(desde, primero) = javiAbiertos.front();
                        while (!daniAbiertos.empty() && cerrado[daniAbiertos.front().second])
                            daniAbiertos.pop();
                    }

                } else {  // == 'J'
                    if (daniAbiertos.empty())
                        desde = hasta;
                    else {
                        tie(desde, primero) = daniAbiertos.front();
                        while (!javiAbiertos.empty() && cerrado[javiAbiertos.front().second])
                            javiAbiertos.pop();
                    }
                }
                ll rangoCerrado = hasta - max(id2inicios[alumno], desde) - 1;
                maxRango = max(maxRango, rangoCerrado);
            } else {
                auto [desde, alumno] = inicios.top();
                inicios.pop();
                if (escuelas[alumno] == 'D') {
                    daniAbiertos.push({desde, alumno});
                } else {  // == 'J'
                    javiAbiertos.push({desde, alumno});
                }
            }
        }
        cout << maxRango << endl;
    }
}