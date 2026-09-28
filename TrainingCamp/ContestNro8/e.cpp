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
    ll gusanos;
    cin >> gusanos;
    vector<ll> gusano;
    gusano.push_back(0);
    ll largos[1001];
    initArr(largos, 1001, 0) forr(i, gusanos) {
        ll largo;
        cin >> largo;
        gusano.push_back(largo);
        largos[largo]++;
    }
    bool sePuede = false;
    vector<ll> indices(3);
    forr(obj, 1001) {
        if (largos[obj] == 0)
            continue;
        largos[obj]--;
        forr(primero, 1001) {
            if (largos[primero] == 0)
                continue;
            largos[primero]--;
            if (largos[max(0LL, obj - primero)] != 0) {
                sePuede = true;
                bool estaObj = false, estaPrim = false, estaSec = false;
                forrr(i, 1, gusanos + 1) {
                    if (!estaObj && gusano[i] == obj) {
                        estaObj = true;
                        indices[0] = (i);
                        continue;
                    }
                    if (!estaPrim && gusano[i] == primero) {
                        estaPrim = true;
                        indices[1] = (i);
                        continue;
                    }
                    if (!estaSec && gusano[i] == (obj - primero)) {
                        estaSec = true;
                        indices[2] = (i);
                        continue;
                    }
                }
                break;
            }
            largos[primero]++;
        }
        largos[obj]++;
        if (sePuede)
            break;
    }
    if (!sePuede) {
        cout << -1 << endl;
    } else {
        for (ll i : indices) {
            cout << i << " ";
        }
        cout << endl;
    }
}