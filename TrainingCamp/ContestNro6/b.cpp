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
        ll minNaranjas = 10e10;
        ll minCaramelos = 10e10;
        ll regalos;
        cin >> regalos;
        vector<ll> naranjas, caramelos, movPosicion;
        forr(i, regalos) {
            ll n;
            cin >> n;
            minCaramelos = min(minCaramelos, n);
            caramelos.push_back(n);
        }
        forr(i, regalos) {
            ll n;
            cin >> n;
            minNaranjas = min(minNaranjas, n);
            naranjas.push_back(n);
        }
        ll necesita = 0;
        forr(i, regalos) {
            ll necesitaNaranja = naranjas[i] - minNaranjas;
            ll necesitaCaramelos = caramelos[i] - minCaramelos;
            necesita += max(necesitaCaramelos, necesitaNaranja);
        }
        cout << necesita << endl;
    }
}