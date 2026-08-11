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
    ll casos, n, elem;
    cin >> casos;
    while (casos--) {
        vector<ll> values;
        cin >> n;
        forr(i, n) {
            cin >> elem;
            values.push_back(elem);
        }
        ll res = n;
        forr(i, n - 1) {
            if (values[i] > values[i + 1]) {
                res = 1;
            }
        }
        cout << res << endl;
    }
}