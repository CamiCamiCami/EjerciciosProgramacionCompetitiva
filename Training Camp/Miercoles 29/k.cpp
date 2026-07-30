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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll dias, durabilidad;
    cin >> dias >> durabilidad;
    vector<bool> necesita;
    ll diasFrios = 0;
    forr(i, dias) {
        ll temp;
        cin >> temp;
        necesita.push_back(temp < 0);
        if (temp < 0)
            diasFrios++;
    }
    if (diasFrios == 0) {
        cout << 0 << endl;
    } else if (diasFrios > durabilidad) {
        cout << -1 << endl;
    } else {
        durabilidad -= diasFrios;
        vector<ll> periodosCalidos;
        ll largoActual = 0;
        bool empezoFrio = false;
        for (bool frio : necesita) {
            if (frio) {
                empezoFrio = true;
                if (largoActual != 0) {
                    periodosCalidos.push_back(largoActual);
                    largoActual = 0;
                }
            } else if (empezoFrio) {
                largoActual++;
            }
        }
        ll final = -1;
        if (!necesita.back()) {
            final = largoActual;
        }
        sort(periodosCalidos.begin(), periodosCalidos.end());
        ll salteados = 0;
        for (ll periodo : periodosCalidos) {
            if (durabilidad < periodo)
                break;
            durabilidad -= periodo;
            salteados++;
        }
        if (final == -1 || durabilidad >= final) {
            cout << 1 + (periodosCalidos.size() - salteados) * 2 << endl;
        } else {
            cout << 2 + (periodosCalidos.size() - salteados) * 2 << endl;
        }
    }
}