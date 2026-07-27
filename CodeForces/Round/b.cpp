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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        ll largo, pares;
        cin >> largo >> pares;
        ll n1 = (pares / 2) + 1, n0 = techo(pares, 2) + 1;
        if (n1 + n0 > largo) {
            cout << -1 << endl;
            continue;
        }
        forr(i, n1) {
            cout << 1;
        }
        forr(i, n0) {
            cout << 0;
        }
        bool uno = true;
        forrr(i, n1 + n0, largo) {
            if (uno) {
                cout << 1;
            } else {
                cout << 0;
            }
            uno = not uno;
        }
        cout << endl;
    }
}