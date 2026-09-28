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
    ll rectangulos;
    cin >> rectangulos;
    ll maximo = 10E9;
    bool sePuede = true;
    forr(i, rectangulos) {
        ll a, b;
        cin >> a >> b;
        ll Min = min(a, b), Max = max(a, b);
        if (Max <= maximo) {
            maximo = Max;
        } else if (Min <= maximo) {
            maximo = Min;
        } else {
            sePuede = false;
        }
    }
    cout << (sePuede ? "YES" : "NO") << endl;
}