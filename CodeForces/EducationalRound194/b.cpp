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

ll formula(ll x, ll y, ll k) {
    if (k == 0) {
        return 0;
    }
    if (y < x) {
        return y * k + ((k + 1) * k) / 2;
    }
    ll total = 0;
    while ((y / x) > 1 && k > 0) {
        total += y % x;
        x++;
        y++;
        k--;
    }
    if (k == 0) {
        return total;
    } else {
        return total + y * k - x * k;
    }
}

int main() {
#ifdef LOCAL
    freopen(FILE_DIR, "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    while (cin >> casos) {
        while (casos--) {
            ll x, y, k;
            cin >> x >> y >> k;
            cout << formula(x, y, k) << endl;
        }
    }
}