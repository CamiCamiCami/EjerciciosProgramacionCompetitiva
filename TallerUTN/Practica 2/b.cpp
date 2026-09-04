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

ll total = 0;

bool f(ll x) {
    return x <= total / x;
}

ll solve(ll min_val, ll max_val) {
    ll L = min_val;
    ll R = max_val;
    ll ans = -1;
    while (L <= R) {

        ll mid = L + (R - L) / 2;

        if (f(mid)) {
            ans = mid;
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll casos;
    cin >> casos;
    while (casos--) {
        ll cajas;
        total = 0;
        cin >> cajas;
        forr(i, cajas) {
            ll n;
            cin >> n;
            total += n;
        }

        ll candidato = solve(1, total);
        bool esCuadrado = ((candidato * candidato) == total);
        cout << (esCuadrado ? "YES" : "NO") << endl;
    }
}