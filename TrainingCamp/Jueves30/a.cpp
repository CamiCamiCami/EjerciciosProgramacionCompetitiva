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
    ll casos;
    cin >> casos;
    while (casos--) {
        ll pilas;
        cin >> pilas;
        bool sePuede = true;
        ll acc = 0;
        forr(i, pilas) {
            ll cajas;
            cin >> cajas;
            acc += cajas;
            sePuede = sePuede && acc >= i;
            acc -= i;
        }
        ll necesario = (pilas * (pilas - 1)) / 2;
        cout << (sePuede ? "YES" : "NO") << endl;
    }
}