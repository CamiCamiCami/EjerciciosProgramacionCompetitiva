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
    ll casos, n, cant;

    cin >> casos;
    while (casos--) {
        ll suma = 0;
        cin >> n;
        vector<ll> values;
        while (n--) {
            cin >> cant;
            values.push_back(cant);
        }
        ll maximo = values[0];
        for (ll value : values) {
            maximo = max(maximo, value);
        }
        for (ll value : values) {
            if (maximo == value)
                suma += 1;
        }
        cout << suma << endl;
    }
}